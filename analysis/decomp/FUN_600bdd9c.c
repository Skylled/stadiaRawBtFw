// 600bdd9c  FUN_600bdd9c  size=208 bytes
// --- callers ---
// --- callees ---
//   600f75c0 FUN_600f75c0
//   600f1996 FUN_600f1996
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600bdd9c(void)

{
  int iVar1;
  
  thunk_EXT_FUN_0000b5ba(DAT_600bde6c,0,0xf98);
  *(undefined1 *)(DAT_600bde6c + 2) = 1;
  *(undefined2 *)(DAT_600bde6c + 4) = 0x100;
  *(undefined1 *)(DAT_600bde6c + 0x20) = 1;
  *(undefined2 *)(DAT_600bde6c + 0x22) = 0xffff;
  *(undefined2 *)(DAT_600bde6c + 0xf90) = 0xf0;
  *(undefined2 *)(DAT_600bde6c + 0xf92) = 0x15;
  iVar1 = FUN_600f1996(0,DAT_600bde70,0,0,1,0,0);
  if (iVar1 != 0) {
    *(undefined1 *)(DAT_600bde6c + 0xf94) = *DAT_600bde74;
    *(undefined4 *)(DAT_600bde6c + 0xf64) = DAT_600bde78;
    *(undefined4 *)(DAT_600bde6c + 0xf68) = 0;
    *(undefined4 *)(DAT_600bde6c + 0xf6c) = 0;
    *(undefined4 *)(DAT_600bde6c + 0xf70) = DAT_600bde7c;
    *(undefined4 *)(DAT_600bde6c + 0xf74) = DAT_600bde80;
    *(undefined4 *)(DAT_600bde6c + 0xf78) = DAT_600bde84;
    *(undefined4 *)(DAT_600bde6c + 0xf7c) = 0;
    *(undefined4 *)(DAT_600bde6c + 0xf80) = 0;
    *(undefined4 *)(DAT_600bde6c + 0xf84) = DAT_600bde88;
    *(undefined4 *)(DAT_600bde6c + 0xf88) = 0;
    *(undefined4 *)(DAT_600bde6c + 0xf8c) = 0;
    FUN_600f75c0(1,DAT_600bde8c);
  }
  return;
}


