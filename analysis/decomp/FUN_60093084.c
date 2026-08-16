// 60093084  FUN_60093084  size=82 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60093084(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x10,DAT_600930d8,0x394);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x110;
    FUN_600efcc6(puVar1 + 4,param_1);
    *(undefined1 *)(puVar1 + 7) = param_2;
    *(undefined1 *)((int)puVar1 + 0xf) = param_3;
    FUN_600962dc(puVar1);
  }
  return;
}


