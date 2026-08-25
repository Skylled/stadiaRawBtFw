// 600f4ff4  FUN_600f4ff4  size=150 bytes
// --- callers ---
//   601323f6 FUN_601323f6
// --- callees ---
//   600af9a0 FUN_600af9a0


undefined1 FUN_600f4ff4(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 in_r3;
  undefined1 *puVar3;
  int iVar4;
  int unaff_r7;
  
  puVar3 = *(undefined1 **)(unaff_r7 + 0x10);
  *(undefined1 **)(unaff_r7 + 0x10) = puVar3 + 1;
  *puVar3 = (char)((uint)in_r3 >> 8);
  if (*(char *)(**(int **)(unaff_r7 + 0x14) + 8) == '\0') {
    uVar1 = *(undefined2 *)(**(int **)(unaff_r7 + 0x14) + 0xe);
    puVar3 = *(undefined1 **)(unaff_r7 + 0x10);
    *(undefined1 **)(unaff_r7 + 0x10) = puVar3 + 1;
    *puVar3 = (char)uVar1;
    uVar1 = *(undefined2 *)(**(int **)(unaff_r7 + 0x14) + 0xe);
    puVar3 = *(undefined1 **)(unaff_r7 + 0x10);
    *(undefined1 **)(unaff_r7 + 0x10) = puVar3 + 1;
    *puVar3 = (char)((ushort)uVar1 >> 8);
  }
  else if (*(char *)(**(int **)(unaff_r7 + 0x14) + 8) == '\x02') {
    FUN_600af9a0(*(undefined4 *)(unaff_r7 + 0x10),
                 *(undefined4 *)(**(int **)(unaff_r7 + 0x14) + 0x10));
    *(int *)(unaff_r7 + 0x10) = *(int *)(unaff_r7 + 0x10) + 0x10;
  }
  else {
    for (iVar4 = 0; iVar4 < 0x10; iVar4 = iVar4 + 1) {
      iVar2 = **(int **)(unaff_r7 + 0x14);
      puVar3 = *(undefined1 **)(unaff_r7 + 0x10);
      *(undefined1 **)(unaff_r7 + 0x10) = puVar3 + 1;
      *puVar3 = *(undefined1 *)(iVar2 + iVar4 + 0xe);
    }
  }
  *(undefined1 *)(unaff_r7 + 0x1b) = 0;
  **(undefined2 **)(unaff_r7 + 0x34) = *(undefined2 *)(unaff_r7 + 0x1e);
  **(undefined4 **)(unaff_r7 + 4) = *(undefined4 *)(unaff_r7 + 0x10);
  return *(undefined1 *)(unaff_r7 + 0x1b);
}


