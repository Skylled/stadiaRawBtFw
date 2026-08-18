// 600d26ea  FUN_600d26ea  size=28 bytes
// --- callers ---
//   60056968 FUN_60056968
//   600569e4 FUN_600569e4
//   600d194a FUN_600d194a
// --- callees ---


undefined4 FUN_600d26ea(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 == 0) {
    return 4;
  }
  piVar1 = *(int **)(param_1 + 0x2d4);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 1;
    }
    if (piVar1 == (int *)param_2) break;
    piVar1 = (int *)*piVar1;
  }
  return 0;
}


