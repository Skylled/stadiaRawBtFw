// 6009598c  FUN_6009598c  size=60 bytes
// --- callers ---
//   600d89a6 FUN_600d89a6
//   60069c58 adapter__60069c58
//   600d88f4 FUN_600d88f4
// --- callees ---
//   6006dbac FUN_6006dbac
//   600962dc FUN_600962dc


void FUN_6009598c(undefined2 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(8,DAT_600959c8,0x209);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x1e0e;
    puVar1[3] = param_1;
    FUN_600962dc(puVar1);
  }
  return;
}


