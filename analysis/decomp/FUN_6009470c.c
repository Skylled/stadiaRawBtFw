// 6009470c  FUN_6009470c  size=66 bytes
// --- callers ---
//   600c2b3c FUN_600c2b3c
//   600c4da8 FUN_600c4da8
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_6009470c(undefined4 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x12,DAT_60094750,0x402);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x1d0c;
    thunk_EXT_FUN_0000b572(puVar1 + 4,param_1,6);
    FUN_600962dc(puVar1);
  }
  return;
}


