// 600a337c  FUN_600a337c  size=164 bytes
// --- callers ---
//   60093478 FUN_60093478
//   60093500 FUN_60093500
// --- callees ---


undefined4 FUN_600a337c(byte param_1,byte *param_2,int param_3)

{
  undefined4 uVar1;
  int local_c;
  
  if ((param_1 & 4) == 0) {
    for (local_c = 0; local_c < 1; local_c = local_c + 1) {
      if (*(char *)((local_c + 0xdb) * 8 + DAT_600a3420 + 8) == '\0') {
        if ((param_1 & 2) != 0) {
          if (param_3 == 0) {
            return 5;
          }
          *(int *)((local_c + 0xdb) * 8 + DAT_600a3420 + 4) = param_3;
        }
        *(byte *)((local_c + 0xdb) * 8 + DAT_600a3420 + 8) = param_1;
        *param_2 = (byte)local_c;
        return 0;
      }
    }
    uVar1 = 3;
  }
  else if (*param_2 == 0) {
    *(undefined1 *)((*param_2 + 0xdb) * 8 + DAT_600a3420 + 8) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}


