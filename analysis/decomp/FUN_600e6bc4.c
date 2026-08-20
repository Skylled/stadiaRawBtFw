// 600e6bc4  FUN_600e6bc4  size=38 bytes
// --- callers ---
//   600e6bea FUN_600e6bea
// --- callees ---


uint FUN_600e6bc4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (param_1 ^ param_1 >> 6) & 0xcc00cc;
  uVar2 = param_1 ^ uVar1 ^ uVar1 << 6;
  uVar1 = (uVar2 ^ uVar2 >> 0xc) & 0xf0f0;
  return uVar2 ^ uVar1 ^ uVar1 << 0xc;
}


