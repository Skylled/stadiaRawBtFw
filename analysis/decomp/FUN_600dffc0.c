// 600dffc0  FUN_600dffc0  size=40 bytes
// --- callers ---
//   600e002e FUN_600e002e
// --- callees ---
//   6013d358 thunk_EXT_FUN_0000ab36


undefined4 * FUN_600dffc0(undefined4 *param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  if (*(char *)(param_3 + 4) == '\0') {
    *param_1 = 0;
    param_1[1] = 0;
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    puVar1 = (undefined4 *)thunk_EXT_FUN_0000ab36(param_3);
    (**(code **)(*param_2 + 0xc))(param_1,param_2,*puVar1,*(code **)(*param_2 + 0xc),param_4);
  }
  return param_1;
}


