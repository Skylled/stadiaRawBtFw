// 600ef57c  FUN_600ef57c  size=66 bytes
// --- callers ---
//   600ef5be FUN_600ef5be
// --- callees ---
//   600ef546 FUN_600ef546
//   600ef510 FUN_600ef510


undefined4 FUN_600ef57c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600ef510(param_1 + 0x1c,param_2 + 0x1c);
  if ((iVar1 == 0) || (iVar1 = FUN_600ef546(param_1,param_2), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


