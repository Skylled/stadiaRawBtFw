// 600e04c8  FUN_600e04c8  size=44 bytes
// --- callers ---
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   6013d048 thunk_EXT_FUN_0000ac06


void FUN_600e04c8(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = param_1;
    do {
      iVar2 = iVar1 + 0x10;
      thunk_EXT_FUN_0000ac06(iVar1);
      iVar1 = iVar2;
    } while (iVar2 != param_1 + 0x100);
    thunk_EXT_FUN_0000ac5e(*(undefined4 *)(param_1 + 0x108));
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}


