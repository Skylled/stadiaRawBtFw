// 600fbb14  FUN_600fbb14  size=172 bytes
// --- callers ---
// --- callees ---
//   600c1548 FUN_600c1548


void FUN_600fbb14(int param_1,undefined4 *param_2)

{
  *(char *)(param_1 + 0xcd) = (char)*param_2;
  *(char *)(param_1 + 0xce) = (char)((uint)*param_2 >> 8);
  *(char *)(param_1 + 0xcf) = (char)((uint)*param_2 >> 0x10);
  *(char *)(param_1 + 0xd0) = (char)((uint)*param_2 >> 0x18);
  *(char *)(param_1 + 0xdd) = (char)*param_2;
  *(char *)(param_1 + 0xde) = (char)((uint)*param_2 >> 8);
  *(char *)(param_1 + 0xdf) = (char)((uint)*param_2 >> 0x10);
  *(char *)(param_1 + 0xe0) = (char)((uint)*param_2 >> 0x18);
  *(undefined1 *)(param_1 + 0x199) = 0;
  FUN_600c1548(param_1);
  return;
}


