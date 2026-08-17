// 600a125c  FUN_600a125c  size=66 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---


void FUN_600a125c(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *local_1c;
  
  if (*param_1 == '\0') {
    pcVar2 = DAT_600a12a0;
    for (iVar1 = 0; local_1c = param_1 + 1, iVar1 < 6; iVar1 = iVar1 + 1) {
      *pcVar2 = *local_1c;
      pcVar2 = pcVar2 + -1;
      param_1 = local_1c;
    }
  }
  return;
}


