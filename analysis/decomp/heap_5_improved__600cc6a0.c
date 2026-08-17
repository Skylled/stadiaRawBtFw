// 600cc6a0  heap_5_improved__600cc6a0  size=50 bytes
// src: heap_5_improved.c
// --- callers ---
//   60051b50 stats__60051b50
// --- callees ---
//   6013d2d0 thunk_EXT_FUN_0000713c
//   6013d0e0 thunk_EXT_FUN_0000728c
//   601016a2 FUN_601016a2


/* src: heap_5_improved.c */

uint heap_5_improved__600cc6a0(void)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  
  if (*DAT_600cc6d4 == 0) {
    FUN_601016a2(DAT_600cc6dc,0xdd,DAT_600cc6d8);
  }
  thunk_EXT_FUN_0000713c();
  piVar3 = DAT_600cc6e0;
  uVar4 = 0;
  while (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0) {
    puVar1 = (uint *)(piVar3 + 1);
    piVar3 = piVar2;
    if (uVar4 < *puVar1) {
      uVar4 = *puVar1;
    }
  }
  thunk_EXT_FUN_0000728c();
  return uVar4;
}


