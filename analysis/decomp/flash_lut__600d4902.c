// 600d4902  flash_lut__600d4902  size=68 bytes
// src: flash_lut.cc
// --- callers ---
// --- callees ---
//   6005fa80 flash_lut__6005fa80


/* src: flash_lut.cc */

uint flash_lut__600d4902(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = flash_lut__6005fa80();
  if ((uVar1 & 0xff) == 0) {
    if (((*(char *)(param_1 + 0xc) == '\x01') && (*(char *)(param_1 + 0x18) == -1)) &&
       (0x39fff < param_2 - 0x6000U)) {
      uVar1 = func_0x6005fb0c(param_1,param_2,param_3,param_4);
      return uVar1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


