// 600af314  FUN_600af314  size=50 bytes
// --- callers ---
//   600ab110 FUN_600ab110
// --- callees ---
//   6006dfa4 FUN_6006dfa4
//   6006dbac FUN_6006dbac


undefined4 * FUN_600af314(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_6006dbac(4,DAT_600af348,0xeb);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    FUN_6006dfa4(DAT_600af34c,puVar1);
  }
  return puVar1;
}


