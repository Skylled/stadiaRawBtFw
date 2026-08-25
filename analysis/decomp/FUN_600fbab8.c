// 600fbab8  FUN_600fbab8  size=40 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34


void FUN_600fbab8(int param_1,undefined4 param_2)

{
  if ((*(ushort *)(param_1 + 0x28) & 0x20) != 0) {
    FUN_600c1a34(param_1,0x24,0,*(ushort *)(param_1 + 0x28) & 0x20,param_2);
  }
  return;
}


