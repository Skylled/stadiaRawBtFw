// 600d5c3c  FUN_600d5c3c  size=46 bytes
// --- callers ---
//   600d61c8 FUN_600d61c8
// --- callees ---
//   600d5c16 FUN_600d5c16


int FUN_600d5c3c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600d5c16();
  if (iVar1 != 0) {
    iVar2 = *param_1;
    if (*(char *)(iVar2 + 5) == '\x02') {
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


