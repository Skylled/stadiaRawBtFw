// 600c4d18  FUN_600c4d18  size=134 bytes
// --- callers ---
//   600c2f68 FUN_600c2f68
// --- callees ---
//   600c2d5c FUN_600c2d5c
//   6009931c FUN_6009931c


bool FUN_600c4d18(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  byte local_a;
  
  if (*(char *)(DAT_600c4da0 + 0x244) != '\0') {
    for (local_a = 0; local_a < *(byte *)(DAT_600c4da0 + 0xe4); local_a = local_a + 1) {
      iVar2 = (uint)local_a * 0x20 + DAT_600c4da0;
      if ((*(char *)(iVar2 + 0xc) == '\x01') && ((*(byte *)(iVar2 + 0xf) & 0x20) != 0)) {
        iVar1 = FUN_6009931c(iVar2 + 4,0,DAT_600c4da4);
        if (iVar1 == 1) {
          *(undefined2 *)(DAT_600c4da0 + 0x242) = param_1;
        }
        FUN_600c2d5c(0x11,0,1,iVar2 + 4);
        return iVar1 == 1;
      }
    }
  }
  return false;
}


