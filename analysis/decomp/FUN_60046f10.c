// 60046f10  FUN_60046f10  size=40 bytes
// --- callers ---
//   60046ed4 FUN_60046ed4
// --- callees ---
//   60046ffc FUN_60046ffc


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60046f10(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  func_0x6004b49c(_DAT_60046f3c,_DAT_60046f38);
  if ((*_DAT_60046f40 == 0) || (iVar2 = FUN_60046ffc(*_DAT_60046f44), iVar2 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(iVar2 + param_1 * 4);
  }
  return uVar1;
}


