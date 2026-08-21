// 600ecbbe  FUN_600ecbbe  size=12 bytes
// --- callers ---
//   6008fa18 tasn_dec__6008fa18
// --- callees ---


undefined4 FUN_600ecbbe(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(*param_1 + *(int *)(param_3 + 4));
  *(undefined4 *)(*param_1 + *(int *)(param_3 + 4)) = param_2;
  return uVar1;
}


