// 600e0bee  FUN_600e0bee  size=16 bytes
// --- callers ---
//   6008ffc0 tasn_dec__6008ffc0
// --- callees ---


undefined4 FUN_600e0bee(int *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar1 = func_0x600e0ba8(param_1,*param_1 + -1);
    return uVar1;
  }
  return 0;
}


