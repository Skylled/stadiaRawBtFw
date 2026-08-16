// 60093d20  FUN_60093d20  size=1164 bytes
// --- callers ---
//   600ee438 FUN_600ee438
//   600ee33e FUN_600ee33e
//   60093a30 FUN_60093a30
// --- callees ---
//   6009633c FUN_6009633c
//   60095d9c FUN_60095d9c
//   600efcfe FUN_600efcfe
//   60096358 FUN_60096358
//   60093988 FUN_60093988
//   600efcc6 FUN_600efcc6
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ee304 FUN_600ee304
//   600941c4 FUN_600941c4
//   600944c0 FUN_600944c0
//   600942d4 FUN_600942d4
//   60094208 FUN_60094208


void FUN_60093d20(undefined4 param_1,byte param_2,char param_3)

{
  int iVar1;
  undefined1 auStack_48 [6];
  undefined1 local_42;
  int local_40;
  byte *local_3c;
  byte *local_38;
  byte *local_34;
  int local_30;
  byte local_29;
  uint local_28;
  int local_24;
  byte local_1f;
  byte local_1e;
  char local_1d;
  byte *local_1c;
  byte local_18;
  byte local_17;
  byte local_16;
  byte local_15;
  ushort local_14;
  byte local_11;
  
  local_11 = 0;
  local_14 = 0;
  local_1f = 0;
  local_24 = 0;
  local_17 = 0;
  local_18 = 0;
  local_1c = (byte *)0x0;
  local_1d = '\0';
  local_1e = 3;
  local_28 = 0;
  if ((*(char *)(DAT_60094044 + 0xe4) != '\0') && (local_24 = FUN_600944c0(param_1), local_24 != 0))
  {
    local_1f = *(byte *)(local_24 + 0x19);
    for (local_15 = 0; local_15 < *DAT_60094048; local_15 = local_15 + 1) {
      local_1c = DAT_60094048 + (uint)local_15 * 10 + 1;
      iVar1 = FUN_600efcfe(local_1c,param_1);
      if (iVar1 == 0) {
        local_16 = 1;
        while ((local_16 <= *(byte *)(*DAT_6009404c + 1) &&
               ((*(byte *)((uint)local_16 * 3 + *DAT_6009404c) != local_1c[6] ||
                ((*(char *)((uint)local_16 * 3 + *DAT_6009404c + 1) != -1 &&
                 (*(byte *)((uint)local_16 * 3 + *DAT_6009404c + 1) != local_1c[7]))))))) {
          local_16 = local_16 + 1;
        }
        local_30 = (uint)local_16 * 3 + *DAT_6009404c;
        local_34 = (byte *)((uint)*(byte *)(local_30 + 2) * 0x4a + *DAT_60094050);
        local_38 = local_34 + (uint)local_1c[8] * 8 + 2;
        local_3c = local_34 + (uint)local_1c[8] * 8 + 6;
        local_17 = local_17 | *local_34;
        if ((local_1f & *local_38) == 0) {
          local_18 = local_18 | *local_38;
          if ((local_11 < *local_38) && ((param_3 != '\x02' || (local_1c[9] != 0)))) {
            local_11 = *local_38;
            local_1c[9] = 0;
            local_14 = *(ushort *)(local_34 + (uint)local_1c[8] * 8 + 4);
          }
        }
        else if (((local_1f & *local_3c) == 0) &&
                (local_18 = local_18 | *local_3c, local_11 < *local_3c)) {
          local_11 = *local_3c;
          local_14 = *(ushort *)(local_34 + (uint)local_1c[8] * 8 + 8);
        }
      }
    }
    if ((((local_11 & 0x30) != 0) && ((local_11 & local_17) == 0)) &&
       (local_11 = local_18 & local_17 & 0x30, local_11 == 0)) {
      local_14 = 0;
    }
    if ((param_3 == '\x03') || (local_14 == 0)) {
      if (((param_3 != '\x03') || (local_11 <= param_2)) && (local_11 != 0)) {
        if (local_11 == 0x10) {
          *(undefined1 *)(local_24 + 0x18) = 0x10;
          FUN_600941c4(param_1);
        }
        else if (local_11 == 4) {
          thunk_EXT_FUN_0000b572(auStack_48,param_1,6);
          local_42 = *(undefined1 *)(DAT_600941c0 + 0x124);
          local_40 = local_24;
          FUN_60095d9c(3,auStack_48);
        }
        else if ((local_11 & 0x20) == 0) {
          if (local_11 == 0x40) {
            FUN_600942d4(param_1);
          }
        }
        else {
          *(undefined1 *)(local_24 + 0x18) = 0x20;
          FUN_60094208(local_24,local_11 & 0xf);
        }
      }
    }
    else {
      for (local_15 = 0; local_15 < 3; local_15 = local_15 + 1) {
        if ((*(char *)((uint)local_15 * 0x5c + DAT_60094044 + 0x180) != '\0') &&
           (iVar1 = FUN_600efcfe((uint)local_15 * 0x5c + DAT_60094044 + 0x17a,param_1), iVar1 == 0))
        {
          local_29 = FUN_600ee304(local_11);
          if (local_29 != 3) {
            local_28 = FUN_60096358((uint)local_29 * 0x18 + (uint)local_15 * 0x5c + 0x128 +
                                    DAT_60094044);
            if (local_28 < local_14) {
              FUN_6009633c((uint)local_29 * 0x18 + (uint)local_15 * 0x5c + 0x128 + DAT_60094044);
              FUN_60093988((uint)local_15 * 0x5c + 0x128 + DAT_60094044,local_29,local_14,
                           local_1c[6],local_11,local_1c[7]);
            }
            local_1d = '\x01';
          }
          break;
        }
        if ((*(char *)((uint)local_15 * 0x5c + DAT_600941c0 + 0x180) == '\0') && (local_1e == 3)) {
          local_1e = local_15;
        }
      }
      if ((local_1d == '\0') && (local_1e != 3)) {
        FUN_600efcc6((uint)local_1e * 0x5c + DAT_600941c0 + 0x17a,param_1);
        local_29 = FUN_600ee304(local_11);
        if (local_29 != '\x03') {
          FUN_60093988((uint)local_1e * 0x5c + 0x128 + DAT_600941c0,local_29,local_14,local_1c[6],
                       local_11,local_1c[7]);
        }
      }
    }
  }
  return;
}


