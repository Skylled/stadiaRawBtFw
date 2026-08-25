// 600f3b0a  FUN_600f3b0a  size=110 bytes
// --- callers ---
//   60134420 FUN_60134420
// --- callees ---
//   600f46b4 FUN_600f46b4
//   600afd84 FUN_600afd84
//   600afd28 FUN_600afd28
//   600afdf8 FUN_600afdf8


undefined1 FUN_600f3b0a(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 in_r3;
  int unaff_r7;
  
  uVar1 = FUN_600afd28(in_r3);
  *(undefined4 *)(unaff_r7 + 0x14) = uVar1;
  if ((*(int *)(unaff_r7 + 0x18) == 0) || (*(int *)(unaff_r7 + 0x14) == 0)) {
    uVar3 = 0x87;
  }
  else {
    iVar2 = FUN_600afd84(*(undefined2 *)(unaff_r7 + 6));
    if (iVar2 == 0) {
      uVar1 = FUN_600afdf8(*(undefined2 *)(unaff_r7 + 6));
      *(undefined4 *)(unaff_r7 + 0x10) = uVar1;
      if (*(int *)(unaff_r7 + 0x10) == 0) {
        *(undefined1 *)(unaff_r7 + 0x1f) = 0x80;
      }
      else {
        *(undefined1 *)(*(int *)(unaff_r7 + 0x10) + 0x31) = 4;
        *(bool *)(unaff_r7 + 0xf) = *(char *)(unaff_r7 + 5) != '\0';
        FUN_600f46b4(**(undefined4 **)(unaff_r7 + 0x10),*(undefined4 *)(unaff_r7 + 0x10),
                     *(undefined1 *)(unaff_r7 + 0xf));
      }
      uVar3 = *(undefined1 *)(unaff_r7 + 0x1f);
    }
    else {
      uVar3 = 0x84;
    }
  }
  return uVar3;
}


