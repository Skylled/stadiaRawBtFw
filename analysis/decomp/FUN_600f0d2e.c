// 600f0d2e  FUN_600f0d2e  size=320 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f7cea FUN_600f7cea
//   6009b290 FUN_6009b290


void FUN_600f0d2e(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  undefined1 auStack_2c [5];
  byte local_27;
  short local_26;
  short local_24;
  short local_22;
  undefined1 local_20;
  undefined1 local_1f;
  ushort local_1e;
  int local_1c;
  undefined1 local_15;
  byte *local_14;
  
  local_15 = 0;
  bVar1 = *(byte *)(param_2 + 1);
  bVar2 = *(byte *)(param_2 + 2);
  local_1f = *(undefined1 *)(param_2 + 3);
  local_20 = *(undefined1 *)(param_2 + 4);
  pbVar3 = &local_27;
  local_14 = (byte *)(param_2 + 5);
  for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
    *pbVar3 = *local_14;
    pbVar3 = pbVar3 + -1;
    local_14 = local_14 + 1;
  }
  local_22 = (ushort)local_14[1] * 0x100 + (ushort)*local_14;
  local_24 = (ushort)local_14[3] * 0x100 + (ushort)local_14[2];
  local_26 = (ushort)local_14[5] * 0x100 + (ushort)local_14[4];
  local_14 = local_14 + 6;
  local_1e = (ushort)(((uint)(ushort)((ushort)bVar2 * 0x100 + (ushort)bVar1) << 0x14) >> 0x14);
  local_1c = param_1;
  if (param_1 != 0) {
    local_15 = 1;
    *(undefined1 *)(param_1 + 0x7a) = 1;
    thunk_EXT_FUN_0000b572(param_1 + 0x74,auStack_2c,6);
    thunk_EXT_FUN_0000b572(auStack_2c,local_1c + 0x10,6);
  }
  FUN_6009b290(auStack_2c,local_1e,0,local_1f,local_20,local_15);
  FUN_600f7cea(local_1e,local_1f,auStack_2c,local_20,local_22,local_24,local_26);
  return;
}


