// 600f2b6a  FUN_600f2b6a  size=56 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600a16fc FUN_600a16fc


void FUN_600f2b6a(char *param_1)

{
  if (*param_1 != '\0') {
    param_1[-1] = '\x01';
    FUN_600a16fc(param_1 + -1);
  }
  return;
}


