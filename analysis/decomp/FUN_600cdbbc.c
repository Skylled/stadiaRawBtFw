// 600cdbbc  FUN_600cdbbc  size=20 bytes
// --- callers ---
//   601020ec FUN_601020ec
//   6010244e FUN_6010244e
//   6006c4cc FUN_6006c4cc
// --- callees ---


undefined4 FUN_600cdbbc(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_600cdbd0 + 0x20);
  if (*(int *)(*DAT_600cdbd0 + 0x20) == 0) {
    iVar1 = DAT_600cdbd4;
  }
  return *(undefined4 *)(iVar1 + 0xec);
}


