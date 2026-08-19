// 600d3ece  FUN_600d3ece  size=280 bytes
// --- callers ---
// --- callees ---
//   600d3eb4 FUN_600d3eb4


undefined4 *
FUN_600d3ece(undefined4 *param_1,int *param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 local_38;
  char local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 auStack_2c [4];
  char local_28;
  
  iVar3 = param_2[0x1a];
  iVar6 = 0xd;
  iVar2 = 0;
  do {
    iVar1 = iVar2 + iVar6 >> 1;
    piVar4 = (int *)(iVar3 + iVar1 * 0xc);
    iVar7 = *(int *)(iVar3 + iVar1 * 0xc);
    if (param_3 == iVar7) goto LAB_600d3f24;
    if (param_3 < iVar7) {
      iVar6 = iVar1 + -1;
    }
    else {
      iVar2 = iVar1 + 1;
    }
  } while (iVar2 < iVar6);
  if ((param_3 < *(int *)(iVar3 + iVar2 * 0xc)) && (iVar2 != 0)) {
    piVar4 = (int *)((iVar2 + -1) * 0xc + iVar3);
  }
  else {
    piVar4 = (int *)(iVar2 * 0xc + iVar3);
  }
LAB_600d3f24:
  if ((param_3 == *piVar4) && (piVar4 != (int *)(iVar3 + 0xa8))) {
    piVar8 = (int *)piVar4[1];
    for (iVar6 = 0; iVar6 != piVar4[2]; iVar6 = iVar6 + 1) {
      if (*piVar8 == param_4) goto LAB_600d3f5e;
      piVar8 = piVar8 + 4;
    }
    (**(code **)(*param_2 + 8))(auStack_2c,param_2,param_3);
    if (local_28 == '\0') {
      for (iVar6 = 0; iVar6 != ((int *)param_2[0x1b])[1]; iVar6 = iVar6 + 1) {
        iVar2 = *(int *)param_2[0x1b];
        piVar8 = (int *)(iVar2 + iVar6 * 0x10);
        if (*(int *)(iVar2 + iVar6 * 0x10) == param_4) goto LAB_600d3f5e;
      }
      *(undefined1 *)(param_1 + 1) = 0;
      *(undefined1 *)(param_1 + 2) = 0;
      *(undefined1 *)((int)param_1 + 9) = 0;
      local_2e = 1;
      goto LAB_600d3f38;
    }
  }
  local_2e = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
LAB_600d3f38:
  *(undefined1 *)((int)param_1 + 10) = local_2e;
  return param_1;
LAB_600d3f5e:
  FUN_600d3eb4(&local_38,piVar8 + 1);
  pcVar5 = *(code **)(*param_2 + 0x28);
  FUN_600d3eb4(auStack_2c,&local_38);
  (*pcVar5)(param_2,param_3,param_4,auStack_2c,param_5);
  if (local_34 != '\0') {
    *param_1 = local_38;
  }
  *(bool *)(param_1 + 1) = local_34 != '\0';
  *(undefined1 *)(param_1 + 2) = local_30;
  *(undefined1 *)((int)param_1 + 9) = local_2f;
  goto LAB_600d3f38;
}


