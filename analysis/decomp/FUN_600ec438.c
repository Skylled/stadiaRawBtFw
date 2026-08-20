// 600ec438  FUN_600ec438  size=220 bytes
// --- callers ---
//   600ec7ca FUN_600ec7ca
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


int FUN_600ec438(int *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar8 = *param_1;
  uVar9 = param_1[1] & 0x100;
  if (iVar8 == 0) {
    if (param_2 == (int *)0x0) {
      return 1;
    }
    puVar7 = (undefined1 *)*param_2;
    iVar8 = 1;
    goto LAB_600ec472;
  }
  pbVar4 = (byte *)param_1[2];
  bVar1 = *pbVar4;
  if ((iVar8 == 1) && (bVar1 == 0)) {
    uVar9 = 0;
LAB_600ec492:
    iVar5 = 0;
    iVar2 = iVar5;
  }
  else if (uVar9 == 0) {
    iVar5 = 0;
    if (bVar1 < 0x80) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if (bVar1 < 0x81) {
      pbVar6 = pbVar4;
      if (bVar1 != 0x80) goto LAB_600ec492;
      do {
        pbVar6 = pbVar6 + 1;
        if (iVar8 <= (int)pbVar6 - (int)pbVar4) {
          iVar5 = 0;
          iVar2 = iVar5;
          goto LAB_600ec466;
        }
      } while (*pbVar6 == 0);
    }
    iVar5 = 0xff;
    iVar2 = 1;
  }
LAB_600ec466:
  iVar8 = iVar8 + iVar2;
  if (param_2 == (int *)0x0) {
    return iVar8;
  }
  puVar7 = (undefined1 *)*param_2;
  if (iVar2 != 0) {
    *puVar7 = (char)iVar5;
    puVar7 = puVar7 + 1;
  }
LAB_600ec472:
  iVar5 = *param_1;
  if (iVar5 == 0) {
    *puVar7 = 0;
  }
  else {
    iVar2 = param_1[2];
    if (uVar9 == 0) {
      thunk_EXT_FUN_0000b572(puVar7);
    }
    else {
      iVar3 = iVar2 + iVar5;
      pbVar4 = puVar7 + iVar5 + -1;
      while( true ) {
        pbVar6 = pbVar4 + -1;
        if ((*(char *)(iVar3 + -1) != '\0') || ((iVar5 + iVar3 + -1) - (iVar2 + iVar5 + -1) < 2))
        break;
        *pbVar4 = 0;
        iVar3 = iVar3 + -1;
        pbVar4 = pbVar6;
      }
      *pbVar4 = -*(char *)(iVar3 + -1);
      pbVar4 = (byte *)(iVar3 + -2);
      for (; 0 < (int)(pbVar6 + (iVar5 - (int)(puVar7 + iVar5 + -1))); pbVar6 = pbVar6 + -1) {
        *pbVar6 = ~*pbVar4;
        pbVar4 = pbVar4 + -1;
      }
    }
  }
  *param_2 = *param_2 + iVar8;
  return iVar8;
}


