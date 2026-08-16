// 6009430c  FUN_6009430c  size=98 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_6009430c(undefined4 param_1,undefined1 param_2,undefined2 param_3,undefined1 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x14,DAT_60094370,0x391);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x111;
    *(undefined1 *)(puVar1 + 7) = param_2;
    puVar1[8] = param_3;
    *(undefined1 *)(puVar1 + 9) = param_4;
    FUN_600efcc6(puVar1 + 4,param_1);
    FUN_600962dc(puVar1);
  }
  return;
}


