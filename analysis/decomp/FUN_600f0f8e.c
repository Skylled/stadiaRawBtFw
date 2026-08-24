// 600f0f8e  FUN_600f0f8e  size=172 bytes
// --- callers ---
//   6009ff18 FUN_6009ff18
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600fbc02 FUN_600fbc02
//   600f0f48 FUN_600f0f48


undefined1 FUN_600f0f8e(byte *param_1,int param_2)

{
  int iVar1;
  byte local_24;
  byte local_23;
  byte local_22;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [19];
  undefined1 local_9;
  
  local_9 = 0;
  if ((*param_1 & 0xc0) == 0x40) {
    if (((*(byte *)(param_2 + 0xe4) & 2) != 0) && ((*(byte *)(param_2 + 0x7b) & 2) != 0)) {
      local_24 = param_1[2];
      local_23 = param_1[1];
      local_22 = *param_1;
      FUN_600fbc02(param_2 + 0x7c,0x10,&local_24,3,auStack_20);
      local_24 = param_1[5];
      local_23 = param_1[4];
      local_22 = param_1[3];
      iVar1 = thunk_EXT_FUN_0000b554(auStack_1c,&local_24,3);
      if (iVar1 == 0) {
        FUN_600f0f48(param_2,param_1);
        local_9 = 1;
      }
    }
  }
  else {
    local_9 = 0;
  }
  return local_9;
}


