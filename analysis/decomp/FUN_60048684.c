// 60048684  FUN_60048684  size=224 bytes
// --- callers ---
//   60048774 heap_5_improved__60048774
//   600488f4 heap_5_improved__600488f4
// --- callees ---


int FUN_60048684(uint *param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  
  puVar2 = DAT_60048764;
  do {
    puVar4 = puVar2;
    puVar2 = (uint *)*puVar4;
  } while (puVar2 < param_1);
  if (param_1 == (uint *)((int)puVar4 + puVar4[1])) {
    puVar4[1] = param_1[1] + puVar4[1];
    param_1 = puVar4;
  }
  puVar5 = (uint *)((int)param_1 + param_1[1]);
  if (puVar2 == puVar5) {
    if (puVar2 == (uint *)*DAT_60048768) {
      *param_1 = (uint)puVar2;
    }
    else {
      uVar6 = *puVar2;
      if (param_2 != 0) {
        if ((uVar6 & 7) == 0) {
          for (puVar5 = (uint *)*DAT_6004876c; puVar5[1] != 0; puVar5 = puVar5 + 2) {
            if ((*puVar5 <= uVar6) && (uVar6 < *puVar5 + puVar5[1])) {
              if ((puVar2[1] & *DAT_60048770) == 0) goto LAB_60048752;
              break;
            }
          }
        }
        *param_1 = (uint)*DAT_60048768;
        if (param_1 != puVar4) {
          *puVar4 = (uint)param_1;
        }
        return 0;
      }
LAB_60048752:
      uVar3 = puVar2[1];
      *param_1 = uVar6;
      param_1[1] = uVar3 + param_1[1];
    }
    param_2 = 1;
  }
  else {
    if (param_2 == 0) {
      param_2 = 1;
    }
    else {
      piVar7 = (int *)*DAT_6004876c;
      piVar9 = piVar7;
      do {
        piVar1 = piVar9 + 1;
        if (*piVar1 == 0) {
          if (*puVar5 == 0) {
            if ((puVar5[1] & *DAT_60048770) == 0) {
              param_2 = 0;
            }
            else {
              param_2 = 1;
            }
          }
          else {
            param_2 = 0;
          }
          goto LAB_6004870c;
        }
        iVar8 = *piVar9;
        piVar9 = piVar9 + 2;
      } while (puVar5 != (uint *)(*piVar1 + -8 + iVar8 & 0xfffffff8U));
      if (puVar5[1] == 0) {
        for (; piVar7[1] != 0; piVar7 = piVar7 + 2) {
          if (((uint *)*piVar7 <= puVar5) && (puVar5 < (uint *)(*piVar7 + piVar7[1])))
          goto LAB_6004870c;
        }
      }
      param_2 = 0;
    }
LAB_6004870c:
    *param_1 = (uint)puVar2;
  }
  if (param_1 != puVar4) {
    *puVar4 = (uint)param_1;
  }
  return param_2;
}


