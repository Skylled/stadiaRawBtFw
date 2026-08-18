// 6009e9e4  FUN_6009e9e4  size=154 bytes
// --- callers ---
//   600a9fce FUN_600a9fce
// --- callees ---
//   6009e8fc FUN_6009e8fc
//   6009e70c FUN_6009e70c
//   6009e768 FUN_6009e768
//   6009d9d4 FUN_6009d9d4
//   6009e95c FUN_6009e95c
//   600f0f26 FUN_600f0f26


void FUN_6009e9e4(int param_1)

{
  switch(*(undefined2 *)(param_1 + 0x14)) {
  case 0x2f:
    FUN_6009e70c();
    break;
  case 0x30:
    *(ushort *)(DAT_6009eaa8 + 0xb10) = *(ushort *)(DAT_6009eaa8 + 0xb10) & 0xfeff;
    FUN_6009d9d4(*(undefined2 *)(DAT_6009eaa8 + 0xb12),*(undefined2 *)(DAT_6009eaa8 + 0xb10));
    FUN_6009e8fc();
    break;
  default:
    break;
  case 0x33:
    if (*(char *)(DAT_6009eaa8 + 0xa34) == '\x01') {
      if (*(int *)(param_1 + 0x10) == 0) {
        FUN_600f0f26(DAT_6009eaac);
      }
      else if (*(int *)(DAT_6009eab0 + 0xd4) != 0) {
        (**(code **)(DAT_6009eab0 + 0xd4))(0x13,*(undefined4 *)(param_1 + 0x10));
      }
    }
    break;
  case 0x37:
    FUN_6009e95c();
    break;
  case 0x38:
    FUN_6009e768();
  }
  return;
}


