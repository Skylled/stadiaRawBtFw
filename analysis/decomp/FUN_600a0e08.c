// 600a0e08  FUN_600a0e08  size=122 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600aa3cc FUN_600aa3cc
//   600a031c FUN_600a031c
//   600f1786 FUN_600f1786


void FUN_600a0e08(char *param_1)

{
  int iVar1;
  int iVar2;
  char *local_1c;
  
  iVar1 = DAT_600a0e84;
  FUN_600aa3cc(DAT_600a0e84 + 0x14);
  if (*param_1 == '\0') {
    for (iVar2 = 0; local_1c = param_1 + 1, iVar2 < 8; iVar2 = iVar2 + 1) {
      *(char *)(iVar1 + 0x123 + iVar2) = *local_1c;
      param_1 = local_1c;
    }
    if ((*(char *)(iVar1 + 0x12a) < '\0') && ((*(byte *)(iVar1 + 0x1ad) & 0x40) != 0)) {
      FUN_600a031c(1);
    }
    else {
      FUN_600f1786(0);
    }
  }
  return;
}


