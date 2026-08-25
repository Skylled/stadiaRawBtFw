// 600fb346  FUN_600fb346  size=184 bytes
// --- callers ---
// --- callees ---
//   600fa7de FUN_600fa7de
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ad00 FUN_6009ad00
//   600fb848 FUN_600fb848


void FUN_600fb346(int param_1,byte *param_2)

{
  int iVar1;
  undefined1 auStack_30 [16];
  byte local_20 [8];
  short local_18;
  undefined1 local_16;
  undefined1 local_15;
  byte *local_14;
  
  local_14 = param_2;
  FUN_600fa7de(param_1,1,1);
  local_18 = (ushort)local_14[1] * 0x100 + (ushort)*local_14;
  local_14 = local_14 + 2;
  for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
    local_20[iVar1] = *local_14;
    local_14 = local_14 + 1;
  }
  thunk_EXT_FUN_0000b572(auStack_30,param_1 + 0x1c6,0x10);
  local_16 = *(undefined1 *)(param_1 + 0x2b);
  local_15 = *(undefined1 *)(param_1 + 0x1b1);
  if (((*(byte *)(param_1 + 0x191) & 1) != 0) && ((*(byte *)(param_1 + 0x192) & 1) != 0)) {
    FUN_6009ad00(param_1 + 0x1d,1,auStack_30,1);
  }
  FUN_600fb848(param_1,0);
  return;
}


