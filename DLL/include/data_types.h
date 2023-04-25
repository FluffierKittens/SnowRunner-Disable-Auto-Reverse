#pragma once

//This entire header was taken (with permission) from Ferrster's Snowrunner Manual Gearbox Mod
//https://github.com/Ferrster/Snowrunner-Manual-Gearbox-Mod

//All credit for this hard work goes to him

/*
The MIT License (MIT)

Copyright (c) 2015 Lopanov Vladislav Alekseevich

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

class combine_combineTruckAction {
public:
  char pad_0000[48];          // 0x0000
  class Vehicle *Veh;         // 0x0030
  float PowerCoef;            // 0x0038
  bool AutoGearSwitch;        // 0x003C
  char pad_003D[3];           // 0x003D
  float WheelTurn;            // 0x0040
  float Accel;                // 0x0044
  bool Handbrake;             // 0x0048
  bool AWD;                   // 0x0049
  bool Diff;                  // 0x004A
  char pad_004B[21];          // 0x004B
  class Unknown_1 *N0000005B; // 0x0060
  char pad_0068[8];           // 0x 0068
  std::int32_t Gear_1;        // 0x0070
  std::int32_t Gear_2;        // 0x0074
  char pad_0078[56];          // 0x0078
  float N00000065;            // 0x00B0
  float N00000319;            // 0x00B4
  float N00000066;            // 0x00B8
  float N00000325;            // 0x00BC
  char pad_00C0[24];          // 0x00C0
  float N0000006A;            // 0x00D8
  float SwitchThreshold;      // 0x00DC
  std::int32_t NextGear;      // 0x00E0
  char pad_00E4[860];         // 0x00E4
};                            // Size: 0x0440

class Vehicle {
public:
  char pad_0000[88];                                // 0x0000
  class combine_TRUCK_ADDON_MODEL *TruckAddonModel; // 0x0058
  class combine_combineTruckAction *TruckAction;    // 0x0060
  class combine_combineTruckPostSimulationListener
      *TruckPostSimulationListener; // 0x0068
  char pad_0070[976];               // 0x0070

  void SetPowerCoef(float coef);

  std::int32_t GetMaxGear() const;

  /**
   * @brief Switches to @p targetGear gear, if possible.
   *
   * @param targetGear gear to switch to
   * @param powerCoef power coef to set after switching. Low gears have
   * different coefs.
   * @return true - if gear was switched, false otherwise
   */
  bool ShiftToGear(std::int32_t targetGear, float powerCoef = 1.f);

  /**
   * @brief Switches to next gear, if possible.
   *
   * @param veh vehicle to switch the gear on
   * @return true - if gear was switched, false otherwise
   */
  bool ShiftToNextGear();

  /**
   * @brief Switches to previous gear, if possible.
   *
   * @param veh vehicle to switch the gear on
   * @return true - if gear was switched, false otherwise
   */
  bool ShiftToPrevGear();

  bool ShiftToHighGear();

  bool ShiftToReverseGear();

  bool ShiftToLowGear();

  bool ShiftToLowPlusGear();

  bool ShiftToLowMinusGear();
}; // Size: 0x0440

class combine_TRUCK_ADDON_MODEL {
public:
  char pad_0000[88];             // 0x0000
  class combine_SCENE *Scene;    // 0x0058
  class combine_XMESH *XMesh;    // 0x0060
  char pad_0068[144];            // 0x0068
  class N0000059F *N00000462;    // 0x00F8
  char pad_0100[16];             // 0x0100
  class N00000579 *N00000465;    // 0x0110
  char pad_0118[200];            // 0x0118
  class hkpRigidBody *N0000047F; // 0x01E0
  char pad_01E8[544];            // 0x01E8
};                               // Size: 0x0408

class combine_XMESH {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class combine_SCENE {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class N00000579 {
public:
  class combine_TRUCK_WHEEL_MODEL *TruckWheelModel1; // 0x0000
  class N00000696 *N000005CA;                        // 0x0008
  void *N000005CB;                                   // 0x0010
  class N000006BB *N000005CC;                        // 0x0018
  char pad_0020[1000];                               // 0x0020
};                                                   // Size: 0x0408

class N0000059F {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class combine_combineTruckPostSimulationListener {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class combine_TRUCK_WHEEL_MODEL {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class N00000696 {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class N000006BB {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class N000006C6 {
public:
  class combine_combineDriveCameraAction *N000006C7; // 0x0000
  class combine_combineSubstanceWheel *N000006C8;    // 0x0008
  class combine_combineSubstanceWheel *N000006C9;    // 0x0010
  class combine_combineSubstanceWheel *N000006CA;    // 0x0018
  class combine_combineSubstanceWheel *N000006CB;    // 0x0020
  class combine_combineSubstanceWheel *N000006CC;    // 0x0028
  class combine_combineSubstanceWheel *N000006CD;    // 0x0030
  class combine_combineSubstanceWheel *N000006CE;    // 0x0038
  class combine_combineSubstanceWheel *N000006CF;    // 0x0040
  char pad_0048[1016];                               // 0x0048
};                                                   // Size: 0x0440

class combine_combineDriveCameraAction {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class combine_combineSubstanceWheel {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class TruckControl {
public:
  char pad_0000[8];                      // 0x0000
  class Vehicle *CurVehicle;             // 0x0008
  char pad_0010[96];                     // 0x0010
  class combine_SOUND_OBJECT *N0000094C; // 0x0070
  class combine_SOUND_OBJECT *N0000094D; // 0x0078
  class combine_SOUND_OBJECT *N0000094E; // 0x0080
  char pad_0088[8];                      // 0x0088
  class String *N00000950;               // 0x0090
  char pad_0098[65];                     // 0x0098
  ///
  bool bFastMode;			// 0x00D9	
  char pad_00DA[870];			// 0x00DA
};                                       // Size: 0x0440

class combine_SOUND_OBJECT {
public:
  char pad_0000[8]; // 0x0000
};                  // Size: 0x0008

class Unknown_1 {
public:
  char pad_0000[1032]; // 0x0000
};                     // Size: 0x0408

class hkpRigidBody {
public:
  char pad_0000[1032]; // 0x0000
};                     // Size: 0x0408
