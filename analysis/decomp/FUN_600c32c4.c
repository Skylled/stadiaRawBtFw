// 600c32c4  FUN_600c32c4  size=68 bytes
// --- callers ---
// --- callees ---
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_600c32c4(undefined2 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c3308,0x59f);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x206;
    puVar1[3] = 0x208;
    puVar1[2] = param_1;
    FUN_600962dc(puVar1);
  }
  return;
}


