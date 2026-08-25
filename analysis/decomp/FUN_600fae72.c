// 600fae72  FUN_600fae72  size=50 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34


void FUN_600fae72(int param_1,char *param_2)

{
  if (*param_2 == '\0') {
    *(undefined1 *)(param_1 + 0x2a) = 1;
  }
  else {
    FUN_600c1a34(param_1,0x17,param_2);
  }
  return;
}


