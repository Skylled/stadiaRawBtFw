// 600b0730  FUN_600b0730  size=56 bytes
// --- callers ---
//   600ac438 FUN_600ac438
// --- callees ---
//   6006dbac FUN_6006dbac
//   6006dfa4 FUN_6006dfa4


undefined4 * FUN_600b0730(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_6006dbac(4,DAT_600b0768,0xab4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    FUN_6006dfa4(param_1,puVar1);
  }
  return puVar1;
}


