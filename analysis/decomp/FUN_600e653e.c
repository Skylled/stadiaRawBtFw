// 600e653e  FUN_600e653e  size=148 bytes
// --- callers ---
//   600e69c2 FUN_600e69c2
//   600eb588 FUN_600eb588
//   600e66be FUN_600e66be
// --- callees ---
//   600e2308 FUN_600e2308


void FUN_600e653e(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  bool bVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c [2];
  
  bVar1 = param_2 != 0;
  FUN_600e2308(&local_38,bVar1,*param_3,*param_4);
  FUN_600e2308(&local_34,bVar1,param_3[1],param_4[1]);
  FUN_600e2308(&local_30,bVar1,param_3[2],param_4[2]);
  FUN_600e2308(&local_2c,bVar1,param_3[3],param_4[3]);
  FUN_600e2308(&local_28,bVar1,param_3[4],param_4[4]);
  FUN_600e2308(&local_24,bVar1,param_3[5],param_4[5]);
  FUN_600e2308(&local_20,bVar1,param_3[6],param_4[6]);
  FUN_600e2308(local_1c,bVar1,param_3[7],param_4[7]);
  *param_1 = local_38;
  param_1[1] = local_34;
  param_1[2] = local_30;
  param_1[3] = local_2c;
  param_1[4] = local_28;
  param_1[5] = local_24;
  param_1[6] = local_20;
  param_1[7] = local_1c[0];
  return;
}


