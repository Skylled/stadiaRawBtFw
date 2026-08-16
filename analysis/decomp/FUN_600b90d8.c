// 600b90d8  FUN_600b90d8  size=590 bytes
// --- callers ---
//   600bc00c FUN_600bc00c
//   600b6900 FUN_600b6900
//   600bbd3c FUN_600bbd3c
// --- callees ---
//   6006e06c FUN_6006e06c
//   600bcf88 FUN_600bcf88


void FUN_600b90d8(void)

{
  uint uVar1;
  int iVar2;
  ushort auStack_28 [4];
  short asStack_20 [4];
  ushort auStack_18 [4];
  int local_10;
  byte local_9;
  
  for (local_9 = 0; local_9 < 4; local_9 = local_9 + 1) {
    auStack_18[local_9] = 0;
    auStack_28[local_9] = 0;
  }
  for (local_9 = 0; local_9 < 8; local_9 = local_9 + 1) {
    local_10 = (uint)local_9 * 0x158 + DAT_600b9328;
    if (*(char *)(local_10 + 5) != '\0') {
      if (*(char *)(local_10 + 0x7e) == '\0') {
        auStack_18[2] =
             (ushort)*(byte *)(local_10 + 0xa6) + (ushort)*(byte *)(local_10 + 0xa5) + auStack_18[2]
        ;
      }
      else {
        auStack_18[*(byte *)(local_10 + 0xaa)] =
             (ushort)*(byte *)(local_10 + 0xa5) + auStack_18[*(byte *)(local_10 + 0xaa)];
        auStack_18[*(byte *)(local_10 + 0xa9)] =
             (ushort)*(byte *)(local_10 + 0xa6) + auStack_18[*(byte *)(local_10 + 0xa9)];
        if (*(char *)(local_10 + 0xac) == '\x02') {
          auStack_28[2] = *(byte *)(local_10 + 0x7f) + auStack_28[2];
        }
        if (*(char *)(local_10 + 0xab) == '\x02') {
          auStack_28[2] = *(byte *)(local_10 + 0x7f) + auStack_28[2];
        }
      }
    }
  }
  for (local_9 = 0; local_9 < 4; local_9 = local_9 + 1) {
    if (auStack_18[local_9] == 0) {
      asStack_20[local_9] = 0;
    }
    else {
      uVar1 = FUN_6006e06c(local_9);
      if (auStack_28[local_9] < uVar1) {
        iVar2 = FUN_6006e06c(local_9);
        asStack_20[local_9] =
             (short)((int)(iVar2 - (uint)auStack_28[local_9]) / (int)(uint)auStack_18[local_9]) + 1;
      }
      else {
        asStack_20[local_9] = 1;
      }
    }
  }
  for (local_9 = 0; local_9 < 8; local_9 = local_9 + 1) {
    local_10 = (uint)local_9 * 0x158 + DAT_600b9328;
    if (*(char *)(local_10 + 5) != '\0') {
      if (*(char *)(local_10 + 0x7e) == '\0') {
        *(ushort *)(local_10 + 0xa2) = asStack_20[2] * (ushort)*(byte *)(local_10 + 0xa5);
      }
      else {
        *(ushort *)(local_10 + 0xa2) =
             asStack_20[*(byte *)(local_10 + 0xaa)] * (ushort)*(byte *)(local_10 + 0xa5);
      }
      FUN_600bcf88(local_10);
    }
  }
  return;
}


