// 600a7ee8  FUN_600a7ee8  size=194 bytes
// --- callers ---
//   600a51a8 FUN_600a51a8
// --- callees ---


int * FUN_600a7ee8(char param_1,short param_2,int param_3,int param_4)

{
  int *piVar1;
  int local_10;
  int *local_c;
  
  piVar1 = *(int **)(DAT_600a7fac + 0x1aa8);
  local_c = DAT_600a7fb0;
  if ((((param_1 == '\0') || (piVar1 == (int *)0x0)) || (param_2 != (short)piVar1[3])) ||
     ((param_3 != *piVar1 || (param_4 != piVar1[1])))) {
    for (local_10 = 0; local_10 < 0xe; local_10 = local_10 + 1) {
      if ((((*(ushort *)((int)local_c + 0xe) & 0x80) != 0) && (param_2 == (short)local_c[3])) &&
         (param_3 == *local_c)) {
        if ((param_1 != '\0') && (param_4 == local_c[1])) {
          return local_c;
        }
        if ((param_1 == '\0') && (param_4 == local_c[2])) {
          return local_c;
        }
      }
      local_c = local_c + 5;
    }
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(DAT_600a7fac + 0x1aa8);
  }
  return piVar1;
}


