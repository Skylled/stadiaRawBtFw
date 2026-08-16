// 600a7d0c  FUN_600a7d0c  size=230 bytes
// --- callers ---
//   600a7b44 FUN_600a7b44
// --- callees ---
//   600f1e84 FUN_600f1e84


char FUN_600a7d0c(int param_1)

{
  char cVar1;
  undefined1 local_11;
  
  if (((*(ushort *)(param_1 + 0x2a) & 8) == 0) && (*(short *)(param_1 + 0xc) != -1)) {
    FUN_600f1e84(param_1);
    cVar1 = '\x01';
  }
  else if (*(int *)(DAT_600a7df4 + 0x1118) == 0) {
    cVar1 = '\x04';
  }
  else {
    if (*(int *)(param_1 + 0xf0) == 0) {
      local_11 = '\0';
    }
    else {
      local_11 = *(char *)(*(int *)(param_1 + 0xf0) + 0x10);
    }
    if ((*(char *)(param_1 + 0xef) == '\0') || (local_11 != *(char *)(param_1 + 0xef))) {
      *(undefined1 *)(param_1 + 0x50) = 4;
      cVar1 = (**(code **)(DAT_600a7df4 + 0x1118))
                        (param_1 + 0x10,param_1 + 0x16,param_1 + 0x2c,0,local_11,
                         *(undefined1 *)(param_1 + 0x51));
      if (cVar1 == '\0') {
        *(ushort *)(param_1 + 0x2a) = *(ushort *)(param_1 + 0x2a) | 1;
        if (*(char *)(param_1 + 0x51) == '\0') {
          *(char *)(param_1 + 0xef) = local_11;
        }
        *(undefined1 *)(param_1 + 0x50) = 0;
      }
    }
    else {
      cVar1 = '\0';
    }
  }
  return cVar1;
}


