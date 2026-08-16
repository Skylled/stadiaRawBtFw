// 600af170  FUN_600af170  size=48 bytes
// --- callers ---
//   600b02e0 FUN_600b02e0
// --- callees ---
//   600d9250 FUN_600d9250
//   6006ddd8 FUN_6006ddd8


void FUN_600af170(int param_1)

{
  undefined4 uVar1;
  
  while (*(int *)(param_1 + 0x68) != 0) {
    uVar1 = FUN_600d9250(param_1 + 0x68);
    FUN_6006ddd8(uVar1,DAT_600af1a0,0x54);
  }
  return;
}


