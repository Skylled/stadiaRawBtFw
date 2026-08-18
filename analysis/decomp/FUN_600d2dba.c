// 600d2dba  FUN_600d2dba  size=282 bytes
// --- callers ---
// --- callees ---
//   600d1692 FUN_600d1692
//   600d2a6e FUN_600d2a6e
//   600d33b2 FUN_600d33b2
//   600d2ace FUN_600d2ace
//   600d29b8 FUN_600d29b8
//   600d2b6c FUN_600d2b6c
//   600d2720 FUN_600d2720
//   600d16ae FUN_600d16ae
//   600d2986 FUN_600d2986


undefined4 FUN_600d2dba(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  int extraout_r1;
  undefined4 *extraout_r1_00;
  uint *puVar4;
  ushort uVar5;
  int *piVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  int *local_1c;
  undefined4 uStack_18;
  
  uVar5 = (ushort)*(byte *)(param_2 + 5);
  local_1c = param_2;
  uStack_18 = param_3;
  switch(uVar5) {
  case 0:
  case 2:
    puVar2 = *(uint **)(param_1 + 0x2c);
    puVar4 = (uint *)param_2[6];
    puVar7 = puVar2;
    if ((uint *)(*puVar2 & 0xffffffe0) == puVar4) {
      FUN_600d2986(*(undefined4 *)(param_1 + 0x28));
      **(undefined4 **)(param_1 + 0x2c) = **(undefined4 **)(extraout_r1 + 0x18);
LAB_600d2dea:
      FUN_600d2720(param_1);
    }
    else {
      do {
        if ((int)(*puVar7 << 0x1f) < 0) break;
        puVar7 = (uint *)(*puVar7 & 0xffffffe0);
        if ((puVar4 == puVar7) || (puVar2 == puVar7)) {
          if (puVar4 == puVar7) {
            FUN_600d2986(*(undefined4 *)(param_1 + 0x28));
            *extraout_r1_00 = *(undefined4 *)param_2[6];
            goto LAB_600d2dea;
          }
          break;
        }
      } while (puVar7 != (uint *)0x0);
    }
    puVar7 = (uint *)param_2[6];
    uVar9 = 1;
    break;
  case 1:
    puVar8 = (undefined4 *)param_2[6];
    if (puVar8[2] != 0) {
      FUN_600d33b2(param_2[1],4,&local_1c);
      if (local_1c == (int *)0x2) {
        FUN_600d2b6c(param_1,param_2);
      }
      else {
        FUN_600d2ace(param_1,param_2[6]);
      }
    }
    FUN_600d1692(*(undefined4 *)(param_1 + 0x3c));
    *puVar8 = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 **)(param_1 + 0x24) = puVar8;
    goto LAB_600d2e26;
  case 3:
    iVar10 = param_1;
    for (uVar9 = (uint)*(ushort *)((int)param_2 + 0x1e); puVar7 = (uint *)param_2[6], uVar9 < 0x400;
        uVar9 = uVar9 + (uVar5 >> 3)) {
      FUN_600d2a6e(*(undefined4 *)(param_1 + 8),puVar7,uVar9 & 0xffff,uVar5,iVar10);
      uVar5 = *(ushort *)(param_2 + 7);
    }
    uVar9 = *puVar7 | 1;
    break;
  default:
    goto switchD_600d2dc6_default;
  }
  *puVar7 = uVar9;
  FUN_600d29b8(param_1,param_2);
  FUN_600d1692(*(undefined4 *)(param_1 + 0x3c));
  *puVar7 = *(uint *)(param_1 + 0xc);
  *(uint **)(param_1 + 0xc) = puVar7;
LAB_600d2e26:
  FUN_600d16ae(*(undefined4 *)(param_1 + 0x3c));
switchD_600d2dc6_default:
  FUN_600d1692(*(undefined4 *)(param_1 + 0x3c));
  piVar1 = *(int **)(param_1 + 0x38);
  if (param_2 == *(int **)(param_1 + 0x38)) {
    *(int *)(param_1 + 0x38) = *param_2;
  }
  else {
    do {
      piVar6 = piVar1;
      if (piVar6 == (int *)0x0) goto LAB_600d2e3c;
      piVar1 = (int *)*piVar6;
    } while ((int *)*piVar6 != param_2);
    *piVar6 = *param_2;
  }
LAB_600d2e3c:
  FUN_600d16ae(*(undefined4 *)(param_1 + 0x3c));
  FUN_600d1692(*(undefined4 *)(param_1 + 0x3c));
  uVar3 = *(undefined4 *)(param_1 + 0x3c);
  *param_2 = *(int *)(param_1 + 0x34);
  *(int **)(param_1 + 0x34) = param_2;
  FUN_600d16ae(uVar3);
  return 0;
}


