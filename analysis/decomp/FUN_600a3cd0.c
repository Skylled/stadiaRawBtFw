// 600a3cd0  FUN_600a3cd0  size=182 bytes
// --- callers ---
//   600a96d8 FUN_600a96d8
// --- callees ---
//   600a3c54 FUN_600a3c54


void FUN_600a3cd0(char param_1)

{
  int iVar1;
  undefined1 local_11;
  
  if (*(byte *)(DAT_600a3d88 + 0x6ec) < 4) {
    iVar1 = (uint)*(byte *)(DAT_600a3d88 + 0x6ec) * 0x24 + DAT_600a3d88;
    if (param_1 == '\0') {
      local_11 = 5;
    }
    else {
      *(undefined1 *)(iVar1 + 0x66c) = *(undefined1 *)(iVar1 + 0x66d);
      local_11 = 6;
    }
    if ((*(char *)(DAT_600a3d88 + 0x6ed) != -0x80) &&
       ((*(byte *)((*(byte *)(DAT_600a3d88 + 0x6ed) + 0xdb) * 8 + DAT_600a3d88 + 8) & 2) != 0)) {
      (**(code **)((*(byte *)(DAT_600a3d88 + 0x6ed) + 0xdb) * 8 + DAT_600a3d88 + 4))
                ((uint)*(byte *)(DAT_600a3d88 + 0x6ec) * 0x14c + DAT_600a3d88 + 0x116,local_11,0,
                 param_1);
    }
    *(undefined1 *)(DAT_600a3d88 + 0x6ec) = 4;
    FUN_600a3c54();
  }
  return;
}


