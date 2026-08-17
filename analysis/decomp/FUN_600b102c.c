// 600b102c  FUN_600b102c  size=96 bytes
// --- callers ---
//   600a020c FUN_600a020c
// --- callees ---
//   600a9234 FUN_600a9234
//   6006dbac FUN_6006dbac


bool FUN_600b102c(void)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b108c,0x189);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0xf;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(0,iVar1,0,(undefined1 *)(iVar1 + 10),iVar1 + 0xb);
  }
  return iVar1 != 0;
}


