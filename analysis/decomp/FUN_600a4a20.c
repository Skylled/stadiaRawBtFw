// 600a4a20  FUN_600a4a20  size=238 bytes
// --- callers ---
//   600fd1ec FUN_600fd1ec
//   600a62cc FUN_600a62cc
//   600fd0f2 FUN_600fd0f2
// --- callees ---
//   600b4658 FUN_600b4658
//   600b4714 FUN_600b4714
//   600a8108 FUN_600a8108
//   600f1ce4 FUN_600f1ce4
//   6013d168 thunk_EXT_FUN_0000b554
//   6009ff18 FUN_6009ff18
//   600a4820 FUN_600a4820


void FUN_600a4a20(char param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  char local_11;
  
  if ((*(char *)(DAT_600a4b10 + 0x118c) != '\0') &&
     (iVar1 = thunk_EXT_FUN_0000b554(DAT_600a4b14,param_2,6), iVar1 == 0)) {
    if ((*(char *)(DAT_600a4b10 + 0x118c) == '\t') && (param_1 != '\0')) {
      iVar1 = FUN_6009ff18(param_2);
      if (iVar1 != 0) {
        *(undefined1 *)(DAT_600a4b10 + 0x1abb) = 0xe;
        if (*(short *)(iVar1 + 0xc) == -1) {
          FUN_600a4820(param_2);
        }
        else {
          FUN_600f1ce4(iVar1,5,*(undefined2 *)(iVar1 + 0xc));
        }
        *(ushort *)(iVar1 + 0x2a) = *(ushort *)(iVar1 + 0x2a) & 0xffcf;
        FUN_600a8108(0);
        return;
      }
    }
    else if (*(char *)(DAT_600a4b10 + 0x118c) != '\x05') {
      return;
    }
    local_11 = param_1;
    if (DAT_600a4b18 < param_3) {
      local_11 = '\x05';
    }
    FUN_600a8108(9);
    if (local_11 == '\0') {
      *(undefined1 *)(DAT_600a4b10 + 0x1abb) = 0;
      FUN_600b4658(param_2,param_3);
    }
    else {
      *(undefined1 *)(DAT_600a4b10 + 0x1abb) = 0xe;
      FUN_600b4714(param_2);
    }
  }
  return;
}


