// 600ee062  FUN_600ee062  size=86 bytes
// --- callers ---
// --- callees ---
//   600ca27c tasks__600ca27c
//   6013cff0 thunk_EXT_FUN_00008844
//   6013d0e0 thunk_EXT_FUN_0000728c
//   6013d2d0 thunk_EXT_FUN_0000713c
//   600ca5cc tasks__600ca5cc
//   600ee058 FUN_600ee058
//   6013d0e8 thunk_EXT_FUN_00006a74
//   600ee01c FUN_600ee01c


undefined4 FUN_600ee062(undefined4 *param_1)

{
  int iVar1;
  
  thunk_EXT_FUN_0000713c();
  param_1[8] = 1;
  if (param_1[7] == 0) {
    tasks__600ca5cc(*param_1);
    while (iVar1 = param_1[10], iVar1 != 0) {
      param_1[10] = *(undefined4 *)(iVar1 + 0xc);
      FUN_600ee058(iVar1,1);
    }
    FUN_600ee01c(param_1);
    if (*(char *)(param_1 + 4) == '\0') {
      param_1[9] = 0xffffffff;
      thunk_EXT_FUN_00006a74(param_1[2],0,0);
    }
    else {
      tasks__600ca27c(*param_1);
      thunk_EXT_FUN_00008844(param_1);
    }
  }
  thunk_EXT_FUN_0000728c();
  return 0;
}


