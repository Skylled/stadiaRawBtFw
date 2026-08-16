// 600a6184  FUN_600a6184  size=310 bytes
// --- callers ---
//   600f2e14 FUN_600f2e14
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600a24c8 FUN_600a24c8
//   600f1746 FUN_600f1746
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f8bd4 FUN_600f8bd4
//   600a8108 FUN_600a8108


void FUN_600a6184(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  byte *local_2c;
  undefined1 auStack_24 [5];
  byte local_1f [7];
  int local_18;
  uint local_14;
  
  pbVar1 = local_1f;
  local_2c = param_1;
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    *pbVar1 = *local_2c;
    pbVar1 = pbVar1 + -1;
    local_2c = local_2c + 1;
  }
  local_1f[1] = *local_2c;
  local_1f[2] = local_2c[1];
  local_1f[3] = local_2c[2];
  local_18 = FUN_600f1746(auStack_24);
  if (*(char *)(DAT_600a62bc + 0x118c) == '\0') {
    thunk_EXT_FUN_0000b572(DAT_600a62c0,auStack_24,6);
    FUN_600a8108(8);
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      *(undefined4 *)(local_14 * 4 + local_18 + 4) = 0;
    }
    FUN_600a24c8();
  }
  FUN_600f8bd4(auStack_24);
  iVar2 = thunk_EXT_FUN_0000b554(auStack_24,DAT_600a62c4,6);
  if (iVar2 == 0) {
    thunk_EXT_FUN_0000b572(local_18 + 0x16,DAT_600a62c8,3);
  }
  if ((*(char *)(DAT_600a62bc + 0x118c) == '\b') && ((local_1f[3] & 2) != 0)) {
    *(byte *)(DAT_600a62bc + 0x118d) = *(byte *)(DAT_600a62bc + 0x118d) | 2;
  }
  *(byte *)(local_18 + 0x5a) = local_1f[1];
  *(byte *)(local_18 + 0x5b) = local_1f[3];
  if (*(int *)(DAT_600a62bc + 0x1134) != 0) {
    (**(code **)(DAT_600a62bc + 0x1134))(1,auStack_24);
  }
  return;
}


