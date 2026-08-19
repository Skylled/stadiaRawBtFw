// 600de0de  FUN_600de0de  size=134 bytes
// --- callers ---
//   6007c7f4 FUN_6007c7f4
// --- callees ---
//   6013d120 thunk_EXT_FUN_0000a94e
//   6013d238 thunk_EXT_FUN_0000b588


void FUN_600de0de(int *param_1,int param_2,int param_3,undefined4 *param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_798 [480];
  
  if (*param_1 == 8000) {
    if (param_2 != param_2 + param_3 * 4) {
      thunk_EXT_FUN_0000b588(param_4);
      return;
    }
  }
  else {
    puVar1 = local_798;
    if (param_3 == 0) {
      param_2 = 0;
      puVar1 = (undefined4 *)0x0;
    }
    thunk_EXT_FUN_0000a94e(param_1 + 2,param_2,param_3,puVar1,param_3);
    puVar1 = param_4 + param_5;
    iVar2 = 0;
    for (; puVar1 != param_4; param_4 = param_4 + 1) {
      *param_4 = local_798[iVar2];
      iVar2 = iVar2 + param_1[1];
    }
  }
  return;
}


