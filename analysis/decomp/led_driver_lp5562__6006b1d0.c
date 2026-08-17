// 6006b1d0  led_driver_lp5562__6006b1d0  size=170 bytes
// src: led_driver_lp5562.cc
// --- callers ---
//   600d4596 led_calibration__600d4596
// --- callees ---
//   600d8c1a FUN_600d8c1a
//   600d37b8 FUN_600d37b8
//   60051120 FUN_60051120
//   600d37ac FUN_600d37ac


/* src: led_driver_lp5562.cc */

undefined1
led_driver_lp5562__6006b1d0
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  undefined1 local_14;
  
  param_1 = param_1 + 8;
  uVar1 = FUN_600d8c1a(param_1,7,param_2,200);
  if ((uVar1 & 0xff) == 0) {
    uVar1 = FUN_600d8c1a(param_1,6,param_3,200);
    if ((uVar1 & 0xff) == 0) {
      uVar1 = FUN_600d8c1a(param_1,5,param_4,200);
      if ((uVar1 & 0xff) == 0) {
        uVar1 = FUN_600d8c1a(param_1,0xf,param_5,200);
        if ((uVar1 & 0xff) == 0) {
          return 0;
        }
        FUN_60051120(auStack_ac,DAT_6006b27c,0x94,uVar1);
        uVar2 = DAT_6006b28c;
      }
      else {
        FUN_60051120(auStack_ac,DAT_6006b27c,0x92,uVar1);
        uVar2 = DAT_6006b288;
      }
    }
    else {
      FUN_60051120(auStack_ac,DAT_6006b27c,0x90,uVar1);
      uVar2 = DAT_6006b284;
    }
  }
  else {
    FUN_60051120(auStack_ac,DAT_6006b27c,0x8e,uVar1);
    uVar2 = DAT_6006b280;
  }
  FUN_600d37ac(auStack_a4,uVar2);
  FUN_600d37b8(auStack_ac);
  return local_14;
}


