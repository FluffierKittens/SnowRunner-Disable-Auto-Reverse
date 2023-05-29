# ⛔️ DEPRECATED ⛔️

This mod is no longer being updated/maintained. All features (and more) are available in [SnowRunner-UI-Changes](https://github.com/FluffierKittens/SnowRunner-UI-Changes).

The code in this repository is only compatible with SnowRunner.exe version 1.188853.SNOW_DLC9

# Disable AUTO REVERSE for SnowRunner
A mod to do nothing more than disable AUTO REVERSE. The only way to reverse is now with the dedicated R gear.

## Installation
1. Download the latest release from [here](https://github.com/FluffierKittens/SnowRunner-Disable-Auto-Reverse/releases/).
2. Extract *DisableAutoReverse.dll* and *DARInjector.exe* files from the archive. 
3. Place *DisableAutoReverse.dll* in the game folder where SnowRunner.exe is located. 
4. Place *DARInjector.exe* anywhere that you find convenient. The game folder is just fine.

## Usage
1. Start SnowRunner
2. Run *DARInjector.exe* and make sure you get a message indicating success. 
3. Start a new game or open an existing save, and have fun!

## Building
 
**With only the code provided, this project will not build.**
 
This project requires the Microsoft Detours library. You will need to place *detours.lib* (x64 version) in the *DLL\lib* folder and *detours.h* in the *DLL\include* folder. 
 
For help obtaining these libraries, see the [Detours FAQ](https://github.com/microsoft/Detours/wiki/FAQ).

In the future I'll improve the build process so that Detours is automatically installed if needed, but for the moment my priority is getting this mod released. 

Further info on building is on its way, and I appreciate your patience.
