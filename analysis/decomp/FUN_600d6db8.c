// 600d6db8  FUN_600d6db8  size=34 bytes
// --- callers ---
//   600666f0 keys__600666f0
//   60065eb8 keys__60065eb8
// --- callees ---
//   60101ba2 FUN_60101ba2
//   60050c18 FUN_60050c18


int * FUN_600d6db8(int *param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


