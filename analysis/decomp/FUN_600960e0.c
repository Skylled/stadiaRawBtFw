// 600960e0  FUN_600960e0  size=114 bytes
// --- callers ---
// --- callees ---
//   600d9242 thunk_FUN_6006d9f0
//   60096378 FUN_60096378


void FUN_600960e0(int param_1)

{
  FUN_60096378(*(undefined2 *)(param_1 + 8));
  *(uint *)(DAT_60096154 + 0x134) =
       ~(1 << (*(ushort *)(param_1 + 8) & 0xff)) & *(uint *)(DAT_60096154 + 0x134);
  if (*(int *)(DAT_60096154 + 0x134) == 0) {
    *(undefined1 *)(DAT_60096154 + 0x116) = 3;
    thunk_FUN_6006d9f0(*(undefined2 *)(param_1 + 8));
  }
  else if (*(int *)(DAT_60096154 + (*(ushort *)(param_1 + 8) + 0x46) * 4) != 0) {
    (**(code **)(DAT_60096154 + (*(ushort *)(param_1 + 8) + 0x46) * 4))(0);
  }
  return;
}


