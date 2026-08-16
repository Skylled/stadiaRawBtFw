// 60042588  FUN_60042588  size=150 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_60042588(int *param_1,undefined4 param_2,int param_3,undefined4 *param_4,uint param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar8;
  
  uVar3 = _DAT_60042628;
  puVar2 = _DAT_60042624;
  puVar1 = _DAT_60042620;
  if ((param_5 < 0x10) || ((param_5 & 0xf) != 0)) {
    cVar4 = '\x03';
  }
  else {
    puVar9 = (undefined4 *)(param_3 + 0x10);
    uVar10 = param_2;
    iVar11 = param_3;
    do {
      puVar5 = _DAT_60042620;
      puVar7 = puVar9 + -4;
      do {
        puVar6 = puVar7 + 1;
        *puVar5 = *puVar7;
        puVar5 = puVar5 + 1;
        puVar7 = puVar6;
      } while (puVar6 != puVar9);
      if (*param_1 == 0) {
        func_0x60041854(uVar3,param_2,puVar1);
      }
      else {
        func_0x6004c054(uVar3,param_2,puVar1,puVar2,0x10,uVar10,iVar11);
      }
      cVar4 = func_0x600491b2();
      if (cVar4 != '\0') {
        return cVar4;
      }
      puVar6 = _DAT_60042624 + 4;
      puVar5 = param_4;
      puVar7 = _DAT_60042624;
      do {
        puVar8 = puVar7 + 1;
        *puVar5 = *puVar7;
        puVar5 = puVar5 + 1;
        puVar7 = puVar8;
      } while (puVar8 != puVar6);
      puVar9 = puVar9 + 4;
      param_4 = param_4 + 4;
    } while (puVar9 != (undefined4 *)(param_3 + param_5 + 0x10));
    cVar4 = '\0';
  }
  return cVar4;
}


