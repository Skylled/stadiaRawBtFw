// 600ce24c  FUN_600ce24c  size=16 bytes
// --- callers ---
//   600ce25c FUN_600ce25c
//   600cbdc8 xbara__600cbdc8
//   60051240 main__60051240
//   60071a30 board__60071a30
// --- callees ---


uint FUN_600ce24c(int param_1)

{
  return **(uint **)(param_1 + 0x20) >> (*(uint *)(param_1 + 0x18) & 0xff) & 1;
}


