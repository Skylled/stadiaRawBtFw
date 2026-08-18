// 600ce1f8  FUN_600ce1f8  size=40 bytes
// --- callers ---
//   600ce220 FUN_600ce220
//   6005e904 FUN_6005e904
// --- callees ---
//   601014d4 FUN_601014d4


void FUN_600ce1f8(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  while( true ) {
    piVar2 = (int *)*param_1;
    if (((undefined4 *)param_1[1] == (undefined4 *)(*piVar2 + piVar2[1] * 4)) ||
       (iVar1 = FUN_601014d4(*(undefined4 *)param_1[1],piVar2[2]), iVar1 != 0)) break;
    param_1[1] = param_1[1] + 4;
  }
  return;
}


