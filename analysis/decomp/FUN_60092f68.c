// 60092f68  FUN_60092f68  size=72 bytes
// --- callers ---
//   6006c370 FUN_6006c370
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60092f68(undefined4 param_1,undefined1 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x10,DAT_60092fb0,0x2d7);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x113;
    FUN_600efcc6(puVar1 + 4,param_1);
    *(undefined1 *)(puVar1 + 7) = param_2;
    FUN_600962dc(puVar1);
  }
  return;
}


