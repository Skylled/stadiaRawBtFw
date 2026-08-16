// 600a8228  FUN_600a8228  size=110 bytes
// --- callers ---
//   600f1b72 FUN_600f1b72
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac
//   6006dfa4 FUN_6006dfa4


bool FUN_600a8228(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined1 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x21,DAT_600a8298,0x1be6);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = param_3;
    *(int *)(iVar1 + 0x10) = iVar1 + 0x20;
    **(undefined1 **)(iVar1 + 0x10) = *param_4;
    *(undefined1 *)(iVar1 + 0x1c) = param_2;
    thunk_EXT_FUN_0000b572(iVar1 + 1,param_1,6);
    FUN_6006dfa4(DAT_600a829c,iVar1);
  }
  return iVar1 != 0;
}


