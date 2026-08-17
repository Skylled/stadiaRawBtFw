// 6009e70c  FUN_6009e70c  size=82 bytes
// --- callers ---
//   600a2ab0 FUN_600a2ab0
//   6009e4d0 FUN_6009e4d0
//   600a1efc FUN_600a1efc
// --- callees ---
//   600a2f3c FUN_600a2f3c
//   600f1592 FUN_600f1592
//   600aa3cc FUN_600aa3cc


void FUN_6009e70c(void)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_6009e764;
  iVar1 = DAT_6009e760;
  FUN_600aa3cc(DAT_6009e760 + 0x48);
  *pbVar2 = *pbVar2 & 0xcf;
  if ((*pbVar2 & 0xf0) == 0) {
    FUN_600f1592();
  }
  FUN_600a2f3c(0,*(byte *)(iVar1 + 0x608) & 0x30);
  return;
}


