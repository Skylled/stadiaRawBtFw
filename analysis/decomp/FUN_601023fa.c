// 601023fa  FUN_601023fa  size=80 bytes
// --- callers ---
//   600cdc90 FUN_600cdc90
// --- callees ---
//   600cdca0 FUN_600cdca0
//   6010244a thunk_FUN_600ce1d8


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int FUN_601023fa(void)

{
  undefined4 *in_r0;
  int iVar1;
  uint in_r1;
  code *pcVar2;
  
  if (in_r1 < 0x20) {
    iVar1 = in_r0[0x11];
    if ((iVar1 == 0) || (pcVar2 = *(code **)(iVar1 + in_r1 * 4), pcVar2 == (code *)0x0)) {
      thunk_FUN_600ce1d8();
      iVar1 = FUN_600cdca0();
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


