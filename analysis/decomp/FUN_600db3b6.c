// 600db3b6  FUN_600db3b6  size=38 bytes
// --- callers ---
//   60078218 FUN_60078218
//   60078340 firmware_image_upload__60078340
// --- callees ---
//   600653f0 FUN_600653f0
//   6007818c partition_table__6007818c


void FUN_600db3b6(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  *(undefined1 *)(param_1 + 0x114) = 1;
  *(undefined1 *)(param_1 + 1) = 0;
  uVar1 = FUN_600653f0();
  puVar2 = (undefined4 *)partition_table__6007818c(uVar1,*(undefined1 *)(param_1 + 8));
                    /* WARNING: Could not recover jumptable at 0x600db3da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*puVar2)(puVar2,0,1);
  return;
}


