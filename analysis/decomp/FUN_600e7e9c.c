// 600e7e9c  FUN_600e7e9c  size=48 bytes
// --- callers ---
//   600e9b1c FUN_600e9b1c
// --- callees ---
//   600e72fc FUN_600e72fc
//   600e7e8a FUN_600e7e8a


undefined4
FUN_600e7e9c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = param_4;
  iVar1 = FUN_600e72fc();
  if (iVar1 == 0) {
LAB_600e7eaa:
    uVar2 = 0;
  }
  else {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      iVar3 = FUN_600e7e8a(param_1,param_1,param_4,param_5,uVar2);
      if (iVar3 == 0) goto LAB_600e7eaa;
    }
    uVar2 = 1;
  }
  return uVar2;
}


