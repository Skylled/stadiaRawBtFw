// 6008b384  bcm__6008b384  size=48 bytes
// src: bcm.c
// --- callers ---
//   6008e264 bcm__6008e264
//   600e0a54 FUN_600e0a54
//   600e732a FUN_600e732a
//   600eda00 FUN_600eda00
//   6008b570 bcm__6008b570
//   600ea77a FUN_600ea77a
//   600e7490 FUN_600e7490
// --- callees ---
//   600e092c FUN_600e092c
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e0552 FUN_600e0552


/* src: bcm.c */

int bcm__6008b384(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_600e092c(0x14);
  if (iVar1 == 0) {
    FUN_600e0552(3,0,0x41,DAT_6008b3b4,0x49,param_2);
  }
  else {
    thunk_EXT_FUN_0000af90(iVar1,0,0x14);
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  return iVar1;
}


