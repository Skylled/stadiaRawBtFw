// 600df3d8  FUN_600df3d8  size=136 bytes
// --- callers ---
// --- callees ---


void FUN_600df3d8(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_2 + 4))(param_2,param_1,param_3,*(code **)(*param_2 + 4),param_4);
  if ((((cVar1 == '\0') &&
       (cVar1 = (**(code **)(*param_2 + 8))(param_2,param_1,param_1 + 0x168), cVar1 == '\0')) &&
      (cVar1 = (**(code **)(*param_2 + 8))(param_2,param_1,param_1 + 0x124), cVar1 == '\0')) &&
     (((cVar1 = (**(code **)(*param_2 + 8))(param_2,param_1,param_1 + 0xe0), cVar1 == '\0' &&
       (cVar1 = (**(code **)(*param_2 + 8))(param_2,param_1,param_1 + 0x9c), cVar1 == '\0')) &&
      ((cVar1 = (**(code **)(*param_2 + 8))(param_2,param_1,param_1 + 0x58), cVar1 == '\0' &&
       (cVar1 = (**(code **)(*param_2 + 8))(param_2,param_1,param_1 + 0x14), cVar1 == '\0')))))) {
    *(int **)(param_1 + 0x10) = param_2;
  }
  return;
}


