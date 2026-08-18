// 600c69dc  FUN_600c69dc  size=92 bytes
// --- callers ---
//   600fee40 FUN_600fee40
// --- callees ---
//   600fed9e FUN_600fed9e
//   60094ffc FUN_60094ffc


void FUN_600c69dc(undefined1 param_1)

{
  int iVar1;
  char *local_10;
  byte local_9;
  
  local_10 = DAT_600c6a38;
  for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
    if ((*local_10 != '\0') && (iVar1 = FUN_60094ffc(param_1,local_10 + 1,2), iVar1 == 0)) {
      FUN_600fed9e(param_1,local_10 + 1);
    }
    local_10 = local_10 + 7;
  }
  return;
}


