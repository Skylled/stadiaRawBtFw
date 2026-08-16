// 600957ec  FUN_600957ec  size=60 bytes
// --- callers ---
//   6006a880 gatt_server__6006a880
// --- callees ---
//   6006dbac FUN_6006dbac
//   600962dc FUN_600962dc


void FUN_600957ec(undefined2 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(8,DAT_60095828,0x126);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x1e08;
    puVar1[3] = param_1;
    FUN_600962dc(puVar1);
  }
  return;
}


