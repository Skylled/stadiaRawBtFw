// 600dc292  FUN_600dc292  size=124 bytes
// --- callers ---
//   600dc30e FUN_600dc30e
// --- callees ---
//   600dc248 FUN_600dc248
//   600dc8f4 FUN_600dc8f4
//   6013d310 thunk_EXT_FUN_0000b52a
//   600dc25e FUN_600dc25e
//   600dbff4 FUN_600dbff4
//   600dbfba FUN_600dbfba
//   600dbfec FUN_600dbfec
//   6013d068 thunk_EXT_FUN_0000b52e


int FUN_600dc292(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x280);
  if (iVar1 != 0) {
    FUN_600dc8f4(iVar1);
    thunk_EXT_FUN_0000b52e(iVar1,0x4b0);
  }
  FUN_600dbfec(*(undefined4 *)(param_1 + 0x274));
  FUN_600dc248(*(undefined4 *)(param_1 + 0x268),*(undefined4 *)(param_1 + 0x26c));
  if (*(int *)(param_1 + 0x268) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  if (*(int *)(param_1 + 0x264) != 0) {
    FUN_600dc25e();
  }
  if (*(int *)(param_1 + 600) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  if (*(int *)(param_1 + 0x254) != 0) {
    thunk_EXT_FUN_0000b52e(*(int *)(param_1 + 0x254),0x60);
  }
  if (*(int *)(param_1 + 0x250) != 0) {
    thunk_EXT_FUN_0000b52e(*(int *)(param_1 + 0x250),0x80);
  }
  if (*(int *)(param_1 + 0x1cc) != 0) {
    FUN_600dbfba();
  }
  if (*(int *)(param_1 + 0x1c8) != 0) {
    FUN_600dbff4();
  }
  return param_1;
}


