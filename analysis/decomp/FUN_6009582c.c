// 6009582c  FUN_6009582c  size=72 bytes
// --- callers ---
//   60068f88 activation_sequence__60068f88
// --- callees ---
//   6006dbac FUN_6006dbac
//   600962dc FUN_600962dc


void FUN_6009582c(undefined2 param_1,undefined1 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(10,DAT_60095874,0x142);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x1e09;
    puVar1[3] = param_1;
    *(undefined1 *)(puVar1 + 4) = param_2;
    FUN_600962dc(puVar1);
  }
  return;
}


