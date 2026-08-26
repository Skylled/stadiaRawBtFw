// 600d598e  FUN_600d598e  size=226 bytes
// --- callers ---
//   600d5a70 FUN_600d5a70
// --- callees ---
//   600d5892 FUN_600d5892


undefined4 * FUN_600d598e(undefined4 *param_1,int param_2,int param_3,uint param_4)

{
  int *piVar1;
  byte *pbVar2;
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
  
  iVar6 = 0xf;
  iVar3 = *(int *)(param_2 + 0x68);
  iVar4 = 0;
  do {
    iVar5 = iVar4 + iVar6 >> 1;
    piVar1 = (int *)(iVar3 + iVar5 * 0xc);
    iVar7 = *(int *)(iVar3 + iVar5 * 0xc);
    if (param_3 == iVar7) goto LAB_600d59da;
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
LAB_600d59da:
  if ((param_3 == *piVar1) && (piVar1 != (int *)(iVar3 + 0xc0))) {
    pbVar2 = (byte *)piVar1[1];
    for (iVar6 = 0; iVar6 != piVar1[2]; iVar6 = iVar6 + 1) {
      if (*pbVar2 == param_4) goto LAB_600d5a2e;
      pbVar2 = pbVar2 + 0x10;
    }
    for (iVar6 = 0; iVar6 != (*(int **)(param_2 + 0x6c))[1]; iVar6 = iVar6 + 1) {
      iVar3 = **(int **)(param_2 + 0x6c);
      pbVar2 = (byte *)(iVar3 + iVar6 * 0x10);
      if (*(byte *)(iVar3 + iVar6 * 0x10) == param_4) goto LAB_600d5a2e;
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
LAB_600d59ee:
  *(undefined1 *)((int)param_1 + 10) = local_26;
  return param_1;
LAB_600d5a2e:
  FUN_600d5892(&local_30,pbVar2 + 4);
  FUN_600d5892(auStack_24,&local_30);
  if (local_2c != '\0') {
    *param_1 = local_30;
  }
  *(bool *)(param_1 + 1) = local_2c != '\0';
  *(undefined1 *)(param_1 + 2) = local_28;
  *(undefined1 *)((int)param_1 + 9) = local_27;
  goto LAB_600d59ee;
}


