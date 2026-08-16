// 600a7870  FUN_600a7870  size=714 bytes
// --- callers ---
//   600f2ba2 FUN_600f2ba2
// --- callees ---
//   600f1746 FUN_600f1746
//   600b25c8 FUN_600b25c8
//   600a8108 FUN_600a8108
//   600b24f8 FUN_600b24f8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d168 thunk_EXT_FUN_0000b554
//   600b27e8 FUN_600b27e8


void FUN_600a7870(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_c;
  
  iVar1 = DAT_600a7b3c;
  if (*(char *)(DAT_600a7b3c + 0x118c) != '\0') {
    iVar2 = thunk_EXT_FUN_0000b554(param_1,DAT_600a7b40,6);
    if ((iVar2 == 0) && (*(char *)(DAT_600a7b3c + 0x118c) == '\t')) {
      *(undefined1 *)(DAT_600a7b3c + 0x118c) = 0;
    }
    else if ((*(char *)(DAT_600a7b3c + 0x118c) != '\x02') ||
            (iVar2 = thunk_EXT_FUN_0000b554(param_1,DAT_600a7b40,6), iVar2 != 0)) {
      FUN_600b25c8(param_1);
      return;
    }
  }
  iVar2 = FUN_600f1746(param_1);
  *(undefined1 *)(iVar2 + 0x59) = 0x10;
  if (*(char *)(DAT_600a7b3c + 0x118c) == '\0') {
    thunk_EXT_FUN_0000b572(DAT_600a7b40,param_1,6);
    *(undefined1 *)(DAT_600a7b3c + 0x118d) = 2;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      *(undefined4 *)(local_c * 4 + iVar2 + 4) = 0;
    }
  }
  if ((*(char *)(iVar1 + 0x1175) == '\0') && (*(char *)(iVar1 + 0xf9) == '\x01')) {
    FUN_600a8108(9);
    FUN_600b24f8(param_1,*(undefined1 *)(iVar1 + 0xfa),iVar1 + 0xfb);
  }
  else {
    iVar3 = thunk_EXT_FUN_0000b554(param_1,iVar1 + 0x1ab0,6);
    if ((iVar3 == 0) &&
       (((*(char *)(iVar1 + 0x1ab6) != '\0' || (*(char *)(iVar1 + 0x1ab7) != '\0')) ||
        (*(char *)(iVar1 + 0x1ab8) != '\0')))) {
      thunk_EXT_FUN_0000b572(iVar2 + 0x16,iVar1 + 0x1ab6,3);
    }
    if (*(char *)(DAT_600a7b3c + 0x117b) == '\0') {
      if (((*(char *)(iVar1 + 0x1175) == '\0') && (*(int *)(iVar1 + 0x111c) != 0)) &&
         ((*(char *)(iVar2 + 0x51) != '\0' ||
          (((*(byte *)(iVar2 + 0x17) & 0x1f) != 5 || ((*(byte *)(iVar2 + 0x18) & 0x40) == 0)))))) {
        FUN_600a8108(3);
        thunk_EXT_FUN_0000b572(iVar1 + 0x1ab0,param_1,6);
        thunk_EXT_FUN_0000b572(iVar1 + 0x1ab6,iVar2 + 0x16,3);
        if ((*(ushort *)(iVar2 + 0x2a) & 8) != 0) {
          *(byte *)(DAT_600a7b3c + 0x118d) = *(byte *)(DAT_600a7b3c + 0x118d) | 8;
          if (*(int *)(iVar1 + 0x111c) == 0) {
            return;
          }
          (**(code **)(iVar1 + 0x111c))(param_1,iVar2 + 0x16,iVar2 + 0x2c);
          return;
        }
        iVar3 = FUN_600b27e8(iVar2 + 0x10,1,0,0);
        if (iVar3 != 0) {
          return;
        }
        *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) | 8;
        *(undefined1 *)(iVar2 + 0x2c) = 0x66;
        *(undefined1 *)(iVar2 + 0x2d) = 0x30;
        *(byte *)(DAT_600a7b3c + 0x118d) = *(byte *)(DAT_600a7b3c + 0x118d) | 8;
        if (*(int *)(iVar1 + 0x111c) == 0) {
          return;
        }
        (**(code **)(iVar1 + 0x111c))(param_1,iVar2 + 0x16,iVar2 + 0x2c);
        return;
      }
      FUN_600b25c8(param_1);
    }
    else {
      FUN_600b24f8(param_1,*(undefined1 *)(DAT_600a7b3c + 0x117b),iVar1 + 0x117c);
      *(undefined1 *)(DAT_600a7b3c + 0x117b) = 0;
      FUN_600a8108(9);
    }
  }
  return;
}


