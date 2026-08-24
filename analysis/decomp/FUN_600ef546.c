// 600ef546  FUN_600ef546  size=54 bytes
// --- callers ---
//   600ef57c FUN_600ef57c
//   600eedee FUN_600eedee
// --- callees ---
//   600ef510 FUN_600ef510


undefined4 FUN_600ef546(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(char *)(param_1 + 0x18) == *(char *)(param_2 + 0x18)) &&
     (iVar1 = FUN_600ef510(param_1,param_2), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


