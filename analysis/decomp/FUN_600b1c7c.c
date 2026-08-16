// 600b1c7c  FUN_600b1c7c  size=110 bytes
// --- callers ---
//   6009f60c FUN_6009f60c
//   6009f5d0 FUN_6009f5d0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b1c7c(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xc,DAT_600b1cec,0x47f);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 4;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x2d;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 1;
    *(undefined1 *)(iVar1 + 0xb) = param_1;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}


