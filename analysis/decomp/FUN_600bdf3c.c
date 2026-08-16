// 600bdf3c  FUN_600bdf3c  size=288 bytes
// --- callers ---
// --- callees ---
//   600bf2d8 FUN_600bf2d8
//   600aa340 FUN_600aa340
//   600f79a8 FUN_600f79a8


void FUN_600bdf3c(undefined2 param_1,short *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_600bf2d8(param_1);
  if (puVar1 != (undefined1 *)0x0) {
    if ((char)param_2[1] == '\0') {
      *(undefined2 *)(puVar1 + 0x20) = 0x100;
    }
    else if ((ushort)param_2[2] < 0x101) {
      *(short *)(puVar1 + 0x20) = param_2[2];
    }
    else {
      *(undefined2 *)(puVar1 + 0x20) = 0x100;
    }
    *(undefined1 *)(param_2 + 0x10) = 0;
    *(undefined1 *)(param_2 + 1) = 0;
    *param_2 = 0;
    if ((char)param_2[0x12] != '\0') {
      if ((char)param_2[0x13] == '\0') {
        *(undefined1 *)(param_2 + 0x12) = 0;
      }
      else {
        if ((*(char *)(DAT_600be05c + 0x26) != '\0') &&
           (*(byte *)(DAT_600be05c + 0x27) < *(byte *)((int)param_2 + 0x27))) {
          *(undefined1 *)((int)param_2 + 0x27) = *(undefined1 *)(DAT_600be05c + 0x27);
          *param_2 = 1;
        }
        if (*(char *)(DAT_600be05c + 0x26) == '\0') {
          *(undefined1 *)(param_2 + 0x13) = 0;
          *param_2 = 1;
        }
        if (*param_2 != 0) {
          FUN_600f79a8(param_1,param_2);
          return;
        }
      }
    }
    FUN_600f79a8(param_1,param_2);
    puVar1[1] = puVar1[1] | 2;
    if (((puVar1[1] & 4) != 0) && (*puVar1 = 3, (puVar1[1] & 1) == 0)) {
      FUN_600aa340(puVar1 + 8,5,0x1e);
    }
  }
  return;
}


