// 600fbae0  FUN_600fbae0  size=52 bytes
// --- callers ---
//   600fb160 FUN_600fb160
// --- callees ---
//   600c1a34 FUN_600c1a34


void FUN_600fbae0(int param_1,undefined4 param_2)

{
  if (((*(ushort *)(param_1 + 0x28) & 0x40) != 0) && ((*(ushort *)(param_1 + 0x28) & 0x100) != 0)) {
    FUN_600c1a34(param_1,0x1d,0,*(ushort *)(param_1 + 0x28) & 0x100,param_2);
  }
  return;
}


