// 600932bc  FUN_600932bc  size=78 bytes
// --- callers ---
//   600d89ec adapter__600d89ec
// --- callees ---
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_600932bc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x18,DAT_6009330c,0x6c4);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x124;
    *(undefined4 *)(puVar1 + 4) = param_1;
    *(undefined4 *)(puVar1 + 8) = param_3;
    *(undefined4 *)(puVar1 + 6) = param_2;
    *(undefined1 *)(puVar1 + 10) = 1;
    FUN_600962dc(puVar1);
  }
  return;
}


