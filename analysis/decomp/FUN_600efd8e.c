// 600efd8e  FUN_600efd8e  size=90 bytes
// --- callers ---
//   60096314 FUN_60096314
// --- callees ---
//   6006e3b0 FUN_6006e3b0
//   6006e2d0 FUN_6006e2d0
//   6006e154 FUN_6006e154
//   6006e214 FUN_6006e214


void FUN_600efd8e(int *param_1,int param_2,undefined2 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = FUN_6006e154();
    param_1[4] = iVar1;
    FUN_6006e3b0((char)param_1[5],param_1[3],1);
  }
  FUN_6006e2d0(param_1,param_2);
  *(undefined2 *)(param_2 + 0x14) = param_3;
  *(undefined4 *)(param_2 + 0xc) = param_4;
  FUN_6006e214(param_1,param_2);
  return;
}


