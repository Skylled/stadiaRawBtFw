// 60098a24  FUN_60098a24  size=324 bytes
// --- callers ---
//   60098b70 FUN_60098b70
//   600988d0 FUN_600988d0
// --- callees ---
//   600a1394 FUN_600a1394
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_60098a24(void)

{
  char local_11c;
  undefined1 local_11b;
  undefined1 local_11a;
  undefined1 local_119;
  undefined1 auStack_118 [258];
  short local_16;
  byte *local_14;
  int local_10;
  uint local_c;
  
  local_10 = *(int *)(DAT_60098b68 + 0x10);
  if (DAT_60098b68[0x1c] == '\x01') {
    local_14 = (byte *)(local_10 + *(int *)(DAT_60098b68 + 0xc));
    local_16 = (ushort)local_14[1] * 0x100 + (ushort)*local_14;
    local_c = (uint)local_14[2];
    local_14 = local_14 + 3;
    FUN_600a1394(local_16,local_c,local_14,DAT_60098b6c);
    *(uint *)(DAT_60098b68 + 0x10) = local_c + *(int *)(DAT_60098b68 + 0x10) + 3;
    if (local_16 == -0x3b2) {
      *DAT_60098b68 = 5;
    }
  }
  else {
    local_c = *(int *)(DAT_60098b68 + 8) - *(int *)(DAT_60098b68 + 0x10);
    if (0xfa < local_c) {
      local_c = 0xfa;
    }
    local_11c = (char)local_10 + (char)*(undefined4 *)(DAT_60098b68 + 0x18);
    local_11b = (undefined1)((uint)(local_10 + *(int *)(DAT_60098b68 + 0x18)) >> 8);
    local_11a = (undefined1)((uint)(local_10 + *(int *)(DAT_60098b68 + 0x18)) >> 0x10);
    local_119 = (undefined1)((uint)(local_10 + *(int *)(DAT_60098b68 + 0x18)) >> 0x18);
    thunk_EXT_FUN_0000b572(auStack_118,*(int *)(DAT_60098b68 + 0xc) + local_10,local_c);
    FUN_600a1394(0xfc4c,(local_c & 0xff) + 4 & 0xff,&local_11c,DAT_60098b6c);
    *(uint *)(DAT_60098b68 + 0x10) = local_c + *(int *)(DAT_60098b68 + 0x10);
  }
  return;
}


