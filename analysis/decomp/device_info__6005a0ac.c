// 6005a0ac  device_info__6005a0ac  size=126 bytes
// src: device_info.cc
// --- callers ---
//   6005a4cc device_info__6005a4cc
//   6005a13c device_info__6005a13c
// --- callees ---
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   6004cb28 FUN_6004cb28
//   60051120 FUN_60051120
//   600d3ac4 FUN_600d3ac4
//   6013d1b0 thunk_EXT_FUN_00006668


/* src: device_info.cc */

undefined1 device_info__6005a0ac(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  undefined1 local_14;
  
  iVar1 = FUN_6004cb28(param_2);
  iVar2 = thunk_EXT_FUN_00006668(param_1,param_2,iVar1);
  if (iVar2 < 0) {
    FUN_60051120(auStack_ac,DAT_6005a12c,0x97,0xf);
    FUN_600d37ac(auStack_a4,DAT_6005a130);
  }
  else {
    if (iVar1 == iVar2) {
      return 0;
    }
    FUN_60051120(auStack_ac,DAT_6005a12c,0x9a,0xf);
    FUN_600d37ac(auStack_a4,DAT_6005a134);
    FUN_600d3ac4(auStack_a4,iVar2);
    FUN_600d37ac(auStack_a4,DAT_6005a138);
    FUN_600d3ac4(auStack_a4,iVar1);
  }
  FUN_600d37b8(auStack_ac);
  return local_14;
}


