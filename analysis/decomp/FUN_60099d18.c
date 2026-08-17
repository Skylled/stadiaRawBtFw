// 60099d18  FUN_60099d18  size=70 bytes
// --- callers ---
//   600c288c FUN_600c288c
//   600c2810 FUN_600c2810
//   600c4da8 FUN_600c4da8
//   600bc5c4 FUN_600bc5c4
// --- callees ---


short FUN_60099d18(void)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined4 local_c;
  
  local_c = DAT_60099d60;
  local_10 = 0;
  for (local_e = 0; local_e < 4; local_e = local_e + 1) {
    if (*(char *)(local_c + 0x128) != '\0') {
      local_10 = local_10 + 1;
    }
    local_c = local_c + 0x14c;
  }
  return local_10;
}


