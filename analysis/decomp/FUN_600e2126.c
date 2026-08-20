// 600e2126  FUN_600e2126  size=50 bytes
// --- callers ---
//   600e22a2 FUN_600e22a2
// --- callees ---


void FUN_600e2126(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)(param_1 + -4);
  do {
    puVar1 = puVar1 + 1;
    uVar2 = *puVar1;
    *puVar1 = (uVar2 & 0x30303030) >> 0x10 | (uVar2 & 0x30303030) << 0x10 |
              (uVar2 & 0xc0c0c0c) >> 8 | (uVar2 & 0xc0c0c0c) << 0x18 | uVar2 & 0x3030303 |
              (uVar2 & 0xc0c0c0c0) >> 0x18 | (uVar2 & 0xc0c0c0c0) << 8;
  } while ((uint *)(param_1 + 0x1c) != puVar1);
  return;
}


