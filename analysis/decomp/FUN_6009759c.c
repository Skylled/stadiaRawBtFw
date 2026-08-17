// 6009759c  FUN_6009759c  size=90 bytes
// --- callers ---
//   60097dc8 FUN_60097dc8
//   600976f8 FUN_600976f8
//   60097f5c FUN_60097f5c
//   60097b20 FUN_60097b20
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


char * FUN_6009759c(int param_1)

{
  int iVar1;
  char *pcVar2;
  char *local_10;
  byte local_9;
  
  pcVar2 = DAT_600975f8;
  if (param_1 != 0) {
    local_10 = DAT_600975fc;
    for (local_9 = 1; local_9 < 9; local_9 = local_9 + 1) {
      if ((*local_10 != '\0') &&
         (iVar1 = thunk_EXT_FUN_0000b554(param_1 + 1,local_10 + 1,6), iVar1 == 0)) {
        return local_10;
      }
      local_10 = local_10 + 0x14;
    }
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}


