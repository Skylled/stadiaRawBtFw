// 6009ec14  FUN_6009ec14  size=60 bytes
// --- callers ---
//   6009ec54 FUN_6009ec54
//   6009ed00 FUN_6009ed00
//   6009c790 FUN_6009c790
//   6009e8fc FUN_6009e8fc
//   600f1592 FUN_600f1592
// --- callees ---


undefined4 FUN_6009ec14(ushort param_1)

{
  *(ushort *)(DAT_6009ec50 + 0xadc) =
       ~(ushort)(((uint)param_1 << 0x16) >> 0x16) & *(ushort *)(DAT_6009ec50 + 0xadc);
  return 1;
}


