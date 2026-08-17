// 600ad494  FUN_600ad494  size=92 bytes
// --- callers ---
//   600f4e88 FUN_600f4e88
//   600f578e FUN_600f578e
//   600f55a4 FUN_600f55a4
// --- callees ---
//   6006dfa4 FUN_6006dfa4
//   6006dd90 FUN_6006dd90
//   6006dcdc FUN_6006dcdc
//   6013cf90 thunk_EXT_FUN_0000b5ba


bool FUN_600ad494(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6006dcdc(3,DAT_600ad4f0,0x42f);
  if (iVar1 != 0) {
    uVar2 = FUN_6006dd90(iVar1);
    thunk_EXT_FUN_0000b5ba(iVar1,0,uVar2);
    *(int *)(param_1 + 4) = iVar1;
    uVar2 = FUN_6006dd90(iVar1);
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    FUN_6006dfa4(param_1 + 8,iVar1);
  }
  return iVar1 != 0;
}


