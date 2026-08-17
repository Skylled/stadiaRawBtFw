// 600bc574  FUN_600bc574  size=76 bytes
// --- callers ---
//   600bc5c4 FUN_600bc5c4
// --- callees ---


char FUN_600bc574(void)

{
  char *local_14;
  int local_10;
  char local_9;
  
  local_9 = '\0';
  local_14 = DAT_600bc5c0;
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    if ((*local_14 != '\0') && (local_14[0x28] == '\x01')) {
      local_9 = local_9 + '\x01';
    }
    local_14 = local_14 + 0xa4;
  }
  return local_9;
}


