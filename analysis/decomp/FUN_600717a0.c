// 600717a0  FUN_600717a0  size=46 bytes
// --- callers ---
//   60073bf0 timer__60073bf0
// --- callees ---


undefined4 *
FUN_600717a0(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = *param_3;
  iVar2 = param_3[1];
  uVar1 = *(undefined1 *)((int)param_3 + 10);
  param_1[5] = param_4;
  *(undefined1 *)(param_1 + 4) = uVar1;
  uVar3 = DAT_600717d0;
  param_1[1] = param_2;
  param_1[2] = iVar6;
  param_1[3] = (iVar2 + 1) - iVar6;
  *param_1 = uVar3;
  uVar3 = param_5[1];
  uVar4 = param_5[2];
  uVar5 = param_5[3];
  param_1[6] = *param_5;
  param_1[7] = uVar3;
  param_1[8] = uVar4;
  param_1[9] = uVar5;
  return param_1;
}


