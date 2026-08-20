// 600ec600  FUN_600ec600  size=166 bytes
// --- callers ---
//   60090568 FUN_60090568
//   600ec8b4 FUN_600ec8b4
//   600902e4 FUN_600902e4
// --- callees ---


void FUN_600ec600(undefined4 *param_1,int param_2,int param_3,int param_4,byte param_5)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte bVar7;
  int iVar8;
  
  if (param_2 == 0) {
    bVar7 = 0;
  }
  else {
    bVar7 = 0x20;
  }
  pbVar6 = (byte *)*param_1;
  pbVar5 = pbVar6 + 1;
  bVar7 = param_5 & 0xc0 | bVar7;
  if (param_4 < 0x1f) {
    *pbVar6 = bVar7 | (byte)param_4 & 0x1f;
  }
  else {
    *pbVar6 = bVar7 | 0x1f;
    iVar1 = param_4;
    iVar3 = 0;
    do {
      iVar8 = iVar3;
      iVar1 = iVar1 >> 7;
      iVar3 = iVar8 + 1;
      iVar4 = iVar3;
    } while (iVar1 != 0);
    while (iVar4 != 0) {
      bVar7 = (byte)param_4 & 0x7f;
      param_4 = param_4 >> 7;
      if (iVar4 + -1 != iVar8) {
        bVar7 = bVar7 | 0x80;
      }
      pbVar6[iVar4] = bVar7;
      iVar4 = iVar4 + -1;
    }
    pbVar5 = pbVar5 + iVar3;
  }
  pbVar6 = pbVar5 + 1;
  if (param_2 == 2) {
    *pbVar5 = 0x80;
  }
  else if (param_3 < 0x80) {
    *pbVar5 = (byte)param_3;
  }
  else {
    iVar3 = 0;
    iVar1 = param_3;
    do {
      iVar1 = iVar1 >> 8;
      iVar3 = iVar3 + 1;
    } while (iVar1 != 0);
    *pbVar5 = (byte)iVar3 | 0x80;
    for (pbVar2 = pbVar5 + iVar3; pbVar5 != pbVar2; pbVar2 = pbVar2 + -1) {
      *pbVar2 = (byte)param_3;
      param_3 = param_3 >> 8;
    }
    pbVar6 = pbVar6 + iVar3;
  }
  *param_1 = pbVar6;
  return;
}


