// 6006b02c  led_driver_lp5562__6006b02c  size=202 bytes
// src: led_driver_lp5562.cc
// --- callers ---
//   60051240 main__60051240
// --- callees ---
//   600d8c1a FUN_600d8c1a
//   600d37b8 FUN_600d37b8
//   600cedd8 FUN_600cedd8
//   60051120 FUN_60051120
//   600d37ac FUN_600d37ac
//   6013cef8 thunk_EXT_FUN_0000737c


/* src: led_driver_lp5562.cc */

undefined1 led_driver_lp5562__6006b02c(int *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  undefined1 local_14;
  
  iVar4 = *param_1;
  if (iVar4 != 0) {
    FUN_600cedd8(*(undefined4 *)(iVar4 + 0x20),*(undefined4 *)(iVar4 + 0x18),1);
  }
  piVar5 = param_1 + 2;
  thunk_EXT_FUN_0000737c(2);
  cVar1 = FUN_600d8c1a(piVar5,0xd,0xff,200);
  if (cVar1 == '\0') {
    thunk_EXT_FUN_0000737c(2);
    if ((char)param_1[1] == '\0') {
      uVar3 = 0x40;
    }
    else {
      uVar3 = 0xc0;
    }
    cVar1 = FUN_600d8c1a(piVar5,0,uVar3,200);
    if (cVar1 == '\0') {
      thunk_EXT_FUN_0000737c(2);
      uVar2 = FUN_600d8c1a(piVar5,8,1,200);
      if ((uVar2 & 0xff) == 0) {
        uVar2 = FUN_600d8c1a(piVar5,0x70,0,200);
        if ((uVar2 & 0xff) == 0) {
          return 0;
        }
        FUN_60051120(auStack_ac,DAT_6006b0f8,0x61,uVar2);
        uVar3 = DAT_6006b108;
      }
      else {
        FUN_60051120(auStack_ac,DAT_6006b0f8,0x5b,uVar2);
        uVar3 = DAT_6006b104;
      }
    }
    else {
      FUN_60051120(auStack_ac,DAT_6006b0f8,0x53);
      uVar3 = DAT_6006b100;
    }
  }
  else {
    FUN_60051120(auStack_ac,DAT_6006b0f8,0x4d);
    uVar3 = DAT_6006b0fc;
  }
  FUN_600d37ac(auStack_a4,uVar3);
  FUN_600d37b8(auStack_ac);
  return local_14;
}


