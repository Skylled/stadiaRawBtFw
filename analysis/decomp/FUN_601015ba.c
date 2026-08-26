// 601015ba  FUN_601015ba  size=44 bytes
// --- callers ---
//   601015e6 FUN_601015e6
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_601015ba(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = param_2[1];
  param_3[1] = *param_2;
  param_3[2] = iVar1;
  param_3[3] = param_2[2];
  iVar1 = param_2[5];
  if (*(char *)((int)param_2 + 0xb) != '\x01') {
    iVar1 = iVar1 + 1;
  }
  *param_3 = iVar1;
  thunk_EXT_FUN_0000b572(param_3 + 4,param_2[3],*param_3);
  return;
}


