// 6007b694  frames__6007b694  size=36 bytes
// src: frames.h
// --- callers ---
//   6007b6c0 append_buffer__6007b6c0
// --- callees ---
//   600ce2a0 FUN_600ce2a0
//   60101740 FUN_60101740


/* src: frames.h */

int frames__6007b694(uint param_1,uint param_2)

{
  undefined1 auStack_a8 [156];
  
  if (param_1 < param_2) {
    FUN_600ce2a0(auStack_a8,DAT_6007b6bc,DAT_6007b6b8,0x58);
    FUN_60101740(auStack_a8);
  }
  return param_1 - param_2;
}


