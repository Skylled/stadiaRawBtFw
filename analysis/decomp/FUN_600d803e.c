// 600d803e  FUN_600d803e  size=20 bytes
// --- callers ---
//   600d808e FUN_600d808e
//   600d9bc6 FUN_600d9bc6
//   60068024 mimxrt10xx_flash_memory__60068024
//   600d8052 FUN_600d8052
//   600d9b8e FUN_600d9b8e
// --- callees ---


int FUN_600d803e(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  return *(int *)(iVar1 + 4) * (*(int *)(param_1 + 8) - *(int *)(iVar1 + 0x14)) +
         param_2 + *(int *)(iVar1 + 0x10);
}


