// 600da24a  FUN_600da24a  size=270 bytes
// --- callers ---
//   600da358 FUN_600da358
// --- callees ---
//   600da230 FUN_600da230


undefined4 *
FUN_600da24a(undefined4 *param_1,int *param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  int iVar6;
  int *piVar7;
  undefined4 local_38;
  char local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 auStack_2c [4];
  char local_28;
  
  iVar3 = param_2[0x1a];
  iVar2 = 0;
  do {
    iVar1 = iVar2 + 2 >> 1;
    iVar6 = iVar1 * 0xc;
    piVar4 = (int *)(iVar3 + iVar6);
    iVar6 = *(int *)(iVar3 + iVar6);
    if (param_3 == iVar6) goto LAB_600da296;
  } while ((iVar6 <= param_3) && (iVar2 = iVar1 + 1, iVar2 < 2));
  if ((param_3 < *(int *)(iVar3 + iVar2 * 0xc)) && (iVar2 != 0)) {
    piVar4 = (int *)((iVar2 + -1) * 0xc + iVar3);
  }
  else {
    piVar4 = (int *)(iVar2 * 0xc + iVar3);
  }
LAB_600da296:
  if ((param_3 == *piVar4) && (piVar4 != (int *)(iVar3 + 0x24))) {
    piVar7 = (int *)piVar4[1];
    for (iVar2 = 0; iVar2 != piVar4[2]; iVar2 = iVar2 + 1) {
      if (*piVar7 == param_4) goto LAB_600da2d0;
      piVar7 = piVar7 + 4;
    }
    (**(code **)(*param_2 + 8))(auStack_2c,param_2,param_3);
    if (local_28 == '\0') {
      for (iVar2 = 0; iVar2 != ((int *)param_2[0x1b])[1]; iVar2 = iVar2 + 1) {
        iVar3 = *(int *)param_2[0x1b];
        piVar7 = (int *)(iVar3 + iVar2 * 0x10);
        if (*(int *)(iVar3 + iVar2 * 0x10) == param_4) goto LAB_600da2d0;
      }
      *(undefined1 *)(param_1 + 1) = 0;
      *(undefined1 *)(param_1 + 2) = 0;
      *(undefined1 *)((int)param_1 + 9) = 0;
      local_2e = 1;
      goto LAB_600da2aa;
    }
  }
  local_2e = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
LAB_600da2aa:
  *(undefined1 *)((int)param_1 + 10) = local_2e;
  return param_1;
LAB_600da2d0:
  FUN_600da230(&local_38,piVar7 + 1);
  pcVar5 = *(code **)(*param_2 + 0x28);
  FUN_600da230(auStack_2c,&local_38);
  (*pcVar5)(param_2,param_3,param_4,auStack_2c,param_5);
  if (local_34 != '\0') {
    *param_1 = local_38;
  }
  *(bool *)(param_1 + 1) = local_34 != '\0';
  *(undefined1 *)(param_1 + 2) = local_30;
  *(undefined1 *)((int)param_1 + 9) = local_2f;
  goto LAB_600da2aa;
}


