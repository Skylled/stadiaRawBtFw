// 600ab88c  FUN_600ab88c  size=68 bytes
// --- callers ---
//   600c2810 FUN_600c2810
// --- callees ---
//   600ab9b8 FUN_600ab9b8


void FUN_600ab88c(void)

{
  undefined1 local_d;
  undefined4 local_c;
  
  local_c = DAT_600ab8d0;
  for (local_d = 0; local_d < 10; local_d = local_d + 1) {
    if (*(char *)(local_c + 0x2d) != '\0') {
      FUN_600ab9b8(*(undefined1 *)(local_c + 0x2c));
    }
    local_c = local_c + 0x30;
  }
  return;
}


