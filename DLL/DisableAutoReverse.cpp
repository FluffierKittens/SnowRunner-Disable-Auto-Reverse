 #include "DisableAutoReverse.h"

using namespace std;

//Used to determine how long since we printed the last "blocked" message
ULONGLONG lastTickCount;

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved)
{
    if (DetourIsHelperProcess()) {
        return TRUE;
    }

	//Dll is being loaded
    if (dwReason == DLL_PROCESS_ATTACH) {
        Init();
    }
	//DLL is being unloaded
    else if (dwReason == DLL_PROCESS_DETACH) {
		//Detach our hook
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        
        DETOUR_DETACH(ShiftGear)

        DetourTransactionCommit();

#ifndef DAR_NO_CONSOLE
		//And dispose of our console if we had one
        FreeConsole();
#endif
    }
    return TRUE;
}

//Initialize the mod
void Init()
{
#ifndef DAR_NO_CONSOLE
	//Create a console, if desired, for viewing mod information while playing
    if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
        AllocConsole();
    }
	
	FILE *file = nullptr;
    freopen_s(&file, "CONOUT$", "w", stdout);
    freopen_s(&file, "CONOUT$", "w", stderr);
#endif

    CONSOLE_LOG("Disable Auto Reverse v0.1")

	//Set our hook
    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    DETOUR_ATTACH(ShiftGear)

    DetourTransactionCommit();
	
	//Set up the counter for rate limiting messages
	lastTickCount = GetTickCount64();
	
	//And announce that we're ready
    CONSOLE_LOG("Initialized")
}

//Our hook into the ShiftGear function
bool Hook_ShiftGear(Vehicle* veh, int32_t gear) 
{
    //We only care if the game is trying to shift into reverse
    if (gear == -1)
    {   //And we only care if we're in AUTO
        if (veh->TruckAction->AutoGearSwitch == 1)
        {
            //Trying to shift from -1 to -1 (Gear_1 holds the previous gear)
            if (veh->TruckAction->Gear_1 == -1) 
            {
				//When shifting R -> A after the truck has been moving backward, the game tries to put you in AUTO REVERSE
				//In this case we instead shift to AUTO 1/x
				//Power coefficient is 1.0 for both A and R; no need to update it
                CONSOLE_LOG("Blocking auto reverse while shifting R -> A.")
                return ShiftGear(veh, 1);
            }
            else //In all other cases, the game is trying to trick you into driving off a cliff
            {
				//Don't spam with messages
				ULONGLONG curTickCount = GetTickCount64();
				if (curTickCount - lastTickCount > MIN_MESSAGE_INTERVAL)
				{
					lastTickCount = curTickCount;
					CONSOLE_LOG("Blocking auto-reverse.")
				}
                return false;
            }
        }
        else //Not in auto
        {
			CONSOLE_LOG("Using R. No problem.")
            return ShiftGear(veh, gear);
        }
    }
    else //Not trying to shift into reverse
	{
		const char * onString = "ON";
		const char * offString = "OFF";
		CONSOLE_LOG("Shifting from %d to %d. Auto: %s.", veh->TruckAction->Gear_1, gear, veh->TruckAction->AutoGearSwitch ? onString : offString)
		return ShiftGear(veh, gear);
	}
}