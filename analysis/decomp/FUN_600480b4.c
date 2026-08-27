// 600480b4  FUN_600480b4  size=18 bytes
// --- callers ---
//   60047678 queue__60047678
// --- callees ---


int FUN_600480b4(void)

{
  int *piVar1;
  
  piVar1 = DAT_600480c8;
  if (*DAT_600480c8 != 0) {
    *(int *)(*DAT_600480c8 + 0x54) = *(int *)(*DAT_600480c8 + 0x54) + 1;
  }
  return *piVar1;
}


