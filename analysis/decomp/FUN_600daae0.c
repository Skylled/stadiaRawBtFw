// 600daae0  FUN_600daae0  size=226 bytes
// --- callers ---
//   600dabc2 FUN_600dabc2
// --- callees ---
//   600daac6 FUN_600daac6


undefined4 * FUN_600daae0(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_30;
  char local_2c;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 auStack_24 [12];
  
  iVar6 = 7;
  iVar3 = *(int *)(param_2 + 0x68);
  iVar4 = 0;
  do {
    iVar5 = iVar4 + iVar6 >> 1;
    piVar1 = (int *)(iVar3 + iVar5 * 0xc);
    iVar7 = *(int *)(iVar3 + iVar5 * 0xc);
    if (param_3 == iVar7) goto LAB_600dab2c;
    if (param_3 < iVar7) {
      iVar6 = iVar5 + -1;
    }
    else {
      iVar4 = iVar5 + 1;
    }
  } while (iVar4 < iVar6);
  if ((param_3 < *(int *)(iVar3 + iVar4 * 0xc)) && (iVar4 != 0)) {
    piVar1 = (int *)((iVar4 + -1) * 0xc + iVar3);
  }
  else {
    piVar1 = (int *)(iVar4 * 0xc + iVar3);
  }
LAB_600dab2c:
  if ((param_3 == *piVar1) && (piVar1 != (int *)(iVar3 + 0x60))) {
    piVar2 = (int *)piVar1[1];
    for (iVar6 = 0; iVar6 != piVar1[2]; iVar6 = iVar6 + 1) {
      if (*piVar2 == param_4) goto LAB_600dab80;
      piVar2 = piVar2 + 4;
    }
    for (iVar6 = 0; iVar6 != (*(int **)(param_2 + 0x6c))[1]; iVar6 = iVar6 + 1) {
      iVar3 = **(int **)(param_2 + 0x6c);
      piVar2 = (int *)(iVar3 + iVar6 * 0x10);
      if (*(int *)(iVar3 + iVar6 * 0x10) == param_4) goto LAB_600dab80;
    }
    *(undefined1 *)(param_1 + 1) = 0;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)((int)param_1 + 9) = 0;
    local_26 = 1;
  }
  else {
    local_26 = 0;
    *(undefined1 *)(param_1 + 1) = 0;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)((int)param_1 + 9) = 0;
  }
LAB_600dab40:
  *(undefined1 *)((int)param_1 + 10) = local_26;
  return param_1;
LAB_600dab80:
  FUN_600daac6(&local_30,piVar2 + 1);
  FUN_600daac6(auStack_24,&local_30);
  if (local_2c != '\0') {
    *param_1 = local_30;
  }
  *(bool *)(param_1 + 1) = local_2c != '\0';
  *(undefined1 *)(param_1 + 2) = local_28;
  *(undefined1 *)((int)param_1 + 9) = local_27;
  goto LAB_600dab40;
}


