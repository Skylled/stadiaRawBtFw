// 600a05ac  FUN_600a05ac  size=74 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a0244 FUN_600a0244
//   600aa3cc FUN_600aa3cc


void FUN_600a05ac(char *param_1)

{
  int iVar1;
  char *local_1c;
  
  FUN_600aa3cc(DAT_600a05f8);
  if (*param_1 == '\0') {
    for (iVar1 = 0; local_1c = param_1 + 1, iVar1 < 8; iVar1 = iVar1 + 1) {
      *(char *)(DAT_600a05fc + iVar1) = *local_1c;
      param_1 = local_1c;
    }
  }
  FUN_600a0244();
  return;
}


