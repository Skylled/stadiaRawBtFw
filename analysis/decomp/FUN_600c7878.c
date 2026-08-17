// 600c7878  FUN_600c7878  size=106 bytes
// --- callers ---
//   600ffada FUN_600ffada
//   600c7eb8 FUN_600c7eb8
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c7878(undefined1 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x18,DAT_600c78e4,0x27);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x15) = param_1;
    *(char *)(iVar1 + 0x16) = (char)param_2;
    *(char *)(iVar1 + 0x17) = (char)((ushort)param_2 >> 8);
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 3;
  }
  return iVar1;
}


