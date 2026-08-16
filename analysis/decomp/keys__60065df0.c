// 60065df0  keys__60065df0  size=106 bytes
// src: keys.cc
// --- callers ---
//   60065a74 ble_info__60065a74
//   600666f0 keys__600666f0
//   6005ded8 FUN_6005ded8
//   6005a6b0 device_info__6005a6b0
// --- callees ---
//   600d37b8 FUN_600d37b8
//   600d6e14 FUN_600d6e14
//   600d37ac FUN_600d37ac
//   601010c8 FUN_601010c8
//   60065d1c keys__60065d1c
//   60065ccc FUN_60065ccc
//   60065db0 FUN_60065db0
//   60051120 FUN_60051120


/* src: keys.cc */

uint keys__60065df0(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  byte local_14;
  
  iVar2 = FUN_60065ccc();
  if (iVar2 == DAT_60065e5c) {
    FUN_60051120(auStack_ac,DAT_60065e60,0x31b,3);
    FUN_600d37ac(auStack_a4,DAT_60065e64);
    uVar5 = (uint)local_14;
    FUN_600d37b8(auStack_ac);
  }
  else {
    iVar3 = FUN_600d6e14(param_1);
    if (iVar3 == 0) {
      if (*(char *)(iVar2 + 0x18) == '\0') {
        uVar5 = 5;
      }
      else {
        bVar1 = keys__60065d1c(iVar2 + 8,param_2);
        uVar5 = (uint)bVar1;
      }
    }
    else {
      uVar4 = FUN_60065db0(param_1);
      uVar5 = FUN_601010c8(uVar4,*(undefined4 *)(iVar2 + 8),param_2);
    }
  }
  return uVar5;
}


