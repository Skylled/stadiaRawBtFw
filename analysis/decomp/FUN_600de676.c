// 600de676  FUN_600de676  size=20 bytes
// --- callers ---
//   600dd8f2 FUN_600dd8f2
// --- callees ---
//   6013d068 thunk_EXT_FUN_0000b52e


int FUN_600de676(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    thunk_EXT_FUN_0000b52e(*(int *)(param_1 + 4),0x104);
  }
  return param_1;
}


