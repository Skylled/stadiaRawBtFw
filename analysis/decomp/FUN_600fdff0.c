// 600fdff0  FUN_600fdff0  size=106 bytes
// --- callers ---
// --- callees ---
//   600ef476 FUN_600ef476
//   600f394c FUN_600f394c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60094d24 FUN_60094d24


void FUN_600fdff0(undefined2 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_1c [8];
  undefined1 uStack_14;
  char cStack_13;
  undefined4 uStack_10;
  char cStack_9;
  
  iVar1 = FUN_600ef476(param_1,param_2);
  if (iVar1 != 0) {
    cStack_9 = FUN_600f394c(*param_1,*(undefined2 *)(param_2 + 8));
    if ((cStack_9 != '\0') && (cStack_9 != -0x7a)) {
      thunk_EXT_FUN_0000b5ba(auStack_1c,0,0x10);
      cStack_13 = cStack_9;
      uStack_14 = 5;
      uStack_10 = 0;
      FUN_60094d24(param_1,0x1d10,auStack_1c);
    }
  }
  return;
}


