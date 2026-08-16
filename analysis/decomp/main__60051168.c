// 60051168  main__60051168  size=96 bytes
// src: main.cc
// --- callers ---
//   6004c700 FUN_6004c700
// --- callees ---
//   600cbdd4 init__600cbdd4
//   600cbdc8 xbara__600cbdc8
//   600ce2a0 FUN_600ce2a0
//   60101740 FUN_60101740
//   600617fc FUN_600617fc


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* src: main.cc */

void main__60051168(void)

{
  undefined4 extraout_r3;
  undefined1 auStack_150 [152];
  undefined1 *puStack_b8;
  undefined4 uStack_a0;
  undefined1 uStack_9c;
  undefined4 uStack_98;
  
  FUN_600617fc();
  if (_DAT_2002a828 != -0x55445545) {
    FUN_600ce2a0(&uStack_a0,s_FreeRTOS_CHECK_failed_60122ce9 + 9,s_main_cc_6011aebe,0x13f);
    FUN_60101740(&uStack_a0);
  }
  xbara__600cbdc8(0x60051241);
  if (_DAT_2002a828 != -0x55445545) {
    FUN_600ce2a0(&uStack_a0,s_FreeRTOS_CHECK_failed_60122ce9 + 9,s_main_cc_6011aebe,0x141);
    FUN_60101740(&uStack_a0);
  }
  init__600cbdd4();
  puStack_b8 = &DAT_2002a828;
  uRam00000002 = uStack_98;
  _DAT_0000000e = uStack_a0;
  _DAT_0000000a = extraout_r3;
  if (&stack0x0000024c == (undefined1 *)0x0) {
    FUN_600ce2a0(auStack_150,DAT_60051238,DAT_60051234,0x4c);
    FUN_60101740(auStack_150);
  }
  _DAT_00000006 = timers__600cad24(0,&stack0x0000024c,uStack_9c,2);
  if (_DAT_00000006 == 0) {
    FUN_600ce2a0(auStack_150,DAT_60051238,DAT_60051234,0x4f);
    FUN_60101740(auStack_150);
  }
                    /* WARNING: Could not recover jumptable at 0x60051232. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x600511b5)(2);
  return;
}


