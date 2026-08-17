// 600b7374  FUN_600b7374  size=178 bytes
// --- callers ---
//   600bc00c FUN_600bc00c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006ddd8 FUN_6006ddd8
//   600d9250 FUN_600d9250
//   600aa4c4 FUN_600aa4c4
//   600f82c4 FUN_600f82c4


void FUN_600b7374(int param_1)

{
  undefined4 uVar1;
  
  FUN_600f82c4(param_1);
  if (*(int *)(param_1 + 0xc0) != 0) {
    FUN_6006ddd8(*(undefined4 *)(param_1 + 0xc0),DAT_600b7428,0xdf);
  }
  while (*(int *)(param_1 + 0xc4) != 0) {
    uVar1 = FUN_600d9250(param_1 + 0xc4);
    FUN_6006ddd8(uVar1,DAT_600b7428,0xe2);
  }
  while (*(int *)(param_1 + 0xd0) != 0) {
    uVar1 = FUN_600d9250(param_1 + 0xd0);
    FUN_6006ddd8(uVar1,DAT_600b7428,0xe5);
  }
  while (*(int *)(param_1 + 0xdc) != 0) {
    uVar1 = FUN_600d9250(param_1 + 0xdc);
    FUN_6006ddd8(uVar1,DAT_600b7428,0xe8);
  }
  FUN_600aa4c4(param_1 + 0xe8);
  FUN_600aa4c4(param_1 + 0x100);
  thunk_EXT_FUN_0000b5ba(param_1 + 0xb0,0,0x68);
  return;
}


