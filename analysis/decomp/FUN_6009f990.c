// 6009f990  FUN_6009f990  size=154 bytes
// --- callers ---
//   6009e84c FUN_6009e84c
//   6009c59c FUN_6009c59c
//   6009dd74 FUN_6009dd74
//   6009c444 FUN_6009c444
// --- callees ---
//   6009f644 FUN_6009f644
//   6009f93c FUN_6009f93c


void FUN_6009f990(undefined1 param_1)

{
  int local_10;
  byte local_9;
  
  local_10 = DAT_6009fa2c;
  if (*(char *)(DAT_6009fa30 + 0xa6b) != '\0') {
    if (*(char *)(DAT_6009fa30 + 0x9c6) == '\0') {
      if (*(byte *)(DAT_6009fa30 + 0xa6c) < *(byte *)(DAT_6009fa30 + 0xa6b)) {
        FUN_6009f93c(param_1);
      }
      else {
        FUN_6009f644(param_1,1);
      }
    }
    else {
      for (local_9 = 0; local_9 < 8; local_9 = local_9 + 1) {
        if (((*(byte *)(local_10 + 0x72) & 2) != 0) && ((*(byte *)(local_10 + 0x72) & 1) != 0)) {
          FUN_6009f93c(param_1);
          return;
        }
        local_10 = local_10 + 0xfc;
      }
      FUN_6009f644(param_1,1);
    }
  }
  return;
}


