// 60099d8c  FUN_60099d8c  size=64 bytes
// --- callers ---
//   600f2cd8 FUN_600f2cd8
// --- callees ---
//   60098f34 FUN_60098f34


void FUN_60099d8c(undefined2 param_1,undefined2 param_2)

{
  byte bVar1;
  
  bVar1 = FUN_60098f34(param_1);
  if (bVar1 < 4) {
    *(undefined2 *)((uint)bVar1 * 0x14c + DAT_60099dcc + 0x114) = param_2;
  }
  return;
}


