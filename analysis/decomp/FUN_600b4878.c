// 600b4878  FUN_600b4878  size=102 bytes
// --- callers ---
//   600a02d8 FUN_600a02d8
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b4878(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b48e0,0xbef);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 2;
    *(undefined1 *)(iVar1 + 9) = 0x10;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(param_1,iVar1);
  }
  return iVar1 != 0;
}


