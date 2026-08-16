// 6009b368  FUN_6009b368  size=582 bytes
// --- callers ---
//   600f2f9a FUN_600f2f9a
//   600f2fba FUN_600f2fba
// --- callees ---
//   6009be40 FUN_6009be40
//   6009bd70 FUN_6009bd70
//   6009ed00 FUN_6009ed00
//   600f7cea FUN_600f7cea
//   6009b290 FUN_6009b290
//   6009f644 FUN_6009f644
//   6009bf1c FUN_6009bf1c
//   6009c790 FUN_6009c790
//   600f103a FUN_600f103a


void FUN_6009b368(char *param_1,undefined4 param_2,char param_3)

{
  byte *pbVar1;
  int iVar2;
  byte *local_44;
  byte local_3c [5];
  byte local_37 [8];
  byte local_2f [8];
  byte local_27 [3];
  short local_24;
  short local_22;
  short local_20;
  char local_1e;
  byte local_1d;
  ushort local_1c;
  char local_19;
  char *local_18;
  char local_12;
  char local_11;
  
  local_12 = '\0';
  local_19 = *param_1;
  local_1c = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
  local_11 = param_1[3];
  local_37[2] = param_1[4];
  pbVar1 = local_37;
  local_44 = (byte *)(param_1 + 5);
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    *pbVar1 = *local_44;
    pbVar1 = pbVar1 + -1;
    local_44 = local_44 + 1;
  }
  local_1d = local_37[2];
  local_18 = param_1;
  if (local_19 == '\0') {
    if ((local_37[2] == 1) && ((local_3c[0] & 0xc0) == 0x40)) {
      local_1e = '\x01';
    }
    else {
      local_1e = '\0';
    }
    if ((local_1e == '\0') || ((local_37[2] & 2) != 0)) {
      local_12 = FUN_6009be40(local_3c,local_37 + 2,1);
    }
    if (param_3 != '\0') {
      pbVar1 = local_27;
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        *pbVar1 = *local_44;
        pbVar1 = pbVar1 + -1;
        local_44 = local_44 + 1;
      }
      pbVar1 = local_2f;
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        *pbVar1 = *local_44;
        pbVar1 = pbVar1 + -1;
        local_44 = local_44 + 1;
      }
    }
    if (((local_12 == '\0') && (local_11 == '\x01')) && (local_1e != '\0')) {
      FUN_6009bd70(local_3c,DAT_6009b5b0,local_18);
    }
    else {
      local_20 = (ushort)local_44[1] * 0x100 + (ushort)*local_44;
      local_22 = (ushort)local_44[3] * 0x100 + (ushort)local_44[2];
      local_24 = (ushort)local_44[5] * 0x100 + (ushort)local_44[4];
      local_1c = (ushort)(((uint)local_1c << 0x14) >> 0x14);
      FUN_6009b290(local_3c,local_1c,0,local_11,local_37[2],local_12);
      FUN_600f7cea(local_1c,local_11,local_3c,local_37[2],local_20,local_22,local_24);
      if ((param_3 != '\0') && (FUN_6009bf1c(local_3c,local_2f + 3), (local_1d & 2) != 0)) {
        FUN_600f103a(local_3c,local_37 + 3,1);
      }
    }
  }
  else {
    local_11 = -1;
    if (local_19 == '<') {
      FUN_6009f644(4,1);
    }
    else {
      FUN_6009c790(0);
      FUN_6009f644(1,1);
    }
  }
  FUN_6009ed00(local_11,local_3c,local_19);
  return;
}


