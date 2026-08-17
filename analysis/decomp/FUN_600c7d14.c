// 600c7d14  FUN_600c7d14  size=74 bytes
// --- callers ---
//   600ffada FUN_600ffada
//   600c7eb8 FUN_600c7eb8
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c7d14(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x16,DAT_600c7d60,0x10d);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined1 *)(iVar1 + 0x15) = param_1;
    *(undefined2 *)(iVar1 + 2) = 1;
  }
  return iVar1;
}


