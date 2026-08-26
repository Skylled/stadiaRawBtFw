// 600d4752  FUN_600d4752  size=32 bytes
// --- callers ---
//   60078340 firmware_image_upload__60078340
//   60067f5c mimxrt10xx_flash_memory__60067f5c
//   60068024 mimxrt10xx_flash_memory__60068024
//   600d80f4 FUN_600d80f4
//   60061684 partition_table__60061684
// --- callees ---


void FUN_600d4752(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
                    /* WARNING: Could not recover jumptable at 0x600d4770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x20))
            (piVar1,piVar1[1] * (*(int *)(param_1 + 8) - piVar1[5]) + param_2 + piVar1[4]);
  return;
}


