// 600a08c4  FUN_600a08c4  size=758 bytes
// --- callers ---
//   600a0bc4 FUN_600a0bc4
// --- callees ---
//   600c7048 FUN_600c7048
//   600a1b68 FUN_600a1b68
//   600a5880 FUN_600a5880
//   600a1bdc FUN_600a1bdc
//   600a1c50 FUN_600a1c50


void FUN_600a08c4(char param_1,byte *param_2)

{
  if (((param_1 != '\x01') && (param_1 != '\x02')) && (param_1 == '\0')) {
    *(undefined2 *)(DAT_600a0bbc + 0xaf0) = 0x18;
    if ((*param_2 & 1) != 0) {
      *(ushort *)(DAT_600a0bbc + 0xaf0) = *(ushort *)(DAT_600a0bbc + 0xaf0) | 0xc00;
    }
    if ((*param_2 & 2) != 0) {
      *(ushort *)(DAT_600a0bbc + 0xaf0) = (ushort)DAT_600a0bc0 | *(ushort *)(DAT_600a0bbc + 0xaf0);
    }
    if (2 < *(byte *)(DAT_600a0bbc + 0x806)) {
      if ((param_2[3] & 2) == 0) {
        *(ushort *)(DAT_600a0bbc + 0xaf0) = *(ushort *)(DAT_600a0bbc + 0xaf0) | 0x1102;
      }
      if ((param_2[3] & 4) == 0) {
        *(ushort *)(DAT_600a0bbc + 0xaf0) = *(ushort *)(DAT_600a0bbc + 0xaf0) | 0x2204;
      }
      if (((param_2[3] & 2) != 0) || ((param_2[3] & 4) != 0)) {
        if (-1 < (char)param_2[4]) {
          *(ushort *)(DAT_600a0bbc + 0xaf0) = *(ushort *)(DAT_600a0bbc + 0xaf0) | 0x300;
        }
        if ((param_2[5] & 1) == 0) {
          *(ushort *)(DAT_600a0bbc + 0xaf0) = *(ushort *)(DAT_600a0bbc + 0xaf0) | 0x3000;
        }
      }
    }
    *(undefined2 *)(DAT_600a0bbc + 0xaf2) = 0;
    if ((param_2[1] & 8) != 0) {
      *(undefined2 *)(DAT_600a0bbc + 0xaf2) = 1;
      if ((param_2[1] & 0x10) != 0) {
        *(ushort *)(DAT_600a0bbc + 0xaf2) = *(ushort *)(DAT_600a0bbc + 0xaf2) | 2;
      }
      if ((param_2[1] & 0x20) != 0) {
        *(ushort *)(DAT_600a0bbc + 0xaf2) = *(ushort *)(DAT_600a0bbc + 0xaf2) | 4;
      }
    }
    if ((char)param_2[3] < '\0') {
      *(ushort *)(DAT_600a0bbc + 0xaf2) = *(ushort *)(DAT_600a0bbc + 0xaf2) | 8;
    }
    if ((param_2[4] & 1) != 0) {
      *(ushort *)(DAT_600a0bbc + 0xaf2) = *(ushort *)(DAT_600a0bbc + 0xaf2) | 0x10;
    }
    if ((param_2[4] & 2) != 0) {
      *(ushort *)(DAT_600a0bbc + 0xaf2) = *(ushort *)(DAT_600a0bbc + 0xaf2) | 0x20;
    }
    if ((*param_2 & 0x20) == 0) {
      *(ushort *)(DAT_600a0bbc + 0x640) = *(ushort *)(DAT_600a0bbc + 0x640) & 0xfffe;
    }
    else {
      *(ushort *)(DAT_600a0bbc + 0x640) = *(ushort *)(DAT_600a0bbc + 0x640) | 1;
    }
    if ((*param_2 & 0x40) == 0) {
      *(ushort *)(DAT_600a0bbc + 0x640) = *(ushort *)(DAT_600a0bbc + 0x640) & 0xfffd;
    }
    else {
      *(ushort *)(DAT_600a0bbc + 0x640) = *(ushort *)(DAT_600a0bbc + 0x640) | 2;
    }
    if ((char)*param_2 < '\0') {
      *(ushort *)(DAT_600a0bbc + 0x640) = *(ushort *)(DAT_600a0bbc + 0x640) | 4;
    }
    else {
      *(ushort *)(DAT_600a0bbc + 0x640) = *(ushort *)(DAT_600a0bbc + 0x640) & 0xfffb;
    }
    if ((param_2[1] & 1) == 0) {
      *(ushort *)(DAT_600a0bbc + 0x640) = *(ushort *)(DAT_600a0bbc + 0x640) & 0xfff7;
    }
    else {
      *(ushort *)(DAT_600a0bbc + 0x640) = *(ushort *)(DAT_600a0bbc + 0x640) | 8;
    }
    FUN_600a5880();
    if (*(char *)(DAT_600a0bbc + 0x1aba) != -1) {
      FUN_600c7048(*(undefined1 *)(DAT_600a0bbc + 0x1ab9),*(undefined1 *)(DAT_600a0bbc + 0x1aba));
    }
    if ((param_2[3] & 0x40) != 0) {
      FUN_600a1c50(1);
    }
    FUN_600a1bdc(1);
    FUN_600a1b68(1);
  }
  return;
}


