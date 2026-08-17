// 6009fe40  FUN_6009fe40  size=116 bytes
// --- callers ---
//   600b8888 FUN_600b8888
// --- callees ---
//   6009ff18 FUN_6009ff18


undefined4 FUN_6009fe40(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  byte local_9;
  
  bVar1 = true;
  iVar2 = FUN_6009ff18(param_1);
  if ((iVar2 != 0) && ((*(byte *)(DAT_6009feb4 + 0x813) & 0x20) != 0)) {
    if ((*(byte *)(iVar2 + 0x37) & 0x20) != 0) {
      return 1;
    }
    for (local_9 = 0; local_9 < 8; local_9 = local_9 + 1) {
      if (*(char *)((uint)local_9 + iVar2 + 0x37) != '\0') {
        bVar1 = false;
        break;
      }
    }
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}


