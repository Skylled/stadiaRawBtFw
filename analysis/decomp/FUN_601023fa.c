// 601023fa  FUN_601023fa  size=80 bytes
// --- callers ---
// --- callees ---
//   6010244a thunk_FUN_600ce1d8


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int FUN_601023fa(void)

{
  int *in_r0;
  int iVar1;
  uint in_r1;
  code *pcVar2;
  
  if (in_r1 < 0x20) {
    iVar1 = in_r0[0x11];
    if ((iVar1 == 0) || (pcVar2 = *(code **)(iVar1 + in_r1 * 4), pcVar2 == (code *)0x0)) {
      thunk_FUN_600ce1d8();
      _DAT_2002a820 = 0;
      iVar1 = FUN_600ce1e8();
      if ((iVar1 == -1) && (_DAT_2002a820 != 0)) {
        *in_r0 = _DAT_2002a820;
      }
      return iVar1;
    }
    if (pcVar2 != (code *)0x1) {
      if (pcVar2 == (code *)0xffffffff) {
        *in_r0 = 0x16;
        return 1;
      }
      *(undefined4 *)(iVar1 + in_r1 * 4) = 0;
      (*pcVar2)();
    }
    iVar1 = 0;
  }
  else {
    *in_r0 = 0x16;
    iVar1 = -1;
  }
  return iVar1;
}


