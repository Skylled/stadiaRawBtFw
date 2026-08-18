// 600c2810  FUN_600c2810  size=106 bytes
// --- callers ---
// --- callees ---
//   600ab88c FUN_600ab88c
//   60096378 FUN_60096378
//   600a1900 FUN_600a1900
//   60099d18 FUN_60099d18
//   600c330c FUN_600c330c
//   60096314 FUN_60096314
//   600a1d3c FUN_600a1d3c


void FUN_600c2810(void)

{
  int iVar1;
  
  FUN_60096378(0);
  FUN_600a1900(0,0,0);
  FUN_600a1d3c(0,0,0);
  FUN_600ab88c();
  FUN_600c330c();
  *(undefined1 *)(DAT_600c287c + 0x108) = 1;
  iVar1 = FUN_60099d18();
  if (iVar1 == 0) {
    *(undefined4 *)(DAT_600c287c + 0x114) = DAT_600c2880;
    FUN_60096314(DAT_600c2884,0,0x78);
  }
  else {
    *(undefined4 *)(DAT_600c287c + 0x114) = DAT_600c2888;
    FUN_60096314(DAT_600c2884,0,200);
  }
  return;
}


