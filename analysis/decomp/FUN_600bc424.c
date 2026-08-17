// 600bc424  FUN_600bc424  size=82 bytes
// --- callers ---
//   600a038c FUN_600a038c
// --- callees ---
//   600b8ba4 FUN_600b8ba4


void FUN_600bc424(void)

{
  char *local_10;
  int local_c;
  
  local_10 = DAT_600bc478;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if ((*local_10 != '\0') && (*(short *)(local_10 + 2) != -1)) {
      FUN_600b8ba4(*(undefined2 *)(local_10 + 2),0xff);
    }
    local_10 = local_10 + 0xa4;
  }
  *(undefined1 *)(DAT_600bc47c + 0xf42) = 0;
  return;
}


