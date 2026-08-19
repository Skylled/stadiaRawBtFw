// 600dff24  FUN_600dff24  size=24 bytes
// --- callers ---
//   600dff3c FUN_600dff3c
//   60083e30 FUN_60083e30
// --- callees ---


int FUN_600dff24(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x10) & 0x10) == 0) {
    iVar1 = 0x68;
  }
  else {
    iVar1 = 0x20;
  }
  if (*(int *)(param_1 + 0x5c) << 0x16 < 0) {
    iVar1 = iVar1 + 4;
  }
  return iVar1;
}


