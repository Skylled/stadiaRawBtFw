// 60094754  FUN_60094754  size=104 bytes
// --- callers ---
//   600ee57a FUN_600ee57a
//   600947c0 FUN_600947c0
//   600ee678 FUN_600ee678
//   60094c5c FUN_60094c5c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600aa648 FUN_600aa648
//   6006dcdc FUN_6006dcdc
//   6006dfa4 FUN_6006dfa4
//   6006dd90 FUN_6006dd90


int FUN_60094754(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_6006dcdc(3,DAT_600947bc,0x7d);
  if (iVar2 == 0) {
    FUN_600aa648(param_1 + 0x28);
    *(undefined2 *)(param_1 + 0x24) = 0;
  }
  else {
    uVar3 = FUN_6006dd90(iVar2);
    thunk_EXT_FUN_0000b5ba(iVar2,0,uVar3);
    *(int *)(param_1 + 0x20) = iVar2;
    uVar1 = FUN_6006dd90(iVar2);
    *(undefined2 *)(param_1 + 0x24) = uVar1;
    FUN_6006dfa4(param_1 + 0x14,iVar2);
  }
  return iVar2;
}


