// 6009c7c8  FUN_6009c7c8  size=44 bytes
// --- callers ---
//   600f7f30 FUN_600f7f30
// --- callees ---
//   6006dbac FUN_6006dbac
//   6006dfa4 FUN_6006dfa4


void FUN_6009c7c8(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_6006dbac(4,DAT_6009c7f4,0x2f1);
  *puVar1 = param_1;
  FUN_6006dfa4(DAT_6009c7f8,puVar1);
  return;
}


