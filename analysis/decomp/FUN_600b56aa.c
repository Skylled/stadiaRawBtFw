// 600b56aa  FUN_600b56aa  size=106 bytes
// --- callers ---
//   60134420 FUN_60134420
// --- callees ---
//   60098f88 FUN_60098f88
//   600b1124 FUN_600b1124
//   6009c790 FUN_6009c790
//   6009f644 FUN_6009f644


void FUN_600b56aa(void)

{
  int unaff_r7;
  uint uStack00000000;
  undefined4 uStack00000004;
  undefined4 uStack00000008;
  
  *(undefined2 *)(*(int *)(unaff_r7 + 0x14) + 0x3e) =
       *(undefined2 *)(*(int *)(unaff_r7 + 0x10) + 0xea);
  uStack00000000 = (uint)*(ushort *)(*(int *)(unaff_r7 + 0x10) + 0xec);
  uStack00000008 = 0;
  uStack00000004 = 0;
  FUN_600b1124(*(undefined2 *)(unaff_r7 + 0xe),*(undefined2 *)(*(int *)(unaff_r7 + 0x10) + 0xe6),
               *(undefined2 *)(*(int *)(unaff_r7 + 0x10) + 0xe8),
               *(undefined2 *)(*(int *)(unaff_r7 + 0x10) + 0xea));
  uStack00000000 = (uint)*(byte *)(*(int *)(unaff_r7 + 0x14) + 10);
  uStack00000004 = 2;
  FUN_60098f88(*(undefined4 *)(unaff_r7 + 8),0,*(int *)(unaff_r7 + 0x10) + 0x2c,
               *(undefined2 *)(unaff_r7 + 0xe));
  FUN_6009c790(0);
  FUN_6009f644(1,1);
  return;
}


