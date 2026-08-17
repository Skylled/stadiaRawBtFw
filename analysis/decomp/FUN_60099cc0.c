// 60099cc0  FUN_60099cc0  size=84 bytes
// --- callers ---
//   600f2e9c FUN_600f2e9c
// --- callees ---
//   60098f34 FUN_60098f34


void FUN_60099cc0(undefined2 param_1,undefined2 param_2)

{
  byte bVar1;
  
  if (*(int *)(DAT_60099d14 + 0x648) != 0) {
    bVar1 = FUN_60098f34(param_1);
    if (bVar1 < 4) {
      (**(code **)(DAT_60099d14 + 0x648))((uint)bVar1 * 0x14c + DAT_60099d14 + 0x116,param_2);
    }
  }
  return;
}


