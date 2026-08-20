// 600e6a90  FUN_600e6a90  size=24 bytes
// --- callers ---
//   600eb588 FUN_600eb588
//   6008aad8 FUN_6008aad8
//   6008dc2c FUN_6008dc2c
// --- callees ---


uint FUN_600e6a90(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < 0x100) {
    uVar1 = (int)(uint)*(byte *)(param_1 + ((int)param_2 >> 3)) >> (param_2 & 7) & 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


