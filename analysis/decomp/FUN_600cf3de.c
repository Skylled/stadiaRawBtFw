// 600cf3de  FUN_600cf3de  size=358 bytes
// --- callers ---
//   600d4b78 FUN_600d4b78
// --- callees ---


undefined4
FUN_600cf3de(int param_1,int param_2,int param_3,uint param_4,undefined1 param_5,uint param_6,
            uint param_7)

{
  char cVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  short sVar12;
  uint uVar13;
  int iVar14;
  
  if (param_4 < 3) {
    param_3 = param_3 + 6;
    iVar9 = param_2 * 0x60 + param_1;
    param_6 = (param_7 >> ((*(ushort *)(iVar9 + 6) & 0x7f) >> 4)) / param_6;
    uVar10 = param_6 & 0xffff;
    iVar6 = (short)param_4 * 6 + param_3;
    sVar4 = (short)(uVar10 >> 1);
    sVar3 = -sVar4;
    for (; iVar6 != param_3; param_3 = param_3 + 6) {
      cVar1 = *(char *)(param_3 + -6);
      uVar13 = (uVar10 * *(byte *)(param_3 + -5)) / 100;
      uVar8 = uVar13 & 0xffff;
      uVar2 = (undefined2)param_6;
      switch(param_5) {
      case 0:
        uVar8 = uVar8 >> 1;
        *(short *)(iVar9 + 2) = sVar3;
        *(undefined2 *)(iVar9 + 10) = 0;
        sVar12 = -(short)uVar8;
        *(short *)(iVar9 + 0xe) = sVar4;
        break;
      case 1:
        uVar13 = uVar13 & 0xffff;
        *(undefined2 *)(iVar9 + 2) = 0;
        *(short *)(iVar9 + 10) = sVar4;
        uVar8 = uVar13 + uVar10 >> 1;
        *(undefined2 *)(iVar9 + 0xe) = uVar2;
        sVar12 = (short)((int)(uVar10 - uVar13) / 2);
        break;
      case 2:
        *(short *)(iVar9 + 2) = sVar3;
        uVar8 = uVar8 - (uVar10 >> 1) & 0xffff;
        *(undefined2 *)(iVar9 + 10) = 0;
        *(short *)(iVar9 + 0xe) = sVar4;
        if (cVar1 == '\x01') {
          *(short *)(iVar9 + 0x12) = sVar3;
          goto LAB_600cf476;
        }
        *(short *)(iVar9 + 0x1a) = sVar3;
        goto LAB_600cf4ee;
      case 3:
        *(undefined2 *)(iVar9 + 2) = 0;
        *(short *)(iVar9 + 10) = sVar4;
        *(undefined2 *)(iVar9 + 0xe) = uVar2;
        if (cVar1 != '\x01') {
          *(undefined2 *)(iVar9 + 0x1a) = 0;
          goto LAB_600cf4ee;
        }
        *(undefined2 *)(iVar9 + 0x12) = 0;
        goto LAB_600cf476;
      default:
        goto switchD_600cf450_default;
      }
      if (cVar1 == '\x01') {
        *(short *)(iVar9 + 0x12) = sVar12;
LAB_600cf476:
        *(short *)(iVar9 + 0x16) = (short)uVar8;
      }
      else {
        *(short *)(iVar9 + 0x1a) = sVar12;
LAB_600cf4ee:
        *(short *)(iVar9 + 0x1e) = (short)uVar8;
      }
switchD_600cf450_default:
      if (cVar1 == '\x01') {
        iVar11 = 8;
        iVar14 = 10;
        *(undefined2 *)(iVar9 + 0x30) = *(undefined2 *)(param_3 + -2);
      }
      else {
        *(undefined2 *)(iVar9 + 0x32) = *(undefined2 *)(param_3 + -2);
        iVar11 = 4;
        iVar14 = 9;
      }
      uVar7 = (ushort)(1 << iVar14);
      if (*(char *)(param_3 + -4) == '\0') {
        uVar7 = *(ushort *)(iVar9 + 0x22) & ~uVar7;
      }
      else {
        uVar7 = uVar7 | *(ushort *)(iVar9 + 0x22);
      }
      *(ushort *)(iVar9 + 0x22) = uVar7;
      *(ushort *)(param_1 + 0x180) =
           (ushort)(1 << (iVar11 + param_2 & 0xffU)) | *(ushort *)(param_1 + 0x180);
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}


