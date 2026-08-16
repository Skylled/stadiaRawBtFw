// 6004baa8  FUN_6004baa8  size=66 bytes
// --- callers ---
//   600416d4 FUN_600416d4
//   6004b8ce FUN_6004b8ce
// --- callees ---
//   6004ba16 FUN_6004ba16
//   6004c464 thunk_FUN_60092528
//   6004b9e0 FUN_6004b9e0


void FUN_6004baa8(int *param_1)

{
  int iVar1;
  int local_14;
  
  local_14 = -1;
  iVar1 = FUN_6004b9e0();
  if (iVar1 == 0) {
    local_14 = iVar1;
    iVar1 = thunk_FUN_60092528(&local_14,0);
    if (iVar1 == 0) {
      FUN_6004ba16(&local_14,0xffffffff);
      DataMemoryBarrier(0x1b);
      *param_1 = local_14;
    }
  }
  else {
    FUN_6004ba16(param_1,0xffffffff);
  }
  return;
}


