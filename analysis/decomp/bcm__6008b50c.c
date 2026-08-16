// 6008b50c  bcm__6008b50c  size=50 bytes
// src: bcm.c
// --- callers ---
//   6008d120 bcm__6008d120
//   600e9a8e FUN_600e9a8e
//   6008d7ac bcm__6008d7ac
//   6008eb24 bcm__6008eb24
//   6008e910 bcm__6008e910
//   6008db50 bcm__6008db50
//   6008e700 bcm__6008e700
//   6008d228 bcm__6008d228
// --- callees ---
//   600e092c FUN_600e092c
//   600e0552 FUN_600e0552


/* src: bcm.c */

undefined4 * bcm__6008b50c(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_600e092c(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_600e0552(3,0,0x41,DAT_6008b540,0x6f,param_2);
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    *(undefined2 *)(puVar1 + 5) = 0;
  }
  return puVar1;
}


