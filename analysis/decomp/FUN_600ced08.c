// 600ced08  FUN_600ced08  size=40 bytes
// --- callers ---
//   600cf7b6 FUN_600cf7b6
//   600cf9c6 FUN_600cf9c6
//   600cfa22 FUN_600cfa22
//   600cf814 FUN_600cf814
// --- callees ---


void FUN_600ced08(int param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 8);
  *(byte *)(iVar2 + 0x1a) = bVar1 & 0x1f;
  iVar2 = iVar2 + (uint)bVar1 * 0x20;
  *(undefined2 *)(iVar2 + 0x101c) = 0;
  *(undefined4 *)(iVar2 + 0x1018) = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    *(undefined1 *)(param_1 + 0x11) = 0;
    *(undefined1 *)(param_1 + 0x12) = 0;
    *(undefined1 *)(param_1 + 0x13) = 0;
  }
  return;
}


