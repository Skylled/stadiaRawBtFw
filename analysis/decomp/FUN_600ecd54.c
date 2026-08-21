// 600ecd54  FUN_600ecd54  size=190 bytes
// --- callers ---
//   60090d24 FUN_60090d24
// --- callees ---
//   600ecce2 FUN_600ecce2


undefined4 FUN_600ecd54(undefined1 *param_1,undefined4 *param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined1 uVar6;
  
  cVar2 = *param_3;
  iVar7 = FUN_600ecce2(cVar2);
  cVar3 = param_3[1];
  iVar8 = FUN_600ecce2(cVar3);
  cVar4 = param_3[2];
  iVar9 = FUN_600ecce2(cVar4);
  cVar1 = param_3[3];
  uVar10 = FUN_600ecce2(cVar1);
  if ((((iVar7 != 0xff) && (iVar8 != 0xff)) && (iVar9 != 0xff)) && (uVar10 != 0xff)) {
    if (cVar2 == '=') {
      uVar11 = 8;
    }
    else {
      uVar11 = 0;
    }
    uVar10 = iVar8 << 0xc | iVar7 << 0x12 | uVar10 | iVar9 << 6;
    if (cVar3 == '=') {
      uVar12 = 4;
    }
    else {
      uVar12 = 0;
    }
    if (cVar4 == '=') {
      uVar13 = 2;
    }
    else {
      uVar13 = 0;
    }
    if (cVar1 == '=') {
      uVar11 = uVar11 | 1;
    }
    uVar13 = uVar11 | uVar12 | uVar13;
    uVar5 = (undefined1)(uVar10 >> 8);
    uVar6 = (undefined1)(uVar10 >> 0x10);
    if (uVar13 == 1) {
      *param_2 = 2;
      *param_1 = uVar6;
      param_1[1] = uVar5;
      return 1;
    }
    if (uVar13 == 3) {
      *param_2 = 1;
      *param_1 = uVar6;
      return 1;
    }
    if (uVar13 == 0) {
      *param_2 = 3;
      param_1[2] = (char)uVar10;
      *param_1 = uVar6;
      param_1[1] = uVar5;
      return 1;
    }
  }
  return 0;
}


