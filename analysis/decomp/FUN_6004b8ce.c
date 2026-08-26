// 6004b8ce  FUN_6004b8ce  size=112 bytes
// --- callers ---
// --- callees ---
//   6004bab0 FUN_6004bab0
//   60047aa8 tasks__60047aa8
//   6004723c queue__6004723c
//   60047834 queue__60047834
//   60047678 queue__60047678
//   6004baa8 FUN_6004baa8
//   60047958 FUN_60047958


undefined4 FUN_6004b8ce(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_1c;
  int *local_18;
  int local_14;
  
  local_1c = param_2;
  local_18 = (int *)param_3;
  local_14 = param_4;
  local_14 = queue__6004723c(1,0,3,param_4,param_1);
  if (local_14 == 0) {
    uVar2 = 0xc;
  }
  else {
    FUN_60047958();
    local_18 = (int *)*param_1;
    local_1c = *local_18;
    if (local_1c != 0) {
      *(int **)(local_1c + 4) = &local_1c;
    }
    *local_18 = (int)&local_1c;
    tasks__60047aa8();
    FUN_6004bab0(param_2);
    iVar1 = queue__60047678(local_14,param_3);
    if (iVar1 == 1) {
      uVar2 = 0;
    }
    else {
      FUN_60047958();
      if (local_1c != 0) {
        *(int **)(local_1c + 4) = local_18;
      }
      uVar2 = 0x74;
      *local_18 = local_1c;
      tasks__60047aa8();
    }
    queue__60047834(local_14);
    FUN_6004baa8(param_2);
  }
  return uVar2;
}


