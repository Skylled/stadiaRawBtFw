// 600f190a  FUN_600f190a  size=66 bytes
// --- callers ---
//   600a4c5c FUN_600a4c5c
//   600a51a8 FUN_600a51a8
// --- callees ---


bool FUN_600f190a(int param_1,int param_2)

{
  return (1 << (*(byte *)(param_2 + 0x10) & 0x1f) &
         *(uint *)((uint)(*(byte *)(param_2 + 0x10) >> 5) * 4 + param_1 + 4)) != 0;
}


