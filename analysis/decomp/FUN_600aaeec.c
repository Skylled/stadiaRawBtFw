// 600aaeec  FUN_600aaeec  size=70 bytes
// --- callers ---
//   6009decc FUN_6009decc
// --- callees ---
//   600aa6f0 FUN_600aa6f0
//   600f3caa FUN_600f3caa


undefined4 FUN_600aaeec(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600aa6f0(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if ((*(char *)(iVar1 + 0x11) == '\0') &&
          (iVar1 = FUN_600f3caa(*(undefined1 *)(DAT_600aaf34 + 0x140),param_1,1), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


