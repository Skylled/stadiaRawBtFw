// 6009605c  FUN_6009605c  size=128 bytes
// --- callers ---
// --- callees ---
//   600d923e thunk_FUN_6006d9cc


void FUN_6009605c(int param_1)

{
  if ((*(int *)(DAT_600960dc + 0x134) == 0) && (*(char *)(DAT_600960dc + 0x116) != '\x02')) {
    *(uint *)(DAT_600960dc + 0x134) =
         1 << (*(ushort *)(param_1 + 8) & 0xff) | *(uint *)(DAT_600960dc + 0x134);
    thunk_FUN_6006d9cc(*(undefined2 *)(param_1 + 8));
  }
  else {
    *(uint *)(DAT_600960dc + 0x134) =
         1 << (*(ushort *)(param_1 + 8) & 0xff) | *(uint *)(DAT_600960dc + 0x134);
    if (*(int *)(DAT_600960dc + (*(ushort *)(param_1 + 8) + 0x46) * 4) != 0) {
      (**(code **)(DAT_600960dc + (*(ushort *)(param_1 + 8) + 0x46) * 4))(1);
    }
  }
  return;
}


