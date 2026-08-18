// 600c4070  FUN_600c4070  size=58 bytes
// --- callers ---
// --- callees ---
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_600c4070(undefined2 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(10,DAT_600c40ac,0x967);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x205;
    puVar1[4] = param_1;
    FUN_600962dc(puVar1);
  }
  return;
}


