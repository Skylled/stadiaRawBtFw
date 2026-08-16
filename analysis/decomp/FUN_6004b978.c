// 6004b978  FUN_6004b978  size=48 bytes
// --- callers ---
// --- callees ---
//   60047290 queue__60047290
//   6004b93e FUN_6004b93e
//   60047aa8 tasks__60047aa8
//   60047958 FUN_60047958


int FUN_6004b978(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar1 = FUN_6004b93e();
  if (iVar1 == 0) {
    piVar4 = (int *)*param_1;
    FUN_60047958();
    while (piVar2 = (int *)*piVar4, piVar2 != (int *)0x0) {
      uVar3 = piVar2[2];
      *piVar4 = *piVar2;
      queue__60047290(uVar3,0,0,0,param_4);
    }
    tasks__60047aa8();
  }
  return iVar1;
}


