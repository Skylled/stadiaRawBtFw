// 600a4984  FUN_600a4984  size=146 bytes
// --- callers ---
//   600fd0c2 FUN_600fd0c2
//   600a62cc FUN_600a62cc
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600b45b4 FUN_600b45b4
//   6009ff18 FUN_6009ff18
//   600a8108 FUN_600a8108


void FUN_600a4984(char param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((*(char *)(DAT_600a4a18 + 0x118c) == '\x04') &&
     (iVar1 = thunk_EXT_FUN_0000b554(DAT_600a4a1c,param_2,6), iVar1 == 0)) {
    FUN_600a8108(9);
    if ((param_1 == '\0') || (param_1 == '\x11')) {
      *(undefined1 *)(DAT_600a4a18 + 0x1abb) = 0;
      if (param_1 == '\0') {
        iVar1 = FUN_6009ff18(param_2);
        if (iVar1 != 0) {
          *(ushort *)(iVar1 + 0x2a) = *(ushort *)(iVar1 + 0x2a) | 0x20;
        }
      }
      FUN_600b45b4(param_2,1);
    }
    else {
      *(undefined1 *)(DAT_600a4a18 + 0x1abb) = 0xe;
      FUN_600b45b4(param_2,0);
    }
  }
  return;
}


