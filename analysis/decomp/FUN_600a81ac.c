// 600a81ac  FUN_600a81ac  size=116 bytes
// --- callers ---
//   600a51a8 FUN_600a51a8
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac
//   6006dfa4 FUN_6006dfa4


bool FUN_600a81ac(undefined4 param_1,undefined2 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x20,DAT_600a8220,0x1baa);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 8) = param_2;
    *(undefined1 *)(iVar1 + 10) = param_3;
    *(undefined4 *)(iVar1 + 0xc) = param_6;
    *(undefined4 *)(iVar1 + 0x10) = param_7;
    *(undefined4 *)(iVar1 + 0x14) = param_4;
    *(undefined4 *)(iVar1 + 0x18) = param_5;
    *(undefined1 *)(iVar1 + 0x1c) = 1;
    thunk_EXT_FUN_0000b572(iVar1 + 1,param_1,6);
    FUN_6006dfa4(DAT_600a8224,iVar1);
  }
  return iVar1 != 0;
}


