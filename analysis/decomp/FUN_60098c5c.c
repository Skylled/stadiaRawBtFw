// 60098c5c  FUN_60098c5c  size=98 bytes
// --- callers ---
// --- callees ---
//   60098c14 FUN_60098c14


void FUN_60098c5c(short *param_1)

{
  int iVar1;
  char *local_18;
  char local_11;
  
  local_11 = -1;
  if ((*param_1 == -0x392) && (param_1[1] != 0)) {
    local_11 = **(char **)(param_1 + 2);
    local_18 = *(char **)(param_1 + 2) + 1;
  }
  if (local_11 == '\0') {
    for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
      *(char *)(DAT_60098cc0 + iVar1) = *local_18;
      local_18 = local_18 + 1;
    }
  }
  FUN_60098c14();
  return;
}


