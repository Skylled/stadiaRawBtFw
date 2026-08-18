// 600cf0ca  FUN_600cf0ca  size=232 bytes
// --- callers ---
// --- callees ---
//   600cefde FUN_600cefde


int FUN_600cf0ca(int param_1,char *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  undefined4 *extraout_r2;
  undefined4 uVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  undefined8 uVar12;
  
  if (*param_2 == '\0') {
    uVar12 = FUN_600cefde();
    iVar8 = (int)((ulonglong)uVar12 >> 0x20);
    iVar10 = (int)uVar12;
    if (iVar10 == 0) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffc1fc;
      uVar2 = extraout_r2[1];
      uVar4 = extraout_r2[2];
      uVar6 = extraout_r2[3];
      *(undefined4 *)(iVar8 + 0x18) = *extraout_r2;
      *(undefined4 *)(iVar8 + 0x1c) = uVar2;
      *(undefined4 *)(iVar8 + 0x20) = uVar4;
      *(undefined4 *)(iVar8 + 0x24) = uVar6;
      iVar7 = *(int *)(param_2 + 0x18);
      uVar2 = extraout_r2[5];
      *(undefined4 *)(iVar8 + 0x28) = extraout_r2[4];
      *(undefined4 *)(iVar8 + 0x2c) = uVar2;
      if (iVar7 << 0x1f < 0) {
        if (param_2[0x1e] == '\x01') {
          cVar5 = '\x02';
        }
        else {
          cVar5 = '\x03';
        }
        *param_2 = cVar5;
        *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 0x28);
        *(short *)(param_2 + 2) = (short)*(undefined4 *)(param_2 + 0x2c);
      }
      else {
        iVar8 = *(int *)(param_2 + 0x24);
        puVar3 = (ushort *)(param_2 + 8);
        if (iVar8 == 0) {
          uVar1 = (ushort)(byte)param_2[0x1e];
        }
        else {
          uVar1 = 0;
        }
        *(ushort *)(param_2 + 8) = uVar1 | *(short *)(param_2 + 0x1c) << 1 | 0x400;
        if (iVar8 == 0) {
          iVar8 = 1;
        }
        else {
          uVar11 = iVar8 << 3;
          puVar9 = puVar3;
          while (uVar11 = uVar11 - 8, puVar9 != puVar3 + iVar8) {
            puVar9 = puVar9 + 1;
            *puVar9 = (ushort)(*(uint *)(param_2 + 0x20) >> (uVar11 & 0xff)) & 0xff;
          }
          iVar8 = iVar8 + 1;
        }
        iVar7 = *(int *)(param_2 + 0x2c);
        if ((iVar7 != 0) && (param_2[0x1e] == '\x01')) {
          if (uVar1 == 0) {
            puVar3[iVar8] = *(short *)(param_2 + 0x1c) << 1 | 0x401;
            iVar8 = iVar8 + 1;
          }
          puVar3[iVar8] = (short)iVar7 - 1U & 0xff | 0x100;
          iVar8 = iVar8 + 1;
        }
        *(short *)(param_2 + 2) = (short)iVar8;
        *(ushort **)(param_2 + 4) = puVar3;
        *param_2 = '\x01';
      }
      *(undefined4 *)(param_1 + 0x14) = 0x7f00;
      *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xfffffeff;
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x3e03;
    }
  }
  else {
    iVar10 = 900;
  }
  return iVar10;
}


