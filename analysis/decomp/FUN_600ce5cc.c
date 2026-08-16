// 600ce5cc  FUN_600ce5cc  size=46 bytes
// --- callers ---
// --- callees ---
//   60051b50 stats__60051b50
//   600519fc FUN_600519fc


undefined1 FUN_600ce5cc(undefined4 *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_2c = *param_1;
  uStack_28 = param_1[1];
  uStack_24 = param_1[2];
  uStack_20 = param_1[3];
  local_1c = param_1[4];
  uStack_18 = param_1[5];
  uStack_14 = param_1[6];
  uVar2 = FUN_600519fc();
  if (uVar2 < 0x6b8) {
    uVar1 = 8;
  }
  else {
    uVar1 = stats__60051b50(&local_2c);
  }
  return uVar1;
}


