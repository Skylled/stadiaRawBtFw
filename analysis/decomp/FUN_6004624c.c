// 6004624c  FUN_6004624c  size=24 bytes
// --- callers ---
//   6004ad38 FUN_6004ad38
//   6004adfc FUN_6004adfc
//   6004ae32 FUN_6004ae32
// --- callees ---


void FUN_6004624c(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2;
  iVar1 = DAT_60046264 * (param_2[1] - iVar2 >> 3);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  *param_1 = iVar2;
  param_1[1] = iVar1;
  return;
}


