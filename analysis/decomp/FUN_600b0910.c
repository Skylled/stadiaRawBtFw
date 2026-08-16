// 600b0910  FUN_600b0910  size=94 bytes
// --- callers ---
//   600a0244 FUN_600a0244
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b0910(void)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b0970,0x4e);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 3;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(0,iVar1,0,(undefined1 *)(iVar1 + 10),iVar1 + 0xb);
  }
  return iVar1 != 0;
}


