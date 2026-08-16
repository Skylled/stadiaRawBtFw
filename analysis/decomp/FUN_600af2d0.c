// 600af2d0  FUN_600af2d0  size=64 bytes
// --- callers ---
//   600f367e FUN_600f367e
// --- callees ---
//   6006dfa4 FUN_6006dfa4
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572


int FUN_600af2d0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x262,DAT_600af310,0xd1);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b572(iVar1,param_2,0x262);
    FUN_6006dfa4(param_1 + 0x68,iVar1);
  }
  return iVar1;
}


