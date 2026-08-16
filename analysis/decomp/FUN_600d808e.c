// 600d808e  FUN_600d808e  size=66 bytes
// --- callers ---
// --- callees ---
//   600d803e FUN_600d803e
//   60067e8c flash_memory__60067e8c


uint FUN_600d808e(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (*(char *)(param_1 + 0x10) == '\x01') {
    uVar1 = 7;
  }
  else {
    uVar1 = flash_memory__60067e8c(param_1,param_2,param_3 * *(int *)(*(int *)(param_1 + 4) + 4));
    if ((uVar1 & 0xff) == 0) {
      piVar3 = *(int **)(param_1 + 4);
      uVar2 = FUN_600d803e(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x600d80ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(*piVar3 + 0x10))(piVar3,uVar2,param_3);
      return uVar1;
    }
  }
  return uVar1;
}


