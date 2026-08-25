// 600fb5dc  FUN_600fb5dc  size=74 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34
//   600c19f4 FUN_600c19f4
//   600c0db4 FUN_600c0db4


void FUN_600fb5dc(int param_1,char *param_2)

{
  if (*param_2 == '\0') {
    FUN_600c0db4(param_1,0);
  }
  else if (*param_2 == '\x01') {
    FUN_600c19f4(4);
    if ((*(ushort *)(param_1 + 0x28) & 8) != 0) {
      FUN_600c1a34(param_1,3,0);
    }
  }
  return;
}


