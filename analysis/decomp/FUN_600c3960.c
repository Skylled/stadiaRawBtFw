// 600c3960  FUN_600c3960  size=86 bytes
// --- callers ---
// --- callees ---
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_600c3960(int param_1)

{
  undefined2 *puVar1;
  
  if ((DAT_600c39b8[2] & 0x3fffffff) != 0) {
    (*(code *)*DAT_600c39b8)(2,param_1 + 8);
  }
  puVar1 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c39bc,0x761);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x206;
    puVar1[3] = 0x202;
    FUN_600962dc(puVar1);
  }
  return;
}


