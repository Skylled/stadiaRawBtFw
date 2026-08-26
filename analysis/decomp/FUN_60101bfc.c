// 60101bfc  FUN_60101bfc  size=34 bytes
// --- callers ---
//   6010165c FUN_6010165c
//   601016a2 FUN_601016a2
// --- callees ---
//   600cdd6c FUN_600cdd6c
//   60101ba2 FUN_60101ba2


undefined1 FUN_60101bfc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_600cdd6c(param_1[2] + *param_1,param_1[1] - param_1[2],param_2,param_3);
  FUN_60101ba2(param_1,uVar1);
  return *(undefined1 *)((int)param_1 + 0xd);
}


