// 600b5c08  FUN_600b5c08  size=456 bytes
// --- callers ---
//   600bb534 FUN_600bb534
//   600bb44c FUN_600bb44c
// --- callees ---


void FUN_600b5c08(void)

{
  ushort uVar1;
  ushort local_1a;
  ushort local_18;
  ushort local_16;
  char *local_14;
  short local_e;
  ushort local_c;
  ushort local_a;
  
  local_16 = 0;
  local_18 = 0;
  uVar1 = *(ushort *)(DAT_600b5df8 + 0xf4c);
  local_1a = 4;
  if (*(short *)(DAT_600b5df8 + 0xf40) == 0) {
    *(undefined2 *)(DAT_600b5df8 + 0xf4a) = *(undefined2 *)(DAT_600b5df8 + 0xf4c);
    *(undefined2 *)(DAT_600b5df8 + 0xf52) = 0;
    *(undefined2 *)(DAT_600b5df8 + 0xf50) = *(undefined2 *)(DAT_600b5df8 + 0xf52);
  }
  else {
    local_14 = DAT_600b5dfc;
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      if ((*local_14 != '\0') && (local_14[0x32] == '\x02')) {
        if (local_14[0x28] == '\x01') {
          local_18 = local_18 + 1;
        }
        else {
          local_16 = local_16 + 1;
        }
      }
      local_14 = local_14 + 0xa4;
    }
    for (; (int)(uint)uVar1 < (int)((uint)local_1a * (uint)local_18 + (uint)(local_16 != 0));
        local_1a = local_1a - 1) {
    }
    if ((ushort)(local_18 * local_1a) < uVar1) {
      uVar1 = uVar1 - local_18 * local_1a;
    }
    else {
      uVar1 = 1;
    }
    if (uVar1 < local_16) {
      *(ushort *)(DAT_600b5df8 + 0xf50) = uVar1;
      local_e = 0;
      local_a = 0;
    }
    else if (local_16 == 0) {
      *(undefined2 *)(DAT_600b5df8 + 0xf50) = 0;
      *(undefined2 *)(DAT_600b5df8 + 0xf52) = 0;
      local_e = 0;
      local_a = 0;
    }
    else {
      *(undefined2 *)(DAT_600b5df8 + 0xf50) = 0;
      *(undefined2 *)(DAT_600b5df8 + 0xf52) = 0;
      local_a = uVar1 / local_16;
      local_e = uVar1 - local_16 * (uVar1 / local_16);
    }
    local_14 = DAT_600b5dfc;
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      if ((*local_14 != '\0') && (local_14[0x32] == '\x02')) {
        if (local_14[0x28] == '\x01') {
          *(ushort *)(local_14 + 0x1a) = local_1a;
        }
        else {
          if ((*(short *)(local_14 + 0x1a) != 0) && (local_a == 0)) {
            *(short *)(DAT_600b5df8 + 0xf52) =
                 *(short *)(local_14 + 0xa0) + *(short *)(DAT_600b5df8 + 0xf52);
          }
          *(ushort *)(local_14 + 0x1a) = local_a;
          if (local_e != 0) {
            *(short *)(local_14 + 0x1a) = *(short *)(local_14 + 0x1a) + 1;
            local_e = local_e + -1;
          }
        }
        if (((local_14[1] == '\x04') && (*(short *)(local_14 + 0x88) != 0)) &&
           (*(ushort *)(local_14 + 0xa0) < *(ushort *)(local_14 + 0x1a))) {
          FUN_600aa340(local_14 + 0x44,2,2);
        }
      }
      local_14 = local_14 + 0xa4;
    }
  }
  return;
}


