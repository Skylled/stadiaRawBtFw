// 600ecce2  FUN_600ecce2  size=114 bytes
// --- callers ---
//   600ecd54 FUN_600ecd54
// --- callees ---


uint FUN_600ecce2(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 - 0x41 & 0xff;
  if (0x19 < uVar1) {
    uVar1 = 0xff;
  }
  uVar1 = (uVar1 ^ (param_1 - 0x47 ^ uVar1) & (int)((param_1 - 0x61 & 0xff) - 0x1a) >> 0x1f) & 0xff;
  uVar1 = ((param_1 + 4 ^ uVar1) & (int)((param_1 - 0x30 & 0xff) - 10) >> 0x1f ^ uVar1) & 0xff;
  uVar1 = uVar1 ^ (uVar1 ^ 0x3e) & (int)((param_1 ^ 0x2b) - 1 & ~(param_1 ^ 0x2b)) >> 0x1f;
  return (uVar1 ^ (uVar1 ^ 0x3f) & (int)((param_1 ^ 0x2f) - 1 & ~(param_1 ^ 0x2f)) >> 0x1f) &
         ~((int)((param_1 ^ 0x3d) - 1 & ~(param_1 ^ 0x3d)) >> 0x1f);
}


