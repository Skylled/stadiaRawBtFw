// 6009decc  FUN_6009decc  size=64 bytes
// --- callers ---
//   600a30f0 FUN_600a30f0
//   600a2180 FUN_600a2180
// --- callees ---
//   600aaeec FUN_600aaeec
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600aa3cc FUN_600aa3cc


undefined1 FUN_6009decc(undefined4 param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = DAT_6009df0c;
  uVar2 = FUN_600aaeec(param_1);
  *(undefined1 *)(iVar1 + 0x32) = 0;
  thunk_EXT_FUN_0000b5ba(iVar1 + 0x2c,0,6);
  FUN_600aa3cc(iVar1 + 4);
  return uVar2;
}


