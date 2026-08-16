// 6008c728  bcm__6008c728  size=194 bytes
// src: bcm.c
// --- callers ---
//   60085f2c pem_lib__60085f2c
// --- callees ---
//   600e0552 FUN_600e0552


/* src: bcm.c */

undefined4 bcm__6008c728(int *param_1,undefined1 *param_2,int *param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  byte *pbVar7;
  undefined4 uVar8;
  
  *param_3 = 0;
  iVar3 = *param_1;
  if ((*(uint *)(iVar3 + 0x14) & 0x400) == 0) {
    if (param_1[5] << 0x14 < 0) {
      if (param_1[0x16] != 0) {
        uVar4 = 0x6a;
        uVar8 = 0x1ad;
LAB_6008c766:
        FUN_600e0552(0x1e,0,uVar4,DAT_6008c7ec,uVar8,param_2,param_3);
        return 0;
      }
    }
    else {
      uVar5 = *(uint *)(iVar3 + 4);
      if (1 < uVar5) {
        if ((param_1[0x16] != 0) || (param_1[0x18] == 0)) {
          uVar4 = 0x7b;
          uVar8 = 0x1b6;
          goto LAB_6008c766;
        }
        uVar1 = (uint)*(byte *)((int)param_1 + uVar5 + 0x67);
        if ((uVar1 == 0) || ((int)uVar5 < (int)uVar1)) {
          uVar4 = 0x1bf;
LAB_6008c7a0:
          FUN_600e0552(0x1e,0,0x65,DAT_6008c7ec,uVar4,param_2,param_3);
          return 0;
        }
        pbVar7 = (byte *)(uVar5 + 0x68 + (int)param_1);
        do {
          pbVar7 = pbVar7 + -1;
          if (*pbVar7 != uVar1) {
            uVar4 = 0x1c5;
            goto LAB_6008c7a0;
          }
        } while ((int)((int)param_1 + uVar5 + (0x68 - (int)pbVar7)) < (int)uVar1);
        piVar6 = param_1 + 0x1a;
        for (puVar2 = param_2; (int)puVar2 - (int)param_2 < (int)(uVar5 - uVar1);
            puVar2 = puVar2 + 1) {
          *puVar2 = (char)*piVar6;
          piVar6 = (int *)((int)piVar6 + 1);
        }
        *param_3 = uVar5 - uVar1;
      }
    }
  }
  else {
    iVar3 = (**(code **)(iVar3 + 0x20))(param_1,param_2,0,0,param_1);
    if (iVar3 < 0) {
      return 0;
    }
    *param_3 = iVar3;
  }
  return 1;
}


