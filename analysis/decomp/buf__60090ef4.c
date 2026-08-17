// 60090ef4  buf__60090ef4  size=44 bytes
// src: buf.c
// --- callers ---
//   600861c0 pem_lib__600861c0
// --- callees ---
//   600e092c FUN_600e092c
//   600e0552 FUN_600e0552


/* src: buf.c */

undefined4 * buf__60090ef4(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_600e092c(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_600e0552(7,0,0x41,DAT_60090f20,0x48,param_2);
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  return puVar1;
}


