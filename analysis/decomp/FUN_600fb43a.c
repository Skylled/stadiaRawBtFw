// 600fb43a  FUN_600fb43a  size=150 bytes
// --- callers ---
// --- callees ---
//   600fa7de FUN_600fa7de
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ad00 FUN_6009ad00
//   600fb848 FUN_600fb848


void FUN_600fb43a(int param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auStack_2c [16];
  undefined1 local_1c;
  undefined1 local_16 [2];
  undefined1 *local_14;
  
  local_14 = param_2;
  FUN_600fa7de(param_1,2,1);
  local_1c = *local_14;
  puVar1 = local_16;
  for (iVar2 = 0; local_14 = local_14 + 1, iVar2 < 6; iVar2 = iVar2 + 1) {
    *puVar1 = *local_14;
    puVar1 = puVar1 + -1;
  }
  thunk_EXT_FUN_0000b572(auStack_2c,param_1 + 0x1b6,0x10);
  if (((*(byte *)(param_1 + 0x191) & 1) != 0) && ((*(byte *)(param_1 + 0x192) & 1) != 0)) {
    FUN_6009ad00(param_1 + 0x1d,2,auStack_2c,1);
  }
  FUN_600fb848(param_1,0);
  return;
}


