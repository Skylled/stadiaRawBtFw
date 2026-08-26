// 600d5f7e  FUN_600d5f7e  size=68 bytes
// --- callers ---
//   600d6750 FUN_600d6750
//   600644dc usb_host_audio_topology__600644dc
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d238 thunk_EXT_FUN_0000b588


int * FUN_600d5f7e(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2[1] - *param_2;
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = thunk_EXT_FUN_0000b532(iVar2);
  }
  *param_1 = iVar1;
  param_1[1] = iVar1;
  param_1[2] = iVar2 + iVar1;
  iVar2 = param_2[1] - *param_2;
  if (iVar2 != 0) {
    iVar1 = thunk_EXT_FUN_0000b588(iVar1,*param_2,iVar2);
  }
  param_1[1] = iVar1 + iVar2;
  return param_1;
}


