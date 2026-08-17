// 600a5880  FUN_600a5880  size=94 bytes
// --- callers ---
//   600a08c4 FUN_600a08c4
// --- callees ---
//   600b3138 FUN_600b3138
//   600b3790 FUN_600b3790
//   600b30ac FUN_600b30ac
//   600b3804 FUN_600b3804
//   600b0824 FUN_600b0824


void FUN_600a5880(void)

{
  if (*(char *)(DAT_600a58e0 + 0x1174) == '\x03') {
    FUN_600b3790(1);
    FUN_600b3804(1);
  }
  else if ((*(byte *)(DAT_600a58e0 + 0x819) & 8) == 0) {
    *(undefined1 *)(DAT_600a58e0 + 0x1174) = 2;
  }
  else {
    FUN_600b30ac(0,DAT_600a58e4);
    FUN_600b0824(DAT_600a58e8);
    FUN_600b3138(0,DAT_600a58ec);
    *(undefined1 *)(DAT_600a58e0 + 0x882) = 1;
  }
  return;
}


