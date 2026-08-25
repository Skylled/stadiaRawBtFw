// 600f6a8a  FUN_600f6a8a  size=38 bytes
// --- callers ---
//   600ffa34 FUN_600ffa34
//   600f4d8e FUN_600f4d8e
// --- callees ---
//   600aa340 FUN_600aa340


void FUN_600f6a8a(int param_1)

{
  *(int *)(param_1 + 0xd8) = param_1;
  FUN_600aa340(param_1 + 200,0x31,0x1e);
  return;
}


