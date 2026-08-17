// 600a0f7c  FUN_600a0f7c  size=82 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a0300 FUN_600a0300
//   600aa3cc FUN_600aa3cc


void FUN_600a0f7c(char *param_1)

{
  int iVar1;
  int iVar2;
  char *local_1c;
  
  iVar1 = DAT_600a0fd0;
  FUN_600aa3cc(DAT_600a0fd0 + 0x14);
  if (*param_1 == '\0') {
    for (iVar2 = 0; local_1c = param_1 + 1, iVar2 < 0x40; iVar2 = iVar2 + 1) {
      *(char *)(iVar1 + 0x19f + iVar2) = *local_1c;
      param_1 = local_1c;
    }
  }
  FUN_600a0300();
  return;
}


