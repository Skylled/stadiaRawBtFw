// 600bce60  FUN_600bce60  size=292 bytes
// --- callers ---
//   600f9906 FUN_600f9906
//   600bcca8 FUN_600bcca8
//   600b7674 FUN_600b7674
// --- callees ---


void FUN_600bce60(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)((uint)*(ushort *)(param_1 + 4) + param_1 + 4);
  *puVar2 = (char)*(undefined2 *)(*(int *)(param_2 + 300) + 2);
  puVar1 = puVar2 + 2;
  puVar2[1] = (byte)((ushort)*(undefined2 *)(*(int *)(param_2 + 300) + 2) >> 8) | 0x20;
  if (*(char *)(*(int *)(param_2 + 300) + 0x32) == '\x02') {
    if (*(ushort *)(DAT_600bcf84 + 0x5c) < *(ushort *)(param_1 + 2)) {
      *puVar1 = (char)*(undefined2 *)(DAT_600bcf84 + 0x5c);
      puVar2[3] = (char)((ushort)*(undefined2 *)(DAT_600bcf84 + 0x5c) >> 8);
    }
    else {
      *puVar1 = (char)*(undefined2 *)(param_1 + 2);
      puVar2[3] = (char)((ushort)*(undefined2 *)(param_1 + 2) >> 8);
    }
  }
  else if (*(ushort *)(DAT_600bcf84 + 0x58) < *(ushort *)(param_1 + 2)) {
    *puVar1 = (char)*(undefined2 *)(DAT_600bcf84 + 0x58);
    puVar2[3] = (char)((ushort)*(undefined2 *)(DAT_600bcf84 + 0x58) >> 8);
  }
  else {
    *puVar1 = (char)*(undefined2 *)(param_1 + 2);
    puVar2[3] = (char)((ushort)*(undefined2 *)(param_1 + 2) >> 8);
  }
  *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + -4;
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 4;
  return;
}


