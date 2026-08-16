// 600b9740  FUN_600b9740  size=494 bytes
// --- callers ---
//   600b9408 FUN_600b9408
// --- callees ---
//   6006b98c FUN_6006b98c


undefined4 FUN_600b9740(int param_1,int param_2)

{
  uint uVar1;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  if (((*(ushort *)(DAT_600b9930 + 0x5a) < *(ushort *)(param_2 + 2)) ||
      (*(char *)(param_1 + 0x32) != '\x01')) &&
     ((*(char *)(param_1 + 0x32) != '\x02' ||
      (*(ushort *)(DAT_600b9930 + 0x5e) < *(ushort *)(param_2 + 2))))) {
    if (*(char *)(param_1 + 0x32) == '\x02') {
      local_e = *(ushort *)(DAT_600b9930 + 0x5c);
      local_c = *(ushort *)(DAT_600b9934 + 0xf4a);
    }
    else {
      local_e = *(ushort *)(DAT_600b9930 + 0x58);
      local_c = *(ushort *)(DAT_600b9934 + 2);
    }
    uVar1 = (int)((uint)local_e + (uint)*(ushort *)(param_2 + 2) + -5) / (int)(uint)local_e;
    local_a = (ushort)uVar1;
    if (*(short *)(param_1 + 0x1a) == 0) {
      local_a = 1;
      *(undefined1 *)(param_1 + 0xa2) = 1;
    }
    else {
      if ((uint)local_c < (uVar1 & 0xffff)) {
        local_a = local_c;
        *(undefined1 *)(param_1 + 0xa2) = 1;
      }
      if ((int)((uint)*(ushort *)(param_1 + 0x1a) - (uint)*(ushort *)(param_1 + 0xa0)) <
          (int)(uint)local_a) {
        local_a = *(short *)(param_1 + 0x1a) - *(short *)(param_1 + 0xa0);
        *(undefined1 *)(param_1 + 0xa2) = 1;
      }
    }
    *(ushort *)(param_2 + 6) = local_a;
    if (*(char *)(param_1 + 0x32) == '\x02') {
      *(ushort *)(DAT_600b9934 + 0xf4a) = *(short *)(DAT_600b9934 + 0xf4a) - local_a;
      if (*(short *)(param_1 + 0x1a) == 0) {
        *(ushort *)(DAT_600b9934 + 0xf52) = local_a + *(short *)(DAT_600b9934 + 0xf52);
      }
    }
    else {
      *(ushort *)(DAT_600b9934 + 2) = *(short *)(DAT_600b9934 + 2) - local_a;
      if (*(short *)(param_1 + 0x1a) == 0) {
        *(ushort *)(DAT_600b9934 + 6) = local_a + *(short *)(DAT_600b9934 + 6);
      }
    }
    *(ushort *)(param_1 + 0xa0) = local_a + *(short *)(param_1 + 0xa0);
    if (*(char *)(param_1 + 0x32) == '\x02') {
      FUN_6006b98c(param_2,0x2101);
    }
    else {
      FUN_6006b98c(param_2,0x2100);
    }
  }
  else {
    if (*(short *)(param_1 + 0x1a) == 0) {
      if (*(char *)(param_1 + 0x32) == '\x02') {
        *(short *)(DAT_600b9934 + 0xf52) = *(short *)(DAT_600b9934 + 0xf52) + 1;
      }
      else {
        *(short *)(DAT_600b9934 + 6) = *(short *)(DAT_600b9934 + 6) + 1;
      }
    }
    *(short *)(param_1 + 0xa0) = *(short *)(param_1 + 0xa0) + 1;
    *(undefined2 *)(param_2 + 6) = 0;
    if (*(char *)(param_1 + 0x32) == '\x02') {
      *(short *)(DAT_600b9934 + 0xf4a) = *(short *)(DAT_600b9934 + 0xf4a) + -1;
      FUN_6006b98c(param_2,0x2101);
    }
    else {
      *(short *)(DAT_600b9934 + 2) = *(short *)(DAT_600b9934 + 2) + -1;
      FUN_6006b98c(param_2,0x2100);
    }
  }
  return 1;
}


