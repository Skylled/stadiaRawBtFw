// 600aa8a4  FUN_600aa8a4  size=70 bytes
// --- callers ---
//   600f322e FUN_600f322e
// --- callees ---
//   6006ddd8 FUN_6006ddd8
//   600d9250 FUN_600d9250


bool FUN_600aa8a4(int param_1,undefined2 *param_2,undefined4 *param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_600d9250(param_1 + 0x14);
  if (puVar1 != (undefined2 *)0x0) {
    *param_3 = *(undefined4 *)(puVar1 + 2);
    *param_2 = *puVar1;
    FUN_6006ddd8(puVar1,DAT_600aa8ec,200);
  }
  return puVar1 != (undefined2 *)0x0;
}


