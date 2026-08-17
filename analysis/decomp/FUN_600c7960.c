// 600c7960  FUN_600c7960  size=128 bytes
// --- callers ---
//   600c7eb8 FUN_600c7eb8
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c7960(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x1a,DAT_600c79e0,0x65);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x15) = 1;
    *(undefined1 *)(iVar1 + 0x16) = param_1;
    *(char *)(iVar1 + 0x17) = (char)param_2;
    *(char *)(iVar1 + 0x18) = (char)((ushort)param_2 >> 8);
    *(undefined1 *)(iVar1 + 0x19) = param_3;
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 5;
  }
  return iVar1;
}


