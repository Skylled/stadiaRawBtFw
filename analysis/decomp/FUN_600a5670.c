// 600a5670  FUN_600a5670  size=156 bytes
// --- callers ---
//   600a4820 FUN_600a4820
//   600a5714 FUN_600a5714
//   600a59d0 FUN_600a59d0
// --- callees ---
//   6009ff18 FUN_6009ff18
//   600a8108 FUN_600a8108


void FUN_600a5670(void)

{
  int iVar1;
  
  if (((*(byte *)(DAT_600a570c + 0x118d) & 4) == 0) &&
     ((*(char *)(DAT_600a570c + 0x118c) != '\x03' || ((*(byte *)(DAT_600a570c + 0x118d) & 1) == 0)))
     ) {
    if (*(char *)(DAT_600a570c + 0x118c) != '\x01') {
      return;
    }
    if ((*(byte *)(DAT_600a570c + 0x118d) & 0x40) == 0) {
      return;
    }
  }
  iVar1 = FUN_6009ff18(DAT_600a5710);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x54) = 0;
  }
  FUN_600a8108(0);
  if (*(int *)(DAT_600a570c + 0x1130) != 0) {
    (**(code **)(DAT_600a570c + 0x1130))(0);
  }
  return;
}


