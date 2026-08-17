// 6009ebd8  FUN_6009ebd8  size=54 bytes
// --- callers ---
//   6009ec54 FUN_6009ec54
//   6009c790 FUN_6009c790
//   6009e6c0 FUN_6009e6c0
// --- callees ---


undefined1 FUN_6009ebd8(ushort param_1)

{
  *(ushort *)(DAT_6009ec10 + 0xadc) =
       (ushort)(((uint)param_1 << 0x16) >> 0x16) | *(ushort *)(DAT_6009ec10 + 0xadc);
  return 1;
}


