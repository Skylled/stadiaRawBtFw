// 6008f0a0  a_object__6008f0a0  size=52 bytes
// src: a_object.c
// --- callers ---
//   6008f0d8 a_object__6008f0d8
// --- callees ---
//   600e092c FUN_600e092c
//   600e0552 FUN_600e0552


/* src: a_object.c */

undefined4 * a_object__6008f0a0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_600e092c(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_600e0552(0xc,0,0x41,DAT_6008f0d4,0xec,param_2);
  }
  else {
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[5] = 1;
  }
  return puVar1;
}


