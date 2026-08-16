// 60042300  FUN_60042300  size=268 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60042300(undefined1 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  uint *puVar2;
  char *pcVar3;
  uint *puVar4;
  byte *pbVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined8 uVar14;
  undefined4 uStack_4;
  
  pcVar3 = _DAT_60042424;
  puVar2 = _DAT_6004240c;
  if (*_DAT_60042424 != '\0') {
    uStack_4 = param_4;
    if (*_DAT_6004240c == 0) {
      func_0x6004c304(0x1e,_DAT_60042414,0x7c,_DAT_60042410);
      *pcVar3 = '\0';
    }
    else {
      uVar10 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar10 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      uVar14 = func_0x60042978(_DAT_60042418);
      puVar4 = _DAT_60042428;
      iVar11 = *_DAT_6004241c;
      *(undefined8 *)_DAT_6004241c = uVar14;
      pbVar5 = _DAT_6004242c;
      uVar9 = *puVar4;
      uVar12 = *puVar2;
      uVar7 = *puVar4 + 1 + (param_3 >> 1);
      *puVar4 = uVar7 - uVar12 * (uVar7 / uVar12);
      bVar6 = *pbVar5;
      if (*puVar4 < uVar9) {
        bVar6 = bVar6 | 1;
      }
      *pbVar5 = bVar6;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar10 & 1) == 1);
      }
      iVar8 = *_DAT_60042420;
      if (*_DAT_60042420 == 0) {
        iVar8 = _DAT_60042430;
      }
      iVar11 = (int)uVar14 - iVar11;
      iVar13 = iVar8 + uVar9 * 8;
      *(char *)(iVar13 + 1) = (char)iVar11;
      *(char *)(iVar13 + 2) = (char)((uint)iVar11 >> 8);
      *(char *)(iVar13 + 3) = (char)((uint)iVar11 >> 0x10);
      *(undefined1 *)(iVar8 + uVar9 * 8) = param_1;
      *(undefined4 *)(iVar13 + 4) = param_2;
      if (param_3 != 0) {
        for (uVar10 = 0; param_3 >> 1 != uVar10; uVar10 = uVar10 + 1) {
          uVar7 = *puVar2;
          uVar9 = (uVar9 + 1) - uVar7 * ((uVar9 + 1) / uVar7);
          *(undefined1 *)(iVar8 + uVar9 * 8) = 0;
          iVar13 = iVar8 + uVar9 * 8;
          *(undefined1 *)(iVar13 + 1) = *(undefined1 *)(&uStack_4 + uVar10 * 2);
          iVar11 = uVar10 * 8;
          *(undefined1 *)(iVar13 + 2) = *(undefined1 *)((int)&uStack_4 + iVar11 + 1);
          *(undefined1 *)(iVar13 + 3) = *(undefined1 *)((int)&uStack_4 + iVar11 + 2);
          *(undefined4 *)(iVar13 + 4) = *(undefined4 *)(&stack0x00000000 + iVar11);
        }
      }
    }
  }
  return;
}


