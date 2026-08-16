// 600af1a4  FUN_600af1a4  size=46 bytes
// --- callers ---
//   600b02e0 FUN_600b02e0
// --- callees ---
//   600d9250 FUN_600d9250
//   6006ddd8 FUN_6006ddd8


void FUN_600af1a4(int *param_1)

{
  undefined4 uVar1;
  
  while (*param_1 != 0) {
    uVar1 = FUN_600d9250(param_1);
    FUN_6006ddd8(uVar1,DAT_600af1d4,0x65);
  }
  return;
}


