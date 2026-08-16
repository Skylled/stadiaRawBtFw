// 600a0e88  FUN_600a0e88  size=236 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a0cac FUN_600a0cac
//   600f1786 FUN_600f1786
//   600aa3cc FUN_600aa3cc
//   600a031c FUN_600a031c


void FUN_600a0e88(char *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *local_1c;
  
  FUN_600aa3cc(DAT_600a0f74);
  if (*param_1 == '\0') {
    bVar1 = param_1[1];
    bVar2 = param_1[2];
    if (bVar1 < 3) {
      local_1c = param_1 + 3;
      for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
        *(char *)((bVar1 + 0x102) * 8 + DAT_600a0f78 + 3 + iVar3) = *local_1c;
        local_1c = local_1c + 1;
      }
      if ((bVar1 == 1) && (*(char *)(DAT_600a0f78 + 0x88e) == '\x01')) {
        *(byte *)(DAT_600a0f78 + 0x88e) = *(byte *)(DAT_600a0f78 + 0x88e) & 0xfe;
        FUN_600a0cac();
      }
      else if ((bVar1 == 1) && (*(char *)(DAT_600a0f78 + 0x88e) == '\x10')) {
        *(byte *)(DAT_600a0f78 + 0x88e) = *(byte *)(DAT_600a0f78 + 0x88e) & 0xef;
      }
      else if ((bVar1 == bVar2) || (bVar1 == 2)) {
        FUN_600f1786(bVar1);
      }
      else {
        FUN_600a031c(bVar1 + 1);
      }
    }
  }
  else {
    FUN_600f1786(0);
  }
  return;
}


