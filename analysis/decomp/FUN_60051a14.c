// 60051a14  FUN_60051a14  size=54 bytes
// --- callers ---
// --- callees ---
//   60051890 FUN_60051890
//   600519fc FUN_600519fc


undefined1 FUN_60051a14(undefined4 *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar3 = *DAT_60051a4c;
  local_2c = *param_1;
  uStack_28 = param_1[1];
  uStack_24 = param_1[2];
  uStack_20 = param_1[3];
  local_1c = param_1[4];
  uStack_18 = param_1[5];
  uStack_14 = param_1[6];
  uVar2 = FUN_600519fc();
  if (uVar2 < 0x864) {
    uVar1 = 8;
  }
  else {
    uVar1 = FUN_60051890(&local_2c,*(undefined4 *)(iVar3 + 0x44));
  }
  return uVar1;
}


