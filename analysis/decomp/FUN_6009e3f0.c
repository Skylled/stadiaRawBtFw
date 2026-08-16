// 6009e3f0  FUN_6009e3f0  size=214 bytes
// --- callers ---
//   600f2f80 FUN_600f2f80
// --- callees ---
//   6009bd70 FUN_6009bd70
//   6009e4d0 FUN_6009e4d0
//   6009be40 FUN_6009be40


void FUN_6009e3f0(char *param_1)

{
  byte *pbVar1;
  int iVar2;
  byte local_21;
  byte local_20 [5];
  byte local_1b [4];
  char local_17;
  byte local_16;
  char local_15;
  byte *local_14;
  
  local_17 = '\0';
  if ((*(byte *)(DAT_6009e4c8 + 0x8d0) & 0xf0) != 0) {
    local_15 = *param_1;
    local_14 = (byte *)(param_1 + 1);
    while (local_15 != '\0') {
      local_16 = *local_14;
      local_21 = local_14[1];
      pbVar1 = local_1b;
      local_14 = local_14 + 2;
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        *pbVar1 = *local_14;
        pbVar1 = pbVar1 + -1;
        local_14 = local_14 + 1;
      }
      local_15 = local_15 + -1;
      local_17 = FUN_6009be40(local_20,&local_21,0);
      if ((local_17 == '\0') && ((local_20[0] & 0xc0) == 0x40)) {
        FUN_6009bd70(local_20,DAT_6009e4cc,param_1);
      }
      else {
        FUN_6009e4d0(local_20,local_21,local_16,local_14);
      }
      local_1b[3] = *local_14;
      local_14 = local_14 + local_1b[3] + 2;
    }
  }
  return;
}


