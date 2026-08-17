// 600c0e7c  FUN_600c0e7c  size=84 bytes
// --- callers ---
// --- callees ---
//   600fbdd0 FUN_600fbdd0
//   600b1368 FUN_600b1368
//   600c15a8 FUN_600c15a8
//   600f0ac8 FUN_600f0ac8


void FUN_600c0e7c(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_600f0ac8(param_1 + 0x1d,param_1 + 0x1d6,param_1 + 0x1d,param_1 + 0x1d6,param_2);
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x1f2) = 4;
    iVar2 = FUN_600b1368(DAT_600c0ed0);
    if (iVar2 == 0) {
      FUN_600c15a8(0);
    }
  }
  else {
    FUN_600fbdd0(param_1,0);
  }
  return;
}


