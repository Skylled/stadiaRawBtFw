// 600cdc90  FUN_600cdc90  size=16 bytes
// --- callers ---
//   6010209a FUN_6010209a
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_600cdc90(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_lr;
  undefined1 *puVar5;
  
  piVar1 = _DAT_20003d80;
  puVar5 = &DAT_20003d80;
  if (param_1 < 0x20) {
    iVar2 = _DAT_20003d80[0x11];
    if ((iVar2 == 0) || (pcVar4 = *(code **)(iVar2 + param_1 * 4), pcVar4 == (code *)0x0)) {
      uVar3 = thunk_FUN_600ce1d8(_DAT_20003d80);
      _DAT_2002a820 = 0;
      iVar2 = FUN_600ce1e8(uVar3,param_1,param_1,0,puVar5,unaff_r4,unaff_r5,unaff_lr);
      if ((iVar2 == -1) && (_DAT_2002a820 != 0)) {
        *piVar1 = _DAT_2002a820;
      }
      return iVar2;
    }
    if (pcVar4 != (code *)0x1) {
      if (pcVar4 == (code *)0xffffffff) {
        *_DAT_20003d80 = 0x16;
        return 1;
      }
      *(undefined4 *)(iVar2 + param_1 * 4) = 0;
      (*pcVar4)(param_1);
    }
    iVar2 = 0;
  }
  else {
    *_DAT_20003d80 = 0x16;
    iVar2 = -1;
  }
  return iVar2;
}


