// 600adc88  FUN_600adc88  size=84 bytes
// --- callers ---
//   600f622a FUN_600f622a
//   600adeb4 FUN_600adeb4
//   600f6be6 FUN_600f6be6
// --- callees ---
//   600d9250 FUN_600d9250
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006ddd8 FUN_6006ddd8


void FUN_600adc88(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_6006ddd8(*(undefined4 *)(param_1 + 0x28),DAT_600adcdc,0x5a);
  }
  while (*(int *)(param_1 + 0x48) != 0) {
    uVar1 = FUN_600d9250(param_1 + 0x48);
    FUN_6006ddd8(uVar1,DAT_600adcdc,0x5e);
  }
  thunk_EXT_FUN_0000b5ba(param_1 + 0x28,0,0x3c);
  return;
}


