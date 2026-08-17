// 600c0e14  FUN_600c0e14  size=98 bytes
// --- callers ---
// --- callees ---
//   600f0ac8 FUN_600f0ac8
//   600b1368 FUN_600b1368
//   600c04c4 FUN_600c04c4
//   600c15a8 FUN_600c15a8
//   600fc302 FUN_600fc302


void FUN_600c0e14(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x195) == '\0') {
    cVar1 = FUN_600f0ac8(param_1 + 0x1d,param_1 + 0x1d6,param_1 + 0x1d,param_1 + 0x1d6,param_2);
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 0x1f2) = 3;
      iVar2 = FUN_600b1368(DAT_600c0e78);
      if (iVar2 == 0) {
        FUN_600c15a8(0);
      }
    }
    else {
      FUN_600fc302(param_1,0);
    }
  }
  else {
    FUN_600c04c4();
  }
  return;
}


