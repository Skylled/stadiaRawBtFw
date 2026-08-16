// 600c8454  FUN_600c8454  size=438 bytes
// --- callers ---
//   600c0ac4 FUN_600c0ac4
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600c8454(undefined4 param_1,byte param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  byte local_15;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  byte local_9;
  
  if (param_2 == 0x20) {
    local_15 = 0x20;
LAB_600c849e:
    thunk_EXT_FUN_0000b572(param_3,param_1,local_15);
    *(byte *)(param_3 + 0xf0) = ((local_15 + 0x1c & 0x3f) >> 2) - 1;
    local_a = 1;
    for (local_9 = local_15; local_9 < (byte)((local_15 + 0x1c) * '\x04'); local_9 = local_9 + 4) {
      local_b = *(byte *)(param_3 + (local_9 - 4));
      local_c = *(byte *)(param_3 + (local_9 - 3));
      local_d = *(byte *)(param_3 + (local_9 - 2));
      local_e = *(byte *)(param_3 + (local_9 - 1));
      if (((uint)local_9 - (uint)local_15 * ((uint)local_9 / (uint)local_15) & 0xff) == 0) {
        bVar1 = local_a ^ *(byte *)(DAT_600c860c + (uint)local_c);
        local_c = *(byte *)(DAT_600c860c + (uint)local_d);
        local_d = *(byte *)(DAT_600c860c + (uint)local_e);
        local_e = *(byte *)(DAT_600c860c + (uint)local_b);
        local_a = ((char)local_a >> 7) * -0x1b ^ local_a << 1;
        local_b = bVar1;
      }
      else if ((0x18 < local_15) &&
              (((uint)local_9 - (uint)local_15 * ((uint)local_9 / (uint)local_15) & 0xff) == 0x10))
      {
        local_b = *(byte *)(DAT_600c860c + (uint)local_b);
        local_c = *(byte *)(DAT_600c860c + (uint)local_c);
        local_d = *(byte *)(DAT_600c860c + (uint)local_d);
        local_e = *(byte *)(DAT_600c860c + (uint)local_e);
      }
      bVar1 = local_9 - local_15;
      *(byte *)(param_3 + (uint)local_9) = local_b ^ *(byte *)(param_3 + (uint)bVar1);
      *(byte *)(param_3 + local_9 + 1) = local_c ^ *(byte *)(param_3 + bVar1 + 1);
      *(byte *)(param_3 + local_9 + 2) = local_d ^ *(byte *)(param_3 + bVar1 + 2);
      *(byte *)(param_3 + local_9 + 3) = local_e ^ *(byte *)(param_3 + bVar1 + 3);
    }
    uVar2 = 0;
  }
  else {
    if (param_2 < 0x21) {
      if (param_2 == 0x10) {
LAB_600c8480:
        local_15 = 0x10;
        goto LAB_600c849e;
      }
      if (param_2 == 0x18) {
LAB_600c8486:
        local_15 = 0x18;
        goto LAB_600c849e;
      }
    }
    else {
      if (param_2 == 0x80) goto LAB_600c8480;
      if (param_2 == 0xc0) goto LAB_600c8486;
    }
    *(undefined1 *)(param_3 + 0xf0) = 0;
    uVar2 = 0xff;
  }
  return uVar2;
}


