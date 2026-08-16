// 600c405e  FUN_600c405e  size=2 bytes
// --- callers ---
// --- callees ---


void FUN_600c405e(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined2 *puVar1;
  
  *param_3 = param_2;
  puVar1 = (undefined2 *)FUN_6006dbac(10,DAT_600c40ac,0x967);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x205;
    puVar1[4] = 2;
    FUN_600962dc(puVar1);
  }
  return;
}


