// 600af350  FUN_600af350  size=56 bytes
// --- callers ---
//   600ada6c FUN_600ada6c
//   600adb54 FUN_600adb54
// --- callees ---
//   6006dfa4 FUN_6006dfa4
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572


int FUN_600af350(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(7,DAT_600af388,0x102);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b572(iVar1,param_1,7);
    FUN_6006dfa4(DAT_600af38c,iVar1);
  }
  return iVar1;
}


