// 600e6b3a  FUN_600e6b3a  size=138 bytes
// --- callers ---
//   600e70ba FUN_600e70ba
//   600e6e26 FUN_600e6e26
//   6008deac FUN_6008deac
//   600e6dfe FUN_600e6dfe
// --- callees ---
//   600e6ac2 FUN_600e6ac2


void FUN_600e6b3a(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int local_28 [4];
  
  local_28[0] = (int)param_1;
  local_28[1] = param_2;
  local_28[2] = param_3;
  local_28[3] = param_4;
  for (uVar5 = 0; uVar5 <= *(uint *)(param_2 + 0xf0); uVar5 = uVar5 + 1) {
    piVar4 = (int *)(param_2 + uVar5 * 0x10);
    piVar2 = piVar4;
    piVar6 = local_28;
    do {
      piVar3 = piVar2 + 2;
      iVar1 = piVar2[1];
      *piVar6 = *piVar2;
      piVar6[1] = iVar1;
      piVar6 = piVar6 + 2;
      piVar2 = piVar3;
    } while (piVar3 != piVar4 + 4);
    *param_1 = local_28[0];
    param_1[2] = local_28[1];
    param_1[4] = local_28[2];
    param_1[6] = local_28[3];
    piVar2 = piVar4;
    piVar6 = local_28;
    do {
      piVar3 = piVar2 + 2;
      iVar1 = piVar2[1];
      *piVar6 = *piVar2;
      piVar6[1] = iVar1;
      piVar6 = piVar6 + 2;
      piVar2 = piVar3;
    } while (piVar3 != piVar4 + 4);
    param_1[1] = local_28[0];
    param_1[3] = local_28[1];
    param_1[5] = local_28[2];
    param_1[7] = local_28[3];
    FUN_600e6ac2(param_1);
    param_1 = param_1 + 8;
  }
  return;
}


