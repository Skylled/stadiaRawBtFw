// 600bc7e8  FUN_600bc7e8  size=52 bytes
// --- callers ---
//   600a6b20 FUN_600a6b20
//   600a5760 FUN_600a5760
//   600f033a FUN_600f033a
//   60098f88 FUN_60098f88
// --- callees ---
//   600bb6dc FUN_600bb6dc


void FUN_600bc7e8(int param_1)

{
  int iVar1;
  int iStack_14;
  int local_10;
  char *local_c;
  
  if (param_1 == 0) {
    local_c = DAT_600bc87c;
    for (iStack_14 = 0; iStack_14 < 4; iStack_14 = iStack_14 + 1) {
      if (*local_c != '\0') {
        local_10 = *(int *)(local_c + 0x5c);
        while (local_10 != 0) {
          iVar1 = *(int *)(local_10 + 0x124);
          FUN_600b5e00(local_10,0x21,0);
          local_10 = iVar1;
        }
      }
      local_c = local_c + 0xa4;
    }
  }
  else {
    iVar1 = FUN_600bb6dc(param_1,1);
    if (iVar1 != 0) {
      local_10 = *(int *)(iVar1 + 0x5c);
      while (local_10 != 0) {
        iVar1 = *(int *)(local_10 + 0x124);
        FUN_600b5e00(local_10,0x21,0);
        local_10 = iVar1;
      }
    }
  }
  return;
}


