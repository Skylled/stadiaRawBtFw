// 600b480c  FUN_600b480c  size=102 bytes
// --- callers ---
//   600a02b4 FUN_600a02b4
// --- callees ---
//   600a9234 FUN_600a9234
//   6006dbac FUN_6006dbac


bool FUN_600b480c(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b4874,0xbdb);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 1;
    *(undefined1 *)(iVar1 + 9) = 0x10;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(param_1,iVar1);
  }
  return iVar1 != 0;
}


