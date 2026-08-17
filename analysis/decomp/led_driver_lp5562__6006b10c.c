// 6006b10c  led_driver_lp5562__6006b10c  size=176 bytes
// src: led_driver_lp5562.cc
// --- callers ---
//   600d8db2 FUN_600d8db2
//   600d8d5a FUN_600d8d5a
// --- callees ---
//   600d8c1a FUN_600d8c1a
//   600d37b8 FUN_600d37b8
//   60051120 FUN_60051120
//   600d37ac FUN_600d37ac
//   600d8c3e FUN_600d8c3e


/* src: led_driver_lp5562.cc */

undefined1
led_driver_lp5562__6006b10c
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 auStack_b4 [8];
  undefined1 auStack_ac [144];
  undefined1 local_1c;
  
  param_1 = param_1 + 8;
  FUN_600d8c3e();
  uVar1 = FUN_600d8c1a(param_1,4,param_2,200);
  if ((uVar1 & 0xff) == 0) {
    uVar1 = FUN_600d8c1a(param_1,3,param_3,200);
    if ((uVar1 & 0xff) == 0) {
      uVar1 = FUN_600d8c1a(param_1,2,param_4,200);
      if ((uVar1 & 0xff) == 0) {
        uVar1 = FUN_600d8c1a(param_1,0xe,param_5,200);
        if ((uVar1 & 0xff) == 0) {
          return 0;
        }
        FUN_60051120(auStack_b4,DAT_6006b1bc,0x78,uVar1);
        uVar2 = DAT_6006b1cc;
      }
      else {
        FUN_60051120(auStack_b4,DAT_6006b1bc,0x76,uVar1);
        uVar2 = DAT_6006b1c8;
      }
    }
    else {
      FUN_60051120(auStack_b4,DAT_6006b1bc,0x74,uVar1);
      uVar2 = DAT_6006b1c4;
    }
  }
  else {
    FUN_60051120(auStack_b4,DAT_6006b1bc,0x72,uVar1);
    uVar2 = DAT_6006b1c0;
  }
  FUN_600d37ac(auStack_ac,uVar2);
  FUN_600d37b8(auStack_b4);
  return local_1c;
}


