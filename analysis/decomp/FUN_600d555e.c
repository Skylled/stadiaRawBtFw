// 600d555e  FUN_600d555e  size=26 bytes
// --- callers ---
// --- callees ---


char FUN_600d555e(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 0x90) == 3) {
    cVar1 = *(char *)(param_1 + 0x104);
    if (cVar1 == '\0') {
      cVar1 = *(char *)(param_1 + 0x105);
    }
  }
  else {
    cVar1 = '\0';
  }
  return cVar1;
}


