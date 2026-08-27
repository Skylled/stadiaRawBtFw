// 600cc2d0  FUN_600cc2d0  size=222 bytes
// --- callers ---
//   600cc450 FUN_600cc450
// --- callees ---


undefined4 FUN_600cc2d0(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  byte *pbVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar5 = param_1[2];
  param_3 = (param_1[1] - iVar5) - param_3;
  if (param_3 < 0) {
LAB_600cc38e:
    *(undefined1 *)((int)param_1 + 0xd) = 8;
    *(undefined1 *)(param_1 + 3) = 8;
    uVar1 = 0;
  }
  else {
    pbVar2 = (byte *)(param_2 + -1);
    param_1[2] = iVar5 + 1;
    *(undefined1 *)(*param_1 + iVar5) = 0x22;
    iVar5 = DAT_600cc3b0;
    iVar7 = *param_1 + param_1[2];
    iVar3 = 0;
    while( true ) {
      pbVar2 = pbVar2 + 1;
      bVar4 = *pbVar2;
      uVar6 = (uint)bVar4;
      if (uVar6 == 0) break;
      if (param_3 <= iVar3) goto LAB_600cc38e;
      if (uVar6 - 8 < 6) {
        if (uVar6 == 0xb) goto LAB_600cc33a;
        bVar4 = *(byte *)(uVar6 + iVar5 + -8);
LAB_600cc320:
        if (param_3 - iVar3 < 2) goto LAB_600cc38e;
        iVar9 = iVar3 + 1;
        *(undefined1 *)(iVar7 + iVar3) = 0x5c;
        iVar3 = iVar3 + 2;
        *(byte *)(iVar7 + iVar9) = bVar4;
      }
      else {
        if ((uVar6 == 0x22) || (uVar6 == 0x5c)) goto LAB_600cc320;
LAB_600cc33a:
        if (uVar6 - 0x20 < 0x5f) {
          *(byte *)(iVar7 + iVar3) = bVar4;
          iVar3 = iVar3 + 1;
        }
        else {
          if (param_3 - iVar3 < 6) goto LAB_600cc38e;
          iVar9 = iVar7 + iVar3;
          *(undefined1 *)(iVar7 + iVar3) = 0x5c;
          iVar11 = iVar3 + 4;
          iVar10 = iVar3 + 5;
          *(undefined1 *)(iVar9 + 1) = 0x75;
          iVar3 = iVar3 + 6;
          *(undefined1 *)(iVar9 + 2) = 0x30;
          *(undefined1 *)(iVar9 + 3) = 0x30;
          if (bVar4 >> 4 < 10) {
            cVar8 = '0';
          }
          else {
            cVar8 = 'W';
          }
          *(byte *)(iVar7 + iVar11) = (bVar4 >> 4) + cVar8;
          if ((uVar6 & 0xf) < 10) {
            cVar8 = '0';
          }
          else {
            cVar8 = 'W';
          }
          *(char *)(iVar7 + iVar10) = (char)(uVar6 & 0xf) + cVar8;
        }
      }
    }
    iVar5 = param_1[2];
    *(byte *)((int)param_1 + 0xd) = bVar4;
    param_1[2] = iVar3 + iVar5 + 1;
    uVar1 = 1;
    *(undefined1 *)(*param_1 + iVar3 + iVar5) = 0x22;
  }
  return uVar1;
}


