// 600d3638  FUN_600d3638  size=32 bytes
// --- callers ---
//   60058600 FUN_60058600
// --- callees ---


bool FUN_600d3638(int *param_1)

{
  if (0x7f < *param_1 - 1U) {
    return false;
  }
  if (*(char *)((int)param_1 + 0xf) == '\0') {
    return *(char *)((int)param_1 + *param_1 + 0xf) == '\0';
  }
  return true;
}


