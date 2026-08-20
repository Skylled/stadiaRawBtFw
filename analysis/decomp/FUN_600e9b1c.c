// 600e9b1c  FUN_600e9b1c  size=70 bytes
// --- callers ---
//   600e9b62 FUN_600e9b62
// --- callees ---
//   600e9a40 FUN_600e9a40
//   600e7450 FUN_600e7450
//   600e7e9c FUN_600e7e9c


undefined4 FUN_600e9b1c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  iVar3 = param_2;
  iVar1 = FUN_600e7450(param_3);
  uVar4 = 1;
  if ((iVar1 != 1) && (iVar2 = FUN_600e9a40(param_1,iVar1 + -1), uVar4 = 0, iVar2 != 0)) {
    iVar3 = FUN_600e7e9c(param_1,param_1,(param_2 + 1) - iVar1,param_3,param_4,iVar3);
    uVar4 = 0;
    if (iVar3 != 0) {
      uVar4 = 1;
    }
  }
  return uVar4;
}


