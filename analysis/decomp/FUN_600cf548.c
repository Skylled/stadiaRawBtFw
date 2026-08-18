// 600cf548  FUN_600cf548  size=210 bytes
// --- callers ---
//   600d4c3a FUN_600d4c3a
//   600d4cae FUN_600d4cae
// --- callees ---


void FUN_600cf548(int param_1,int param_2,int param_3,undefined4 param_4,byte param_5)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  
  uVar6 = (uint)param_5;
  switch(param_4) {
  case 0:
    param_1 = param_2 * 0x60 + param_1;
    uVar1 = (ushort)((uVar6 * (*(ushort *)(param_1 + 0xe) & 0x7fff) * 2) / 100);
    uVar5 = uVar1 >> 1;
    sVar3 = -(uVar1 >> 1);
    break;
  case 1:
    param_1 = param_2 * 0x60 + param_1;
    uVar4 = (uint)*(ushort *)(param_1 + 0xe);
    uVar6 = (uVar4 * uVar6) / 100 & 0xffff;
    uVar2 = (undefined2)((int)(uVar4 - uVar6) / 2);
    if (param_3 == 1) {
      *(undefined2 *)(param_1 + 0x12) = uVar2;
      uVar5 = (ushort)(uVar6 + uVar4 >> 1);
      goto LAB_600cf5b6;
    }
    *(undefined2 *)(param_1 + 0x1a) = uVar2;
    uVar5 = (ushort)(uVar6 + uVar4 >> 1);
    goto LAB_600cf5c0;
  case 2:
    param_1 = param_2 * 0x60 + param_1;
    uVar1 = *(ushort *)(param_1 + 0xe);
    uVar5 = (short)((uVar6 * (uVar1 & 0x7fff) * 2) / 100) - uVar1;
    if (param_3 != 1) {
      *(ushort *)(param_1 + 0x1a) = -uVar1;
      goto LAB_600cf5c0;
    }
    *(ushort *)(param_1 + 0x12) = -uVar1;
    goto LAB_600cf5b6;
  case 3:
    param_1 = param_2 * 0x60 + param_1;
    sVar3 = 0;
    uVar5 = (ushort)((uVar6 * *(ushort *)(param_1 + 0xe)) / 100);
    break;
  default:
    goto switchD_600cf552_default;
  }
  if (param_3 == 1) {
    *(short *)(param_1 + 0x12) = sVar3;
LAB_600cf5b6:
    *(ushort *)(param_1 + 0x16) = uVar5;
  }
  else {
    *(short *)(param_1 + 0x1a) = sVar3;
LAB_600cf5c0:
    *(ushort *)(param_1 + 0x1e) = uVar5;
  }
switchD_600cf552_default:
  return;
}


