// 600c239c  FUN_600c239c  size=84 bytes
// --- callers ---
//   600c1864 FUN_600c1864
// --- callees ---
//   6006dbac FUN_6006dbac
//   600c1b20 FUN_600c1b20


void FUN_600c239c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x17,DAT_600c23f0,0x4a1);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x15) = 5;
    *(undefined1 *)(iVar1 + 0x16) = 5;
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 2;
    FUN_600c1b20(param_1,iVar1);
  }
  return;
}


