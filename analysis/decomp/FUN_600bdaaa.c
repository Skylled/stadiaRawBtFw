// 600bdaaa  FUN_600bdaaa  size=100 bytes
// --- callers ---
//   6013aad0 FUN_6013aad0
// --- callees ---
//   600bd848 FUN_600bd848
//   6006ddd8 FUN_6006ddd8


undefined1 FUN_600bdaaa(void)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int unaff_r7;
  undefined4 uStack00000000;
  
  while( true ) {
    uVar1 = **(undefined2 **)(unaff_r7 + 4);
    puVar3 = *(undefined1 **)(unaff_r7 + 0x20);
    *(undefined1 **)(unaff_r7 + 0x20) = puVar3 + 1;
    *puVar3 = (char)uVar1;
    if (*(int *)(unaff_r7 + 0x1c) < *(int *)(unaff_r7 + 0x20) - *(int *)(unaff_r7 + 0x18)) break;
    *(short *)(unaff_r7 + 0x26) = *(short *)(unaff_r7 + 0x26) + 1;
    *(int *)(unaff_r7 + 4) = *(int *)(unaff_r7 + 4) + 2;
    if (*(ushort *)(unaff_r7 + 8) <= *(ushort *)(unaff_r7 + 0x26)) break;
    puVar3 = *(undefined1 **)(unaff_r7 + 0x20);
    *(undefined1 **)(unaff_r7 + 0x20) = puVar3 + 1;
    *puVar3 = 0x19;
    uVar1 = **(undefined2 **)(unaff_r7 + 4);
    puVar3 = *(undefined1 **)(unaff_r7 + 0x20);
    *(undefined1 **)(unaff_r7 + 0x20) = puVar3 + 1;
    *puVar3 = (char)((ushort)uVar1 >> 8);
  }
  uStack00000000 = *(undefined4 *)(unaff_r7 + 0x18);
  uVar2 = FUN_600bd848(*(undefined4 *)(unaff_r7 + 0xc),*(undefined2 *)(unaff_r7 + 10),6,
                       *(int *)(unaff_r7 + 0x20) - *(int *)(unaff_r7 + 0x18));
  *(undefined1 *)(unaff_r7 + 0x17) = uVar2;
  FUN_6006ddd8(*(undefined4 *)(unaff_r7 + 0x18),DAT_600bdb10,0x27e);
  return *(undefined1 *)(unaff_r7 + 0x17);
}


