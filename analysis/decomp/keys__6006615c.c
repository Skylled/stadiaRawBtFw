// 6006615c  keys__6006615c  size=140 bytes
// src: keys.cc
// --- callers ---
//   60065b84 ble_info__60065b84
//   60066b40 keys__60066b40
//   6005a6b0 device_info__6005a6b0
//   6004cbf0 device_info__6004cbf0
// --- callees ---
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   60101198 FUN_60101198
//   60065ccc FUN_60065ccc
//   60065db0 FUN_60065db0
//   60051120 FUN_60051120


/* src: keys.cc */

uint keys__6006615c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_b4 [8];
  undefined1 auStack_ac [144];
  byte local_1c;
  
  iVar1 = FUN_60065ccc();
  if (iVar1 == DAT_600661e8) {
    FUN_60051120(auStack_b4,DAT_600661ec,0x310,3);
    uVar2 = DAT_600661f0;
  }
  else if (*(char *)(iVar1 + 0xc) == '\0') {
    if (*(char *)(iVar1 + 0xe) != '\x01') {
      uVar2 = FUN_60065db0(param_1);
      uVar3 = FUN_60101198(uVar2,*(undefined4 *)(iVar1 + 8),param_2,param_3);
      return uVar3;
    }
    FUN_60051120(auStack_b4,DAT_600661ec,0x315,7);
    uVar2 = DAT_600661f8;
  }
  else {
    FUN_60051120(auStack_b4,DAT_600661ec,0x311,3);
    FUN_600d37ac(auStack_ac,*(undefined4 *)(iVar1 + 8));
    uVar2 = DAT_600661f4;
  }
  FUN_600d37ac(auStack_ac,uVar2);
  FUN_600d37b8(auStack_b4);
  return (uint)local_1c;
}


