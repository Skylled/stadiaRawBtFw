// 600dcc10  FUN_600dcc10  size=70 bytes
// --- callers ---
//   600dc8f6 FUN_600dc8f6
//   600dcc56 FUN_600dcc56
// --- callees ---
//   6007dd28 FUN_6007dd28
//   600dcb9e FUN_600dcb9e
//   600de276 FUN_600de276
//   600dcbb6 FUN_600dcbb6
//   6013d378 thunk_EXT_FUN_0000b532


void FUN_600dcc10(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_6007dd28(param_1 + 0x1c);
  FUN_600de276(param_1 + 0x4c);
  uVar1 = thunk_EXT_FUN_0000b532(0xc);
  FUN_600dcbb6(uVar1,0x50,0x80);
  iVar2 = *(int *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  if (iVar2 != 0) {
    FUN_600dcb9e();
  }
  *(undefined4 *)(param_1 + 0x140) = param_2;
  *(undefined4 *)(param_1 + 0x144) = 2;
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x14c) = 1;
  return;
}


