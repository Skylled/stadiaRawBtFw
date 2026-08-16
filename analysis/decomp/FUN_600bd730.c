// 600bd730  FUN_600bd730  size=270 bytes
// --- callers ---
//   600f6c4c FUN_600f6c4c
//   600bd150 FUN_600bd150
//   600ab564 FUN_600ab564
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600bd730(int param_1)

{
  undefined4 uVar1;
  int *local_14;
  ushort local_e;
  ushort local_c;
  ushort local_a;
  
  local_14 = DAT_600bd840;
  if ((param_1 == 0) || (*(short *)(DAT_600bd844 + 0x102) == 0)) {
    *(undefined2 *)(DAT_600bd844 + 0x102) = 0;
    *(undefined4 *)(DAT_600bd844 + 0xfc) = 0;
    *(undefined1 *)(DAT_600bd844 + 0x100) = 0;
    uVar1 = 1;
  }
  else {
    for (local_a = 0; local_a < *(ushort *)(DAT_600bd844 + 0x102); local_a = local_a + 1) {
      if (param_1 == *local_14) {
        for (local_c = local_a; local_c < *(ushort *)(DAT_600bd844 + 0x102); local_c = local_c + 1)
        {
          thunk_EXT_FUN_0000b572(local_14,local_14 + 0x73,0x1cc);
          for (local_e = 0; local_e < *(ushort *)(local_14 + 2); local_e = local_e + 1) {
            local_14[(uint)local_e * 3 + 4] = local_14[(uint)local_e * 3 + 4] + -0x1cc;
          }
          local_14 = local_14 + 0x73;
        }
        *(short *)(DAT_600bd844 + 0x102) = *(short *)(DAT_600bd844 + 0x102) + -1;
        if (param_1 == *(int *)(DAT_600bd844 + 0xfc)) {
          *(undefined4 *)(DAT_600bd844 + 0xfc) = 0;
          *(undefined1 *)(DAT_600bd844 + 0x100) = 0;
        }
        return 1;
      }
      local_14 = local_14 + 0x73;
    }
    uVar1 = 0;
  }
  return uVar1;
}


