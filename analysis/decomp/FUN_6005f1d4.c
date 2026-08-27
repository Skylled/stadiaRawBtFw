// 6005f1d4  FUN_6005f1d4  size=40 bytes
// --- callers ---
//   600d4772 FUN_600d4772
// --- callees ---


undefined4 FUN_6005f1d4(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_6005f1fc + 0x260);
  if (iVar2 == 0x6a0000) {
    return 0;
  }
  if (iVar2 == DAT_6005f200) {
    return 1;
  }
  if (iVar2 - 0x6c0000U < 2) {
    uVar1 = 2;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


