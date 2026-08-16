// 600d9b8e  FUN_600d9b8e  size=56 bytes
// --- callers ---
// --- callees ---
//   600d803e FUN_600d803e
//   60067e8c flash_memory__60067e8c


void FUN_600d9b8e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  
  cVar1 = flash_memory__60067e8c();
  if (cVar1 == '\0') {
    piVar3 = *(int **)(param_1 + 4);
    uVar2 = FUN_600d803e(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x600d9bc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar3 + 0x1c))(piVar3,uVar2,param_3,param_4);
    return;
  }
  return;
}


