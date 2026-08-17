// 600cae18  timers__600cae18  size=22 bytes
// src: timers.c
// --- callers ---
//   6005d3b4 thermal__6005d3b4
// --- callees ---
//   601016a2 FUN_601016a2


/* src: timers.c */

undefined4 timers__600cae18(int param_1)

{
  if (param_1 == 0) {
    FUN_601016a2(DAT_600cae34,0x1b5,DAT_600cae30);
  }
  return *(undefined4 *)(param_1 + 0x18);
}


