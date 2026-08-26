// 600d8052  FUN_600d8052  size=60 bytes
// --- callers ---
//   60067f5c mimxrt10xx_flash_memory__60067f5c
//   600d80f4 FUN_600d80f4
// --- callees ---
//   60067e8c flash_memory__60067e8c
//   600d803e FUN_600d803e


void FUN_600d8052(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  
  cVar1 = flash_memory__60067e8c(param_1,param_3,param_4);
  if (cVar1 == '\0') {
    piVar3 = *(int **)(param_1 + 4);
    uVar2 = FUN_600d803e(param_1,param_3);
                    /* WARNING: Could not recover jumptable at 0x600d8088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar3 + 0x14))(piVar3,param_2,uVar2,param_4);
    return;
  }
  return;
}


