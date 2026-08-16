// 60041c50  FUN_60041c50  size=58 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60041c50(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  puVar1 = _DAT_60041c94;
  iVar5 = *(int *)(_DAT_60041c90 + 4);
  iVar3 = *_DAT_60041c8c;
  *_DAT_60041c8c = iVar5;
  uVar2 = _DAT_60041c9c;
  uVar6 = iVar5 - iVar3;
  uVar7 = *puVar1;
  uVar4 = *_DAT_60041c98;
  *puVar1 = uVar7 + uVar6;
  puVar1[1] = puVar1[1] + (uint)CARRY4(uVar7,uVar6);
  func_0x6004c414(*puVar1,puVar1[1],uVar4 / uVar2,0);
  return;
}


