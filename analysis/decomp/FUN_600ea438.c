// 600ea438  FUN_600ea438  size=638 bytes
// --- callers ---
//   600ea6b6 FUN_600ea6b6
// --- callees ---
//   600ea032 FUN_600ea032
//   600ea0e8 FUN_600ea0e8


void FUN_600ea438(uint *param_1,undefined1 *param_2,uint param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,uint *param_7,int param_8)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  uint local_30;
  uint local_2c;
  
  uVar4 = *param_7;
  uVar3 = param_7[1];
  local_2c = uVar3;
  local_30 = uVar4;
  puVar7 = param_2;
  puVar10 = param_1;
  if (param_8 == 0) {
    for (; 7 < (int)param_1 + (param_3 - (int)puVar10); puVar10 = puVar10 + 2) {
      uVar5 = *puVar10;
      uVar8 = puVar10[1];
      local_30 = uVar5;
      local_2c = uVar8;
      FUN_600ea0e8(&local_30,param_4,param_5,param_6);
      uVar4 = uVar4 ^ local_30;
      uVar3 = uVar3 ^ local_2c;
      *puVar7 = (char)uVar4;
      puVar7[1] = (char)(uVar4 >> 8);
      puVar7[4] = (char)uVar3;
      puVar7[2] = (char)(uVar4 >> 0x10);
      puVar7[3] = (char)(uVar4 >> 0x18);
      puVar7[5] = (char)(uVar3 >> 8);
      puVar7[6] = (char)(uVar3 >> 0x10);
      puVar7[7] = (char)(uVar3 >> 0x18);
      uVar3 = uVar8;
      uVar4 = uVar5;
      puVar7 = puVar7 + 8;
    }
    uVar5 = param_3 >> 3;
    iVar6 = uVar5 * -8 + param_3;
    local_2c = uVar3;
    local_30 = uVar4;
    if (iVar6 != 0) {
      uVar11 = param_1[uVar5 * 2];
      uVar8 = (param_1 + uVar5 * 2)[1];
      local_30 = uVar11;
      local_2c = uVar8;
      FUN_600ea0e8(&local_30,param_4,param_5,param_6);
      uVar4 = uVar4 ^ local_30;
      uVar3 = uVar3 ^ local_2c;
      param_2 = param_2 + uVar5 * 8 + iVar6;
      switch(iVar6) {
      case 7:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar3 >> 0x10);
      case 6:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar3 >> 8);
      case 5:
        param_2[-1] = (char)uVar3;
        param_2 = param_2 + -1;
      case 4:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar4 >> 0x18);
      case 3:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar4 >> 0x10);
      case 2:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar4 >> 8);
      default:
        param_2[-1] = (char)uVar4;
        local_2c = uVar8;
        local_30 = uVar11;
      }
    }
    goto LAB_600ea5da;
  }
  for (; 7 < (int)param_1 + (param_3 - (int)puVar10); puVar10 = puVar10 + 2) {
    local_30 = local_30 ^ *puVar10;
    local_2c = local_2c ^ puVar10[1];
    FUN_600ea032(&local_30,param_4,param_5,param_6);
    *puVar7 = (char)local_30;
    puVar7[4] = (char)local_2c;
    puVar7[1] = (char)(local_30 >> 8);
    puVar7[2] = (char)(local_30 >> 0x10);
    puVar7[3] = (char)(local_30 >> 0x18);
    puVar7[5] = (char)(local_2c >> 8);
    puVar7[6] = (char)(local_2c >> 0x10);
    puVar7[7] = (char)(local_2c >> 0x18);
    puVar7 = puVar7 + 8;
  }
  uVar3 = param_3 >> 3;
  iVar2 = uVar3 * 8;
  iVar6 = uVar3 * -8 + param_3;
  if (iVar6 == 0) goto LAB_600ea5da;
  iVar9 = (int)param_1 + iVar2 + iVar6;
  pbVar1 = (byte *)(iVar9 + -1);
  switch(iVar6) {
  case 2:
    uVar5 = 0;
    uVar4 = uVar5;
    goto LAB_600ea590;
  case 3:
    uVar5 = 0;
    uVar4 = uVar5;
    goto LAB_600ea584;
  case 4:
    uVar4 = 0;
    goto LAB_600ea57a;
  case 5:
    uVar4 = 0;
    goto LAB_600ea570;
  case 6:
    uVar4 = 0;
    break;
  case 7:
    iVar9 = iVar9 + -1;
    uVar4 = (uint)*pbVar1 << 0x10;
    break;
  default:
    uVar5 = 0;
    uVar4 = uVar5;
    goto LAB_600ea59c;
  }
  pbVar1 = (byte *)(iVar9 + -1);
  iVar9 = iVar9 + -1;
  uVar4 = uVar4 | (uint)*pbVar1 << 8;
LAB_600ea570:
  pbVar1 = (byte *)(iVar9 + -1);
  iVar9 = iVar9 + -1;
  uVar4 = uVar4 | *pbVar1;
LAB_600ea57a:
  pbVar1 = (byte *)(iVar9 + -1);
  iVar9 = iVar9 + -1;
  uVar5 = (uint)*pbVar1 << 0x18;
LAB_600ea584:
  pbVar1 = (byte *)(iVar9 + -1);
  iVar9 = iVar9 + -1;
  uVar5 = uVar5 | (uint)*pbVar1 << 0x10;
LAB_600ea590:
  pbVar1 = (byte *)(iVar9 + -1);
  iVar9 = iVar9 + -1;
  uVar5 = uVar5 | (uint)*pbVar1 << 8;
LAB_600ea59c:
  local_2c = local_2c ^ uVar4;
  local_30 = local_30 ^ (uVar5 | *(byte *)(iVar9 + -1));
  FUN_600ea032(&local_30,param_4,param_5,param_6);
  param_2[uVar3 * 8] = (char)local_30;
  param_2[iVar2 + 4] = (char)local_2c;
  param_2[iVar2 + 1] = (char)(local_30 >> 8);
  param_2[iVar2 + 2] = (char)(local_30 >> 0x10);
  param_2[iVar2 + 3] = (char)(local_30 >> 0x18);
  param_2[iVar2 + 5] = (char)(local_2c >> 8);
  param_2[iVar2 + 6] = (char)(local_2c >> 0x10);
  param_2[iVar2 + 7] = (char)(local_2c >> 0x18);
LAB_600ea5da:
  *(char *)param_7 = (char)local_30;
  *(char *)(param_7 + 1) = (char)local_2c;
  *(char *)((int)param_7 + 1) = (char)(local_30 >> 8);
  *(char *)((int)param_7 + 2) = (char)(local_30 >> 0x10);
  *(char *)((int)param_7 + 3) = (char)(local_30 >> 0x18);
  *(char *)((int)param_7 + 5) = (char)(local_2c >> 8);
  *(char *)((int)param_7 + 6) = (char)(local_2c >> 0x10);
  *(char *)((int)param_7 + 7) = (char)(local_2c >> 0x18);
  return;
}


