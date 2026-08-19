// 600da4e2  FUN_600da4e2  size=26 bytes
// --- callers ---
// --- callees ---
//   600da4ac FUN_600da4ac


int FUN_600da4e2(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x74);
  piVar1 = (int *)FUN_600da4ac(iVar2);
  if (param_2 != *piVar1) {
    piVar1 = (int *)(iVar2 + 0x68);
  }
  return piVar1[1];
}


