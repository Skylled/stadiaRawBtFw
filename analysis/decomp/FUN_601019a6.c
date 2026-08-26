// 601019a6  FUN_601019a6  size=12 bytes
// --- callers ---
//   601019da FUN_601019da
// --- callees ---


void FUN_601019a6(int param_1,char param_2)

{
  *(char *)(param_1 + 0xd) = param_2;
  if (param_2 != '\0') {
    *(char *)(param_1 + 0xc) = param_2;
  }
  return;
}


