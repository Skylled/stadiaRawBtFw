// 6007b59c  append_buffer__6007b59c  size=90 bytes
// src: append_buffer.h
// --- callers ---
//   600dbf72 FUN_600dbf72
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588
//   600ce2a0 FUN_600ce2a0
//   60101740 FUN_60101740


/* src: append_buffer.h */

void append_buffer__6007b59c(uint *param_1,uint param_2)

{
  uint uVar1;
  undefined1 auStack_a8 [152];
  
  if (param_1[1] < param_2) {
    FUN_600ce2a0(auStack_a8,DAT_6007b5fc,DAT_6007b5f8,0x12);
    FUN_60101740(auStack_a8);
  }
  if (param_1[1] == param_2) {
    param_1[1] = 0;
  }
  else {
    uVar1 = param_1[1] - param_2;
    thunk_EXT_FUN_0000b588(param_1[2],param_1[2] + param_2 * 2,uVar1 * 2);
    param_1[1] = uVar1;
  }
  if (*param_1 < param_1[1]) {
    FUN_600ce2a0(auStack_a8,DAT_6007b5fc,DAT_6007b5f8,0x1c);
    FUN_60101740(auStack_a8);
  }
  return;
}


