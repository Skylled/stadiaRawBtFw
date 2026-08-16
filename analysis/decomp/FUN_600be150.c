// 600be150  FUN_600be150  size=1026 bytes
// --- callers ---
//   600fa5c6 FUN_600fa5c6
// --- callees ---
//   600bf6a0 FUN_600bf6a0
//   600bd4bc FUN_600bd4bc
//   6006dcdc FUN_6006dcdc
//   600fa6bc FUN_600fa6bc
//   600bf5a4 FUN_600bf5a4
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f7b26 FUN_600f7b26


void FUN_600be150(undefined4 param_1,int param_2,undefined2 param_3,undefined2 param_4,
                 undefined4 param_5)

{
  undefined1 *puVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 auStack_178 [8];
  short local_158 [145];
  short local_36;
  undefined1 *local_34;
  undefined1 *local_30;
  int local_2c;
  char local_25;
  undefined4 *local_24;
  ushort local_20;
  ushort local_1e;
  undefined1 *local_1c;
  ushort local_18;
  ushort local_16;
  ushort local_14;
  ushort local_12;
  
  thunk_EXT_FUN_0000b5ba(auStack_178,0,0x20);
  local_24 = (undefined4 *)0x0;
  local_25 = '\0';
  pbVar2 = (byte *)FUN_600bf6a0(param_5,param_4,local_158);
  if ((pbVar2 == (byte *)0x0) || (local_158[0] == 0)) {
    FUN_600bf5a4(param_2,param_3,3,0);
    return;
  }
  local_12 = (ushort)pbVar2[1] + (ushort)*pbVar2 * 0x100;
  if (8 < local_12) {
    local_12 = 8;
  }
  local_1e = 0;
  while ((local_1e < local_12 &&
         (local_24 = (undefined4 *)FUN_600bd4bc(local_24,local_158), local_24 != (undefined4 *)0x0))
        ) {
    uVar4 = (uint)local_1e;
    local_1e = local_1e + 1;
    auStack_178[uVar4] = *local_24;
  }
  if (pbVar2[2] == 0) {
    local_16 = local_1e;
    local_18 = 0;
    FUN_600fa6bc(param_2);
  }
  else {
    if (pbVar2[2] != 2) {
      FUN_600bf5a4(param_2,param_3,5,0);
      return;
    }
    local_18 = (ushort)pbVar2[4] + (ushort)pbVar2[3] * 0x100;
    if (local_18 != *(ushort *)(param_2 + 0x2c)) {
      FUN_600bf5a4(param_2,param_3,5,0);
      return;
    }
    local_16 = local_1e - local_18;
  }
  iVar5 = *(ushort *)(param_2 + 0x20) - 0xc;
  if (iVar5 < 0) {
    iVar5 = *(ushort *)(param_2 + 0x20) - 9;
  }
  local_14 = (ushort)(iVar5 >> 2);
  if (local_14 < local_16) {
    *(ushort *)(param_2 + 0x2c) = local_14 + *(short *)(param_2 + 0x2c);
    local_25 = '\x01';
  }
  else {
    local_14 = local_16;
  }
  local_2c = FUN_6006dcdc(3,DAT_600be554,0x100);
  if (local_2c != 0) {
    *(undefined2 *)(local_2c + 4) = 0xd;
    local_30 = (undefined1 *)(local_2c + 0x15);
    *local_30 = 3;
    *(char *)(local_2c + 0x16) = (char)((ushort)param_3 >> 8);
    local_34 = (undefined1 *)(local_2c + 0x18);
    *(char *)(local_2c + 0x17) = (char)param_3;
    *(char *)(local_2c + 0x1a) = (char)(local_1e >> 8);
    *(char *)(local_2c + 0x1b) = (char)local_1e;
    *(char *)(local_2c + 0x1c) = (char)(local_14 >> 8);
    local_1c = (undefined1 *)(local_2c + 0x1e);
    *(char *)(local_2c + 0x1d) = (char)local_14;
    for (local_20 = local_18; puVar1 = local_1c, (uint)local_20 < (uint)local_14 + (uint)local_18;
        local_20 = local_20 + 1) {
      puVar3 = local_1c + 1;
      local_1c = puVar3;
      *puVar1 = (char)((uint)auStack_178[local_20] >> 0x18);
      local_1c = puVar1 + 2;
      *puVar3 = (char)((uint)auStack_178[local_20] >> 0x10);
      local_1c = puVar1 + 3;
      puVar1[2] = (char)((uint)auStack_178[local_20] >> 8);
      local_1c = puVar1 + 4;
      puVar1[3] = (char)auStack_178[local_20];
    }
    if (local_25 == '\0') {
      *local_1c = 0;
      local_1c = local_1c + 1;
    }
    else {
      *local_1c = 2;
      local_1c[1] = (char)((ushort)*(undefined2 *)(param_2 + 0x2c) >> 8);
      local_1c[2] = (char)*(undefined2 *)(param_2 + 0x2c);
      local_1c = local_1c + 3;
    }
    local_36 = ((short)local_1c - (short)local_34) + -2;
    *local_34 = (char)((ushort)local_36 >> 8);
    local_34 = (undefined1 *)(local_2c + 0x1a);
    *(char *)(local_2c + 0x19) = (char)local_36;
    *(short *)(local_2c + 2) = (short)local_1c - (short)local_30;
    FUN_600f7b26(*(undefined2 *)(param_2 + 0x22),local_2c);
  }
  return;
}


