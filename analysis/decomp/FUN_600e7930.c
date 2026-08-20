// 600e7930  FUN_600e7930  size=156 bytes
// --- callers ---
//   600e87fa FUN_600e87fa
//   600e9542 FUN_600e9542
//   600e89f8 FUN_600e89f8
//   600e863c FUN_600e863c
// --- callees ---
//   600e78a2 FUN_600e78a2
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e77d4 FUN_600e77d4


void FUN_600e7930(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,uint param_5)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar2 = param_5;
  puVar4 = param_4;
  if (param_3 < param_5) {
    uVar2 = param_3;
    param_3 = param_5;
    puVar4 = param_2;
    param_2 = param_4;
  }
  if (uVar2 == 0) {
    thunk_EXT_FUN_0000af90(param_1,0,param_3 * 4,param_4);
    return;
  }
  puVar3 = (undefined4 *)(param_1 + param_3 * 4);
  uVar1 = FUN_600e78a2(param_1,param_2,param_3,*puVar4);
  *(undefined4 *)(param_1 + param_3 * 4) = uVar1;
  while( true ) {
    if (uVar2 == 1) {
      return;
    }
    uVar1 = FUN_600e77d4(param_1 + 4,param_2,param_3,puVar4[1]);
    puVar3[1] = uVar1;
    if (uVar2 == 2) {
      return;
    }
    uVar1 = FUN_600e77d4(param_1 + 8,param_2,param_3,puVar4[2]);
    puVar3[2] = uVar1;
    if (uVar2 == 3) {
      return;
    }
    uVar1 = FUN_600e77d4(param_1 + 0xc,param_2,param_3,puVar4[3]);
    uVar2 = uVar2 - 4;
    puVar3[3] = uVar1;
    if (uVar2 == 0) break;
    param_1 = param_1 + 0x10;
    puVar4 = puVar4 + 4;
    uVar1 = FUN_600e77d4(param_1,param_2,param_3,*puVar4);
    puVar3 = puVar3 + 4;
    *puVar3 = uVar1;
  }
  return;
}


