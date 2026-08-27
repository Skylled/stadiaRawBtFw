// 6005dabc  FUN_6005dabc  size=44 bytes
// --- callers ---
// --- callees ---
//   600517e8 FUN_600517e8
//   60101a80 FUN_60101a80
//   600cc450 FUN_600cc450


undefined1 FUN_6005dabc(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = FUN_60101a80(*(undefined4 *)(param_1 + 0x14));
  uVar2 = FUN_600517e8();
  uVar1 = FUN_600cc450(uVar1,DAT_6005dae8,uVar2);
  uVar1 = FUN_600cc450(uVar1,DAT_6005daf0,DAT_6005daec);
  iVar3 = FUN_600cc450(uVar1,DAT_6005daf8,DAT_6005daf4);
  return *(undefined1 *)(iVar3 + 0xd);
}


