// 600b1d74  FUN_600b1d74  size=134 bytes
// --- callers ---
//   600a07b0 FUN_600a07b0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b1d74(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xe,DAT_600b1dfc,0x4a8);
  *(undefined2 *)(iVar1 + 2) = 6;
  *(undefined2 *)(iVar1 + 4) = 0;
  *(undefined1 *)(iVar1 + 8) = 0x31;
  *(undefined1 *)(iVar1 + 9) = 0x20;
  *(undefined1 *)(iVar1 + 10) = 3;
  *(undefined1 *)(iVar1 + 0xb) = param_1;
  *(undefined1 *)(iVar1 + 0xc) = param_2;
  *(undefined1 *)(iVar1 + 0xd) = param_3;
  FUN_600a9234(0,iVar1);
  return 1;
}


