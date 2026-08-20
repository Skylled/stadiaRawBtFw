// 600e6ac2  FUN_600e6ac2  size=48 bytes
// --- callers ---
//   600e6af2 FUN_600e6af2
//   600e6cf2 FUN_600e6cf2
//   600e6c88 FUN_600e6c88
//   600e6b3a FUN_600e6b3a
// --- callees ---
//   600e6aa8 FUN_600e6aa8


void FUN_600e6ac2(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_600e6aa8(param_1,param_1 + 4);
  FUN_600e6aa8(iVar1 + 8,iVar1 + 0xc);
  FUN_600e6aa8(param_1 + 0x10,param_1 + 0x14);
  FUN_600e6aa8(param_1 + 0x18,param_1 + 0x1c);
  return;
}


