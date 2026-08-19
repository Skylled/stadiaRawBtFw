// 600dbd64  FUN_600dbd64  size=66 bytes
// --- callers ---
//   600dbda6 FUN_600dbda6
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


undefined4 FUN_600dbd64(int *param_1,int param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    uVar1 = 3;
  }
  else {
    iVar2 = *param_1;
    if ((uint)param_1[1] <= param_3) {
      param_3 = param_1[1];
    }
    if (iVar2 != 0) {
      iVar3 = param_3 * 2;
      if (iVar2 != iVar2 + iVar3) {
        thunk_EXT_FUN_0000b588(param_2,iVar2,iVar3,iVar2 + iVar3,param_4);
      }
      *param_1 = *param_1 + iVar3;
    }
    param_1[1] = param_1[1] - param_3;
    if (param_4 != (uint *)0x0) {
      *param_4 = param_3;
    }
    uVar1 = 0;
  }
  return uVar1;
}


