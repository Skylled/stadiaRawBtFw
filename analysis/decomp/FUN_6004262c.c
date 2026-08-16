// 6004262c  FUN_6004262c  size=130 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_6004262c(undefined4 param_1,byte *param_2,byte *param_3,uint param_4,undefined4 *param_5)

{
  byte *pbVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 *puVar10;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  undefined4 *puVar11;
  
  pcVar3 = _DAT_600426b0;
  pcVar9 = _DAT_600426b0;
  puVar10 = param_5;
  do {
    puVar11 = puVar10 + 1;
    *(undefined4 *)pcVar9 = *puVar10;
    uVar6 = _DAT_600426bc;
    iVar5 = _DAT_600426b4;
    pcVar4 = _DAT_600426b0;
    pcVar9 = pcVar9 + 4;
    puVar10 = puVar11;
    pbVar14 = param_2;
    pbVar15 = param_3;
  } while (puVar11 != param_5 + 4);
  do {
    if (param_4 == 0) {
      return 0;
    }
    func_0x60041854(uVar6,param_1,pcVar4,iVar5,0x10,pbVar14,pbVar15);
    uVar7 = func_0x600491b2();
    if ((uVar7 & 0xff) != 0) {
      return uVar7;
    }
    uVar7 = 0;
    uVar8 = param_4;
    pbVar12 = param_2;
    pbVar13 = param_3;
    if (0xf < param_4) {
      uVar8 = 0x10;
    }
    do {
      pbVar1 = (byte *)(uVar7 + iVar5);
      uVar7 = uVar7 + 1;
      param_2 = pbVar12 + 1;
      param_3 = pbVar13 + 1;
      *pbVar13 = *pbVar12 ^ *pbVar1;
      pbVar12 = param_2;
      pbVar13 = param_3;
    } while (uVar7 < uVar8);
    param_4 = param_4 - uVar8;
    pcVar9 = _DAT_600426b8;
    do {
      pcVar9 = pcVar9 + -1;
      cVar2 = *pcVar9;
      *pcVar9 = cVar2 + '\x01';
      if ((char)(cVar2 + '\x01') != '\0') break;
    } while (pcVar3 != pcVar9);
  } while( true );
}


