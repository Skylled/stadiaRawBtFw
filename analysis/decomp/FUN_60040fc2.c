// 60040fc2  FUN_60040fc2  size=10 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60040fc2(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = _DAT_60040fd0;
  piVar6 = (int *)*_DAT_60040fcc;
  uVar9 = *(uint *)(_DAT_60040fd0 + 0x14);
  iVar2 = FUN_60040864(_DAT_60040fd0,uVar9 & 0xff);
  if ((iVar2 != 0) &&
     (UNRECOVERED_JUMPTABLE = (code *)piVar6[4], UNRECOVERED_JUMPTABLE != (code *)0x0)) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffff794;
    *piVar6 = 0;
                    /* WARNING: Could not recover jumptable at 0x60040eb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar1,piVar6,iVar2,piVar6[5]);
    return;
  }
  if (((int)(uVar9 << 0x1a) < 0) && (*piVar6 == 2)) {
    uVar8 = piVar6[2];
    iVar2 = ((*(uint *)(iVar1 + 0xb8) & 0x3f) >> 2) + 1;
    if (uVar8 < (uint)(iVar2 * 8)) {
      bVar7 = 0;
      while( true ) {
        if ((uVar8 >> 2) + 1 <= (uint)bVar7) break;
        puVar4 = (undefined4 *)piVar6[1];
        uVar5 = *(undefined4 *)(iVar1 + (bVar7 + 0x40) * 4);
        piVar6[1] = (int)(puVar4 + 1);
        *puVar4 = uVar5;
        bVar7 = bVar7 + 1;
      }
      iVar2 = 0;
    }
    else {
      bVar7 = 0;
      while( true ) {
        uVar3 = (uint)bVar7;
        bVar7 = bVar7 + 1;
        if ((uint)(iVar2 * 2) <= uVar3) break;
        puVar4 = (undefined4 *)piVar6[1];
        uVar5 = *(undefined4 *)(iVar1 + (uVar3 + 0x40) * 4);
        piVar6[1] = (int)(puVar4 + 1);
        *puVar4 = uVar5;
      }
      iVar2 = uVar8 + iVar2 * -8;
    }
    piVar6[2] = iVar2;
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x20;
  }
  if ((int)(uVar9 << 0x1f) < 0) {
    UNRECOVERED_JUMPTABLE = (code *)piVar6[4];
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 1;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffff794;
    *piVar6 = 0;
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      (*UNRECOVERED_JUMPTABLE)(iVar1,piVar6,0,piVar6[5]);
    }
  }
  if ((((int)(uVar9 << 0x19) < 0) && (*piVar6 == 1)) && (uVar9 = piVar6[2], uVar9 != 0)) {
    iVar2 = ((*(uint *)(iVar1 + 0xbc) & 0x3f) >> 2) + 1;
    if (uVar9 < (uint)(iVar2 * 8)) {
      bVar7 = 0;
      while( true ) {
        if ((uVar9 >> 2) + 1 <= (uint)bVar7) break;
        uVar5 = *(undefined4 *)piVar6[1];
        piVar6[1] = (int)((undefined4 *)piVar6[1] + 1);
        *(undefined4 *)(iVar1 + (bVar7 + 0x60) * 4) = uVar5;
        bVar7 = bVar7 + 1;
      }
      iVar2 = 0;
    }
    else {
      bVar7 = 0;
      while( true ) {
        uVar8 = (uint)bVar7;
        bVar7 = bVar7 + 1;
        if ((uint)(iVar2 * 2) <= uVar8) break;
        uVar5 = *(undefined4 *)piVar6[1];
        piVar6[1] = (int)((undefined4 *)piVar6[1] + 1);
        *(undefined4 *)(iVar1 + (uVar8 + 0x60) * 4) = uVar5;
      }
      iVar2 = uVar9 + iVar2 * -8;
    }
    piVar6[2] = iVar2;
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x40;
  }
  return;
}


