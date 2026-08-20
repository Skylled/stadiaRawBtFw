// 600eb3a4  FUN_600eb3a4  size=92 bytes
// --- callers ---
//   600eb400 FUN_600eb400
//   600eb428 FUN_600eb428
// --- callees ---
//   600e7554 FUN_600e7554
//   600eadd0 FUN_600eadd0
//   600eb370 FUN_600eb370


undefined4 FUN_600eb3a4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((((iVar3 == 0) || (iVar4 = *(int *)(param_2 + 4), iVar4 == 0)) ||
      (iVar1 = FUN_600e7554(param_1 + 8,param_2 + 8,param_3,param_4,param_4), iVar1 != 0)) ||
     (((iVar1 = FUN_600e7554(param_1 + 0x24,param_2 + 0x24), iVar1 != 0 ||
       (iVar1 = FUN_600eadd0(param_1,param_1 + 0x38,param_2 + 0x38), iVar1 == 0)) ||
      (iVar1 = FUN_600eadd0(param_1,param_1 + 0x7c,param_2 + 0x7c), iVar1 == 0)))) {
    uVar2 = 1;
  }
  else {
    iVar3 = FUN_600eb370(param_1,iVar3 + 4,iVar4 + 4);
    uVar2 = 0;
    if (iVar3 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}


