// 600d73ac  FUN_600d73ac  size=148 bytes
// --- callers ---
//   600667fc FUN_600667fc
// --- callees ---
//   600d7272 FUN_600d7272


int FUN_600d73ac(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_1c;
  
  local_1c = param_3;
  for (iVar3 = param_2 - param_1 >> 2; 0 < iVar3; iVar3 = iVar3 + -1) {
    iVar1 = FUN_600d7272(&local_1c,param_1);
    if (iVar1 != 0) {
      return param_1;
    }
    iVar1 = FUN_600d7272(&local_1c,param_1 + 1);
    if (iVar1 != 0) {
      return param_1 + 1;
    }
    iVar1 = FUN_600d7272(&local_1c,param_1 + 2);
    if (iVar1 != 0) {
      return param_1 + 2;
    }
    iVar2 = param_1 + 3;
    param_1 = param_1 + 4;
    iVar1 = FUN_600d7272(&local_1c,iVar2);
    if (iVar1 != 0) {
      return iVar2;
    }
  }
  iVar3 = param_2 - param_1;
  if (iVar3 != 2) {
    if (iVar3 != 3) {
      if (iVar3 != 1) {
        return param_2;
      }
      goto LAB_600d740e;
    }
    iVar3 = FUN_600d7272(&local_1c,param_1);
    if (iVar3 != 0) {
      return param_1;
    }
    param_1 = param_1 + 1;
  }
  iVar3 = FUN_600d7272(&local_1c,param_1);
  if (iVar3 != 0) {
    return param_1;
  }
  param_1 = param_1 + 1;
LAB_600d740e:
  iVar3 = FUN_600d7272(&local_1c,param_1);
  if (iVar3 == 0) {
    return param_2;
  }
  return param_1;
}


