// 601003da  FUN_601003da  size=74 bytes
// --- callers ---
//   60100166 FUN_60100166
// --- callees ---
//   6010039a FUN_6010039a
//   60100362 FUN_60100362


int FUN_601003da(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_6010039a(param_1,param_2);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_60100362(*(undefined4 *)((iVar1 + 0x3fffffff) * 4 + param_1));
    iVar2 = iVar2 + (iVar1 + -1) * 0x20;
  }
  return iVar2;
}


