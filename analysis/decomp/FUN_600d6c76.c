// 600d6c76  FUN_600d6c76  size=58 bytes
// --- callers ---
//   6006581c haptics_cluster__6006581c
// --- callees ---
//   600d4a7e FUN_600d4a7e
//   600d49ce FUN_600d49ce
//   600d4b78 FUN_600d4b78


uint FUN_600d6c76(char *param_1)

{
  uint uVar1;
  
  if (*param_1 == '\0') {
    uVar1 = FUN_600d4a7e(*(undefined4 *)(param_1 + 4));
    if ((uVar1 & 0xff) == 0) {
      FUN_600d49ce(*(undefined4 *)(param_1 + 8));
      uVar1 = FUN_600d4b78(*(undefined4 *)(param_1 + 4),0,30000);
      if ((uVar1 & 0xff) == 0) {
        *param_1 = '\x01';
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


