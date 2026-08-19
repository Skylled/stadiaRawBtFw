// 600dacc4  FUN_600dacc4  size=50 bytes
// --- callers ---
// --- callees ---


bool FUN_600dacc4(undefined4 param_1,int param_2)

{
  if ((((*(int *)(param_2 + 0x1c) == 0x800) && (*(int *)(param_2 + 0x20) == 0x800)) &&
      (*(int *)(param_2 + 0x24) == 0x800)) &&
     ((*(int *)(param_2 + 0x28) == 0x800 && (*(int *)(param_2 + 0x2c) == 0)))) {
    return *(int *)(param_2 + 0x30) == 0;
  }
  return false;
}


