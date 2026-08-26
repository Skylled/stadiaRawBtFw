// 6010179a  FUN_6010179a  size=26 bytes
// --- callers ---
//   601017b4 FUN_601017b4
// --- callees ---
//   6013d2d0 thunk_EXT_FUN_0000713c
//   600ca27c tasks__600ca27c
//   6013d0e0 thunk_EXT_FUN_0000728c


void FUN_6010179a(int param_1)

{
  undefined4 uVar1;
  
  thunk_EXT_FUN_0000713c();
  uVar1 = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x58) = 0;
  tasks__600ca27c(uVar1);
  thunk_EXT_FUN_0000728c();
  return;
}


