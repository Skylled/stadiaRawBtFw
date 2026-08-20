// 600ea1a0  FUN_600ea1a0  size=634 bytes
// --- callers ---
//   600ea41a FUN_600ea41a
// --- callees ---
//   60087970 FUN_60087970


void FUN_600ea1a0(uint *param_1,undefined1 *param_2,uint param_3,undefined4 param_4,uint *param_5,
                 int param_6)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  uint local_30;
  uint local_2c;
  
  uVar5 = *param_5;
  uVar4 = param_5[1];
  local_2c = uVar4;
  local_30 = uVar5;
  puVar6 = param_2;
  puVar10 = param_1;
  if (param_6 == 0) {
    for (; 7 < (int)param_1 + (param_3 - (int)puVar10); puVar10 = puVar10 + 2) {
      uVar2 = *puVar10;
      uVar7 = puVar10[1];
      local_30 = uVar2;
      local_2c = uVar7;
      FUN_60087970(&local_30,param_4,0);
      uVar5 = uVar5 ^ local_30;
      uVar4 = uVar4 ^ local_2c;
      *puVar6 = (char)uVar5;
      puVar6[1] = (char)(uVar5 >> 8);
      puVar6[4] = (char)uVar4;
      puVar6[2] = (char)(uVar5 >> 0x10);
      puVar6[3] = (char)(uVar5 >> 0x18);
      puVar6[5] = (char)(uVar4 >> 8);
      puVar6[6] = (char)(uVar4 >> 0x10);
      puVar6[7] = (char)(uVar4 >> 0x18);
      uVar4 = uVar7;
      uVar5 = uVar2;
      puVar6 = puVar6 + 8;
    }
    uVar2 = param_3 >> 3;
    iVar9 = uVar2 * -8 + param_3;
    local_2c = uVar4;
    local_30 = uVar5;
    if (iVar9 != 0) {
      uVar11 = param_1[uVar2 * 2];
      uVar7 = (param_1 + uVar2 * 2)[1];
      local_30 = uVar11;
      local_2c = uVar7;
      FUN_60087970(&local_30,param_4,0);
      uVar5 = uVar5 ^ local_30;
      param_2 = param_2 + uVar2 * 8 + iVar9;
      uVar4 = uVar4 ^ local_2c;
      switch(iVar9) {
      case 7:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar4 >> 0x10);
      case 6:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar4 >> 8);
      case 5:
        param_2[-1] = (char)uVar4;
        param_2 = param_2 + -1;
      case 4:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar5 >> 0x18);
      case 3:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar5 >> 0x10);
      case 2:
        param_2 = param_2 + -1;
        *param_2 = (char)(uVar5 >> 8);
      default:
        param_2[-1] = (char)uVar5;
        local_2c = uVar7;
        local_30 = uVar11;
      }
    }
    goto LAB_600ea350;
  }
  for (; 7 < (int)param_1 + (param_3 - (int)puVar10); puVar10 = puVar10 + 2) {
    local_30 = local_30 ^ *puVar10;
    local_2c = local_2c ^ puVar10[1];
    FUN_60087970(&local_30,param_4,1);
    *puVar6 = (char)local_30;
    puVar6[4] = (char)local_2c;
    puVar6[1] = (char)(local_30 >> 8);
    puVar6[2] = (char)(local_30 >> 0x10);
    puVar6[3] = (char)(local_30 >> 0x18);
    puVar6[5] = (char)(local_2c >> 8);
    puVar6[6] = (char)(local_2c >> 0x10);
    puVar6[7] = (char)(local_2c >> 0x18);
    puVar6 = puVar6 + 8;
  }
  uVar4 = param_3 >> 3;
  iVar3 = uVar4 * 8;
  iVar9 = uVar4 * -8 + param_3;
  if (iVar9 == 0) goto LAB_600ea350;
  iVar8 = (int)param_1 + iVar3 + iVar9;
  pbVar1 = (byte *)(iVar8 + -1);
  switch(iVar9) {
  case 2:
    uVar2 = 0;
    uVar5 = uVar2;
    goto LAB_600ea2fc;
  case 3:
    uVar2 = 0;
    uVar5 = uVar2;
    goto LAB_600ea2f0;
  case 4:
    uVar5 = 0;
    goto LAB_600ea2e6;
  case 5:
    uVar5 = 0;
    goto LAB_600ea2dc;
  case 6:
    uVar5 = 0;
    break;
  case 7:
    iVar8 = iVar8 + -1;
    uVar5 = (uint)*pbVar1 << 0x10;
    break;
  default:
    uVar2 = 0;
    uVar5 = uVar2;
    goto LAB_600ea308;
  }
  pbVar1 = (byte *)(iVar8 + -1);
  iVar8 = iVar8 + -1;
  uVar5 = uVar5 | (uint)*pbVar1 << 8;
LAB_600ea2dc:
  pbVar1 = (byte *)(iVar8 + -1);
  iVar8 = iVar8 + -1;
  uVar5 = uVar5 | *pbVar1;
LAB_600ea2e6:
  pbVar1 = (byte *)(iVar8 + -1);
  iVar8 = iVar8 + -1;
  uVar2 = (uint)*pbVar1 << 0x18;
LAB_600ea2f0:
  pbVar1 = (byte *)(iVar8 + -1);
  iVar8 = iVar8 + -1;
  uVar2 = uVar2 | (uint)*pbVar1 << 0x10;
LAB_600ea2fc:
  pbVar1 = (byte *)(iVar8 + -1);
  iVar8 = iVar8 + -1;
  uVar2 = uVar2 | (uint)*pbVar1 << 8;
LAB_600ea308:
  local_2c = local_2c ^ uVar5;
  local_30 = local_30 ^ (uVar2 | *(byte *)(iVar8 + -1));
  FUN_60087970(&local_30,param_4,1);
  param_2[uVar4 * 8] = (char)local_30;
  param_2[iVar3 + 4] = (char)local_2c;
  param_2[iVar3 + 1] = (char)(local_30 >> 8);
  param_2[iVar3 + 2] = (char)(local_30 >> 0x10);
  param_2[iVar3 + 3] = (char)(local_30 >> 0x18);
  param_2[iVar3 + 5] = (char)(local_2c >> 8);
  param_2[iVar3 + 6] = (char)(local_2c >> 0x10);
  param_2[iVar3 + 7] = (char)(local_2c >> 0x18);
LAB_600ea350:
  *(char *)param_5 = (char)local_30;
  *(char *)(param_5 + 1) = (char)local_2c;
  *(char *)((int)param_5 + 1) = (char)(local_30 >> 8);
  *(char *)((int)param_5 + 2) = (char)(local_30 >> 0x10);
  *(char *)((int)param_5 + 3) = (char)(local_30 >> 0x18);
  *(char *)((int)param_5 + 5) = (char)(local_2c >> 8);
  *(char *)((int)param_5 + 6) = (char)(local_2c >> 0x10);
  *(char *)((int)param_5 + 7) = (char)(local_2c >> 0x18);
  return;
}


