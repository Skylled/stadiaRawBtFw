// 600d94fc  FUN_600d94fc  size=30 bytes
// --- callers ---
// --- callees ---
//   6007014c FUN_6007014c


void FUN_600d94fc(undefined2 *param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_6007014c(0);
                    /* WARNING: Could not recover jumptable at 0x600d9518. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0xc))(piVar1,param_2,*param_1,param_1[1]);
  return;
}


