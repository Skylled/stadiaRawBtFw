// 600cf0ca  FUN_600cf0ca  size=232 bytes
// --- callers ---
// --- callees ---
//   600cefde FUN_600cefde


int FUN_600cf0ca(int param_1,char *param_2)

{
  ushort uVar1;
  int iVar2;
  int extraout_r1;
  undefined4 uVar3;
  ushort *puVar4;
  undefined4 *extraout_r2;
  undefined4 uVar5;
  int iVar6;
  char cVar7;
  undefined4 uVar8;
  int iVar9;
  ushort *puVar10;
  uint uVar11;
  
  if (*param_2 == '\0') {
    iVar2 = FUN_600cefde();
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffc1fc;
      uVar3 = extraout_r2[1];
      uVar5 = extraout_r2[2];
      uVar8 = extraout_r2[3];
      *(undefined4 *)(extraout_r1 + 0x18) = *extraout_r2;
      *(undefined4 *)(extraout_r1 + 0x1c) = uVar3;
      *(undefined4 *)(extraout_r1 + 0x20) = uVar5;
      *(undefined4 *)(extraout_r1 + 0x24) = uVar8;
      iVar9 = *(int *)(param_2 + 0x18);
      uVar3 = extraout_r2[5];
      *(undefined4 *)(extraout_r1 + 0x28) = extraout_r2[4];
      *(undefined4 *)(extraout_r1 + 0x2c) = uVar3;
      if (iVar9 << 0x1f < 0) {
        if (param_2[0x1e] == '\x01') {
          cVar7 = '\x02';
        }
        else {
          cVar7 = '\x03';
        }
        *param_2 = cVar7;
        *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 0x28);
        *(short *)(param_2 + 2) = (short)*(undefined4 *)(param_2 + 0x2c);
      }
      else {
        iVar9 = *(int *)(param_2 + 0x24);
        puVar4 = (ushort *)(param_2 + 8);
        if (iVar9 == 0) {
          uVar1 = (ushort)(byte)param_2[0x1e];
        }
        else {
          uVar1 = 0;
        }
        *(ushort *)(param_2 + 8) = uVar1 | *(short *)(param_2 + 0x1c) << 1 | 0x400;
        if (iVar9 == 0) {
          iVar9 = 1;
        }
        else {
          uVar11 = iVar9 << 3;
          puVar10 = puVar4;
          while (uVar11 = uVar11 - 8, puVar10 != puVar4 + iVar9) {
            puVar10 = puVar10 + 1;
            *puVar10 = (ushort)(*(uint *)(param_2 + 0x20) >> (uVar11 & 0xff)) & 0xff;
          }
          iVar9 = iVar9 + 1;
        }
        iVar6 = *(int *)(param_2 + 0x2c);
        if ((iVar6 != 0) && (param_2[0x1e] == '\x01')) {
          if (uVar1 == 0) {
            puVar4[iVar9] = *(short *)(param_2 + 0x1c) << 1 | 0x401;
            iVar9 = iVar9 + 1;
          }
          puVar4[iVar9] = (short)iVar6 - 1U & 0xff | 0x100;
          iVar9 = iVar9 + 1;
        }
        *(short *)(param_2 + 2) = (short)iVar9;
        *(ushort **)(param_2 + 4) = puVar4;
        *param_2 = '\x01';
      }
      *(undefined4 *)(param_1 + 0x14) = 0x7f00;
      *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xfffffeff;
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x3e03;
    }
  }
  else {
    iVar2 = 900;
  }
  return iVar2;
}


