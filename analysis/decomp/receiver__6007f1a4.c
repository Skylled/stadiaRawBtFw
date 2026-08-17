// 6007f1a4  receiver__6007f1a4  size=78 bytes
// src: receiver.cc
// --- callers ---
// --- callees ---
//   600debc8 FUN_600debc8
//   6010165c FUN_6010165c


/* src: receiver.cc */

void receiver__6007f1a4(int param_1,undefined4 param_2,undefined4 param_3,undefined3 param_4)

{
  if (*(int *)(param_1 + 0x9c0) == *(int *)(param_1 + 0x9c8)) {
    FUN_6010165c(0x1e,DAT_6007f1f8,0xa5,DAT_6007f1f4,param_1);
  }
  else {
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    FUN_600debc8(param_1 + 0x9bc,*(undefined4 *)(param_1 + 0x990),*(undefined4 *)(param_1 + 0x994),
                 param_1 + 0x998,&stack0xfffffff7,param_2,param_3,
                 CONCAT13(*(char *)(param_1 + 0x9d0) != '\0',param_4));
  }
  return;
}


