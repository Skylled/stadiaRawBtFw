// 600d5c90  FUN_600d5c90  size=46 bytes
// --- callers ---
//   600d614a FUN_600d614a
// --- callees ---
//   600d5c6a FUN_600d5c6a


int FUN_600d5c90(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600d5c6a();
  if (iVar1 != 0) {
    iVar2 = *param_1;
    if (*(char *)(iVar2 + 5) == '\x03') {
      iVar1 = 0;
      if (*(char *)(iVar2 + 4) != '\0') {
        iVar1 = 1;
      }
    }
    else if (*(char *)(iVar2 + 5) == '\x04') {
      if (*(char *)(iVar2 + 4) == '\0') {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}


