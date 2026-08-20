// 600e6aa8  FUN_600e6aa8  size=26 bytes
// --- callers ---
//   600e6ac2 FUN_600e6ac2
// --- callees ---


void FUN_600e6aa8(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = (*param_2 ^ *param_1 >> 1) & 0x55555555;
  *param_1 = *param_1 ^ uVar1 << 1;
  *param_2 = uVar1 ^ *param_2;
  return;
}


