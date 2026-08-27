// 6005f3e0  FUN_6005f3e0  size=52 bytes
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   600ceaf8 FUN_600ceaf8
//   601017e8 FUN_601017e8
//   6013cf40 thunk_EXT_FUN_00007d10
//   60052bb0 FUN_60052bb0
//   6013d3d8 thunk_EXT_FUN_0000b4c2


undefined4 FUN_6005f3e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  iVar1 = param_1 + 4;
  iStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  FUN_601017e8(iVar1);
  thunk_EXT_FUN_0000b4c2(iVar1);
  FUN_600ceaf8(&iStack_18);
  FUN_60052bb0(DAT_6005f414,&iStack_18);
  *(undefined1 *)(param_1 + 0x58) = 1;
  thunk_EXT_FUN_00007d10(iVar1);
  return 0;
}


