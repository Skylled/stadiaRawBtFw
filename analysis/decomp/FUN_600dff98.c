// 600dff98  FUN_600dff98  size=40 bytes
// --- callers ---
//   600843c8 state_machine__600843c8
//   600841d0 state_machine__600841d0
//   600dffe8 FUN_600dffe8
//   60084644 state_machine__60084644
//   600842ac state_machine__600842ac
// --- callees ---
//   6013d358 thunk_EXT_FUN_0000ab36


undefined4 * FUN_600dff98(undefined4 *param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  if (*(char *)(param_3 + 4) == '\0') {
    *param_1 = 0;
    param_1[1] = 0;
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    puVar1 = (undefined4 *)thunk_EXT_FUN_0000ab36(param_3);
    (**(code **)(*param_2 + 8))(param_1,param_2,*puVar1,*(code **)(*param_2 + 8),param_4);
  }
  return param_1;
}


