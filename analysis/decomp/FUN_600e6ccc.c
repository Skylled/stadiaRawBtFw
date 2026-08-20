// 600e6ccc  FUN_600e6ccc  size=38 bytes
// --- callers ---
//   600e6cf2 FUN_600e6cf2
// --- callees ---


uint FUN_600e6ccc(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (param_1 ^ param_1 >> 0xc) & 0xf0f0;
  uVar2 = param_1 ^ uVar1 ^ uVar1 << 0xc;
  uVar1 = (uVar2 ^ uVar2 >> 6) & 0xcc00cc;
  return uVar2 ^ uVar1 ^ uVar1 << 6;
}


