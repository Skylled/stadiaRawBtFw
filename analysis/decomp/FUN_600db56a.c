// 600db56a  FUN_600db56a  size=62 bytes
// --- callers ---
// --- callees ---
//   600db43e FUN_600db43e
//   6013cf78 thunk_EXT_FUN_000065c4
//   60084b64 FUN_60084b64


undefined4 FUN_600db56a(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 8) == 3) && (*(char *)(param_1 + 0x10) == '\a')) {
    *(undefined4 *)(param_2 + 8) = 0xd;
    *(undefined1 *)(param_2 + 0x20) = 1;
    uVar1 = FUN_60084b64();
    FUN_600db43e(uVar1,param_2 + 0x24);
    *(undefined1 *)(param_2 + 0x78) = 1;
    uVar1 = thunk_EXT_FUN_000065c4();
    FUN_600db43e(uVar1,param_2 + 0x7c);
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


