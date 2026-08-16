// 60095650  FUN_60095650  size=58 bytes
// --- callers ---
//   600d89a6 FUN_600d89a6
// --- callees ---
//   6006dbac FUN_6006dbac
//   600962dc FUN_600962dc


void FUN_60095650(undefined1 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(10,DAT_6009568c,0x75);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x1e02;
    *(undefined1 *)(puVar1 + 4) = param_1;
    FUN_600962dc(puVar1);
  }
  return;
}


