// 600ec740  FUN_600ec740  size=22 bytes
// --- callers ---
//   6008ffc0 tasn_dec__6008ffc0
//   600901c8 tasn_dec__600901c8
//   6008f4ac tasn_dec__6008f4ac
//   6008fa18 tasn_dec__6008fa18
//   6008f794 tasn_dec__6008f794
// --- callees ---


undefined4 FUN_600ec740(undefined4 *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)*param_1;
  if ((*pcVar1 == '\0') && (pcVar1[1] == '\0')) {
    *param_1 = pcVar1 + 2;
    return 1;
  }
  return 0;
}


