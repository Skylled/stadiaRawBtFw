// 600cdc90  FUN_600cdc90  size=16 bytes
// --- callers ---
//   6010209a FUN_6010209a
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int FUN_600cdc90(void)

{
  int *piVar1;
  uint in_r0;
  int iVar2;
  code *pcVar3;
  
  piVar1 = _DAT_20003d80;
  if (in_r0 < 0x20) {
    iVar2 = _DAT_20003d80[0x11];
    if ((iVar2 == 0) || (pcVar3 = *(code **)(iVar2 + in_r0 * 4), pcVar3 == (code *)0x0)) {
      thunk_FUN_600ce1d8(_DAT_20003d80);
      _DAT_2002a820 = 0;
      iVar2 = FUN_600ce1e8();
      if ((iVar2 == -1) && (_DAT_2002a820 != 0)) {
        *piVar1 = _DAT_2002a820;
      }
      return iVar2;
    }
    if (pcVar3 != (code *)0x1) {
      if (pcVar3 == (code *)0xffffffff) {
        *_DAT_20003d80 = 0x16;
        return 1;
      }
      *(undefined4 *)(iVar2 + in_r0 * 4) = 0;
      (*pcVar3)();
    }
    iVar2 = 0;
  }
  else {
    *_DAT_20003d80 = 0x16;
    iVar2 = -1;
  }
  return iVar2;
}


