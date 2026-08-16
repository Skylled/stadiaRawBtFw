// 600b4548  FUN_600b4548  size=102 bytes
// --- callers ---
//   600ff862 FUN_600ff862
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b4548(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b45b0,0xa65);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0xc;
    *(undefined1 *)(iVar1 + 9) = 0x14;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(param_1,iVar1);
  }
  return iVar1 != 0;
}


