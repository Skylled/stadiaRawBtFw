// 600aa858  FUN_600aa858  size=70 bytes
// --- callers ---
//   600aae30 FUN_600aae30
// --- callees ---
//   6006dfa4 FUN_6006dfa4
//   6006dbac FUN_6006dbac


bool FUN_600aa858(int param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(8,DAT_600aa8a0,0xa9);
  if (puVar1 != (undefined2 *)0x0) {
    *(undefined4 *)(puVar1 + 2) = param_3;
    *puVar1 = param_2;
    FUN_6006dfa4(param_1 + 0x14,puVar1);
  }
  return puVar1 != (undefined2 *)0x0;
}


