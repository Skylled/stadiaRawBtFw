// 60093a30  FUN_60093a30  size=734 bytes
// --- callers ---
// --- callees ---
//   600944c0 FUN_600944c0
//   60093810 FUN_60093810
//   600f0252 FUN_600f0252
//   60093d20 FUN_60093d20
//   600efcfe FUN_600efcfe
//   600a12a4 FUN_600a12a4
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600efcc6 FUN_600efcc6


void FUN_60093a30(byte param_1,byte param_2,byte param_3,undefined4 param_4)

{
  int iVar1;
  byte local_1c [6];
  short local_16;
  ushort local_12;
  int local_10;
  char local_b;
  byte local_a;
  byte local_9;
  
  local_b = FUN_600a12a4(local_1c);
  if (((local_b == '\0') && (local_16 == 0xf)) && (local_1c[0] < 3)) {
    if (param_1 == 4) {
      local_12 = *(ushort *)(DAT_60093d10 + 0x240) & 0xb;
      FUN_600f0252(param_4,&local_12);
    }
    else if (param_1 == 5) {
      local_12 = *(ushort *)(DAT_60093d10 + 0x240);
      FUN_600f0252(param_4,&local_12);
    }
  }
  local_9 = 1;
  while ((local_9 <= *(byte *)(*DAT_60093d14 + 1) &&
         ((param_2 != *(byte *)((uint)local_9 * 3 + *DAT_60093d14) ||
          ((*(char *)((uint)local_9 * 3 + *DAT_60093d14 + 1) != -1 &&
           (param_3 != *(byte *)((uint)local_9 * 3 + *DAT_60093d14 + 1)))))))) {
    local_9 = local_9 + 1;
  }
  if (local_9 <= *(byte *)(*DAT_60093d14 + 1)) {
    FUN_60093810(param_4,param_2,param_3);
    local_10 = FUN_600944c0(param_4);
    if (*(char *)((uint)param_1 * 8 +
                  *DAT_60093d18 + (uint)*(byte *)((uint)local_9 * 3 + *DAT_60093d14 + 2) * 0x4a + 2)
        != '\0') {
      for (local_a = 0; local_a < *DAT_60093d1c; local_a = local_a + 1) {
        if (((param_2 == DAT_60093d1c[(uint)local_a * 10 + 7]) &&
            (param_3 == DAT_60093d1c[(uint)local_a * 10 + 8])) &&
           (iVar1 = FUN_600efcfe(DAT_60093d1c + (uint)local_a * 10 + 1,param_4), iVar1 == 0)) {
          DAT_60093d1c[(uint)local_a * 10 + 10] = 1;
          break;
        }
      }
      if (*(char *)((uint)param_1 * 8 +
                    *DAT_60093d18 + (uint)*(byte *)((uint)local_9 * 3 + *DAT_60093d14 + 2) * 0x4a +
                   2) == '\x01') {
        if (local_a == *DAT_60093d1c) {
          return;
        }
        *DAT_60093d1c = *DAT_60093d1c - 1;
        for (; local_a < *DAT_60093d1c; local_a = local_a + 1) {
          thunk_EXT_FUN_0000b572
                    (DAT_60093d1c + (uint)local_a * 10 + 1,DAT_60093d1c + (local_a + 1) * 10 + 1,10)
          ;
        }
      }
      else if (local_a == *DAT_60093d1c) {
        if (*DAT_60093d1c == 10) {
          return;
        }
        DAT_60093d1c[(uint)local_a * 10 + 7] = param_2;
        DAT_60093d1c[(uint)local_a * 10 + 8] = param_3;
        DAT_60093d1c[(uint)local_a * 10 + 10] = 1;
        FUN_600efcc6(DAT_60093d1c + (uint)local_a * 10 + 1,param_4);
        *DAT_60093d1c = *DAT_60093d1c + 1;
        DAT_60093d1c[(uint)local_a * 10 + 9] = param_1;
      }
      else {
        DAT_60093d1c[(uint)local_a * 10 + 9] = param_1;
      }
      if (local_10 != 0) {
        *(undefined1 *)(local_10 + 0x18) = 0;
        *(undefined1 *)(local_10 + 0x19) = 0;
      }
      FUN_60093d20(param_4,0,2);
    }
  }
  return;
}


