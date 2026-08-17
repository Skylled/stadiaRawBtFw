// 600477e4  queue__600477e4  size=32 bytes
// src: queue.c
// --- callers ---
// --- callees ---
//   60048580 FUN_60048580
//   6004c084 thunk_FUN_601016a2
//   600485c8 FUN_600485c8


/* src: queue.c */

undefined4 queue__600477e4(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    thunk_FUN_601016a2(DAT_60047808,0x76b,DAT_60047804);
  }
  FUN_60048580();
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  FUN_600485c8();
  return uVar1;
}


