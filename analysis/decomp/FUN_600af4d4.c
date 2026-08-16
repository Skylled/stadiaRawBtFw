// 600af4d4  FUN_600af4d4  size=66 bytes
// --- callers ---
//   600ab318 FUN_600ab318
//   600ab110 FUN_600ab110
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006ddd8 FUN_6006ddd8
//   600d9250 FUN_600d9250


void FUN_600af4d4(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    while (*(int *)(param_1 + 0x40) != 0) {
      uVar1 = FUN_600d9250(param_1 + 0x40);
      FUN_6006ddd8(uVar1,DAT_600af518,0x171);
    }
    thunk_EXT_FUN_0000b5ba(param_1,0,0x58);
  }
  return;
}


