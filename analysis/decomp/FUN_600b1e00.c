// 600b1e00  FUN_600b1e00  size=84 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a9234 FUN_600a9234


bool FUN_600b1e00(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x103,DAT_600b1e54,0x36);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = param_2;
    *(undefined2 *)(iVar1 + 4) = 0;
    thunk_EXT_FUN_0000b572(iVar1 + 8,param_1,param_2);
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}


