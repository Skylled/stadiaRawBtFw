// 600f395a  FUN_600f395a  size=162 bytes
// --- callers ---
//   60134420 FUN_60134420
// --- callees ---
//   600ffada FUN_600ffada
//   600afd84 FUN_600afd84
//   600af7c8 FUN_600af7c8
//   600afd28 FUN_600afd28
//   600afdf8 FUN_600afdf8


undefined1 FUN_600f395a(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 in_r3;
  int unaff_r7;
  
  *(undefined2 *)(unaff_r7 + 4) = in_r3;
  *(undefined1 *)(unaff_r7 + 0x17) = 0x80;
  *(char *)(unaff_r7 + 0x16) = (char)*(undefined2 *)(unaff_r7 + 6);
  *(char *)(unaff_r7 + 0x15) = (char)((ushort)*(undefined2 *)(unaff_r7 + 6) >> 8);
  uVar2 = FUN_600af7c8(*(undefined1 *)(unaff_r7 + 0x15));
  *(undefined4 *)(unaff_r7 + 0x10) = uVar2;
  uVar2 = FUN_600afd28(*(undefined1 *)(unaff_r7 + 0x16));
  *(undefined4 *)(unaff_r7 + 0xc) = uVar2;
  if ((((*(int *)(unaff_r7 + 0x10) == 0) || (*(int *)(unaff_r7 + 0xc) == 0)) ||
      (*(ushort *)(unaff_r7 + 4) < 0x17)) || (0x205 < *(ushort *)(unaff_r7 + 4))) {
    uVar1 = 0x87;
  }
  else if (*(char *)(*(int *)(unaff_r7 + 0x10) + 0x13) == '\x02') {
    iVar3 = FUN_600afd84(*(undefined2 *)(unaff_r7 + 6));
    if (iVar3 == 0) {
      uVar2 = FUN_600afdf8(*(undefined2 *)(unaff_r7 + 6));
      *(undefined4 *)(unaff_r7 + 8) = uVar2;
      if (*(int *)(unaff_r7 + 8) != 0) {
        *(undefined2 *)(**(int **)(unaff_r7 + 8) + 0x1a) = *(undefined2 *)(unaff_r7 + 4);
        *(undefined1 *)(*(int *)(unaff_r7 + 8) + 0x31) = 5;
        uVar1 = FUN_600ffada(**(undefined4 **)(unaff_r7 + 8),
                             *(undefined2 *)(*(int *)(unaff_r7 + 8) + 0x26),2,unaff_r7 + 4);
        *(undefined1 *)(unaff_r7 + 0x17) = uVar1;
      }
      uVar1 = *(undefined1 *)(unaff_r7 + 0x17);
    }
    else {
      uVar1 = 0x84;
    }
  }
  else {
    uVar1 = 0x85;
  }
  return uVar1;
}


