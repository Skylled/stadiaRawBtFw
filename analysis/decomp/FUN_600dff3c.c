// 600dff3c  FUN_600dff3c  size=24 bytes
// --- callers ---
//   60083e30 FUN_60083e30
// --- callees ---
//   600dff24 FUN_600dff24


undefined4 FUN_600dff3c(uint *param_1)

{
  undefined4 uVar1;
  
  if (((int)(param_1[4] << 0x1d) < 0) && ((*param_1 & 0x1010) == 0)) {
    uVar1 = FUN_600dff24();
    return uVar1;
  }
  return 0;
}


