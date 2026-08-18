// 600d0bc8  FUN_600d0bc8  size=56 bytes
// --- callers ---
//   600d07d4 FUN_600d07d4
//   600d0a90 FUN_600d0a90
//   600d0a4e FUN_600d0a4e
// --- callees ---
//   60054f7c FUN_60054f7c
//   60054f30 FUN_60054f30
//   6005505c FUN_6005505c


void FUN_600d0bc8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_14;
  
  local_14 = param_2;
  iVar1 = FUN_60054f7c(param_1,&local_14,param_3,param_4,param_1);
  if (iVar1 == 0) {
    if (param_2 == 1) {
      FUN_60054f30(param_1,local_14);
      FUN_6005505c(param_1,2,local_14);
    }
    (**(code **)(*(int *)(local_14 + 4) + 4))(param_1,param_2,param_3);
  }
  return;
}


