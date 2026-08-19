// 600e00ca  FUN_600e00ca  size=234 bytes
// --- callers ---
//   600849a4 state_machine__600849a4
// --- callees ---
//   60101fcc FUN_60101fcc
//   6013d238 thunk_EXT_FUN_0000b588
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600e00ca(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  
  iVar5 = param_1[9];
  uVar6 = param_1[1];
  if (1 < uVar6 - (iVar5 - *param_1 >> 2)) goto LAB_600e0130;
  piVar3 = (int *)param_1[5];
  iVar11 = iVar5 - (int)piVar3 >> 2;
  iVar9 = iVar11 + 2;
  if ((uint)(iVar9 * 2) < uVar6) {
    piVar7 = (int *)(iVar5 + 4);
    piVar10 = (int *)(*param_1 + (uVar6 - iVar9 >> 1) * 4);
    if (piVar10 < piVar3) {
      piVar1 = piVar10;
      if (piVar3 != piVar7) {
LAB_600e0108:
        thunk_EXT_FUN_0000b588(piVar1);
      }
    }
    else if (piVar3 != piVar7) {
      piVar1 = (int *)(((iVar11 + 1) * 4 - ((int)piVar7 - (int)piVar3)) + (int)piVar10);
      goto LAB_600e0108;
    }
  }
  else {
    uVar12 = uVar6;
    if (uVar6 == 0) {
      uVar12 = 1;
    }
    uVar12 = uVar12 + uVar6 + 2;
    if (0x3fffffff < uVar12) {
      FUN_60101fcc();
    }
    iVar5 = thunk_EXT_FUN_0000b532(uVar12 * 4);
    iVar4 = param_1[5];
    piVar10 = (int *)(iVar5 + (uVar12 - iVar9 >> 1) * 4);
    if (param_1[9] + 4 != iVar4) {
      thunk_EXT_FUN_0000b588(piVar10,iVar4,(param_1[9] + 4) - iVar4);
    }
    thunk_EXT_FUN_0000b52a(*param_1);
    *param_1 = iVar5;
    param_1[1] = uVar12;
  }
  iVar5 = *piVar10;
  param_1[5] = (int)piVar10;
  param_1[3] = iVar5;
  param_1[4] = iVar5 + 0x200;
  iVar5 = piVar10[iVar11];
  param_1[7] = iVar5;
  param_1[9] = (int)(piVar10 + iVar11);
  param_1[8] = iVar5 + 0x200;
LAB_600e0130:
  iVar5 = param_1[9];
  uVar2 = thunk_EXT_FUN_0000b532(0x200);
  *(undefined4 *)(iVar5 + 4) = uVar2;
  puVar8 = (undefined4 *)param_1[6];
  uVar2 = param_2[1];
  *puVar8 = *param_2;
  puVar8[1] = uVar2;
  iVar5 = *(int *)(param_1[9] + 4);
  param_1[9] = param_1[9] + 4;
  param_1[7] = iVar5;
  param_1[8] = iVar5 + 0x200;
  param_1[6] = iVar5;
  return;
}


