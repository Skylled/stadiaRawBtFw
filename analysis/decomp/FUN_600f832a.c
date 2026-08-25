// 600f832a  FUN_600f832a  size=118 bytes
// --- callers ---
//   600b6d30 FUN_600b6d30
// --- callees ---
//   600b7674 FUN_600b7674
//   600f9db4 FUN_600f9db4


void FUN_600f832a(int param_1)

{
  if ((*(char *)(param_1 + 0x80) != '\0') &&
     (*(char *)(param_1 + 0xb4) = *(char *)(param_1 + 0xb4) + '\x01',
     *(byte *)(param_1 + 0x80) < *(byte *)(param_1 + 0xb4))) {
    FUN_600f9db4(param_1);
    return;
  }
  if ((*(char *)(param_1 + 0xb9) == '\0') && (*(char *)(param_1 + 0xb8) == '\0')) {
    if (*(char *)(param_1 + 0xb7) == '\0') {
      FUN_600b7674(param_1,0,0x10);
    }
    else {
      FUN_600b7674(param_1,2,0x10);
    }
  }
  return;
}


