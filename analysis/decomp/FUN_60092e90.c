// 60092e90  FUN_60092e90  size=72 bytes
// --- callers ---
//   600d89ec adapter__600d89ec
// --- callees ---
//   601024d8 FUN_601024d8
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60092e90(undefined4 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x102,DAT_60092ed8,0xc5);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x102;
    FUN_601024d8(puVar1 + 4,param_1,0xf8);
    *(undefined1 *)(puVar1 + 0x80) = 0;
    FUN_600962dc(puVar1);
  }
  return;
}


