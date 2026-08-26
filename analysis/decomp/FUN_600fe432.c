// 600fe432  FUN_600fe432  size=100 bytes
// --- callers ---
// --- callees ---
//   600ef476 FUN_600ef476
//   600f3ade FUN_600f3ade
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60094d24 FUN_60094d24


void FUN_600fe432(undefined2 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_1c [8];
  undefined1 local_14;
  char local_13;
  undefined4 local_10;
  char local_9;
  
  iVar1 = FUN_600ef476(param_1,param_2);
  if (iVar1 != 0) {
    local_9 = FUN_600f3ade(*param_1,*(undefined1 *)(param_2 + 8));
    if (local_9 != '\0') {
      thunk_EXT_FUN_0000b5ba(auStack_1c,0,0x10);
      local_13 = local_9;
      local_14 = 4;
      local_10 = 0;
      FUN_60094d24(param_1,0x1d10,auStack_1c);
    }
  }
  return;
}


