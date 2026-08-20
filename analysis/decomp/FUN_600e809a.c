// 600e809a  FUN_600e809a  size=72 bytes
// --- callers ---
//   600e863c FUN_600e863c
//   600e87fa FUN_600e87fa
// --- callees ---
//   600e7f7a FUN_600e7f7a
//   600e7412 FUN_600e7412


int FUN_600e809a(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = param_2;
  uVar3 = param_3;
  iVar1 = FUN_600e7f7a(param_6);
  FUN_600e7f7a(param_1,param_3,param_2,param_4,-param_5,uVar2,uVar3);
  if (param_5 < 0) {
    param_5 = -param_5;
  }
  FUN_600e7412(param_1,-iVar1,param_1,param_6,param_5 + param_4);
  return -iVar1;
}


