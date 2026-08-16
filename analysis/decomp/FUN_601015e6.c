// 601015e6  FUN_601015e6  size=72 bytes
// --- callers ---
//   60058510 FUN_60058510
// --- callees ---
//   601015ba FUN_601015ba
//   6010156a FUN_6010156a
//   6010155c FUN_6010155c


uint FUN_601015e6(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_6010156a(param_1,*(int *)(param_2 + 0x14) + 0x11);
  if ((uVar1 & 0xff) == 0) {
    FUN_601015ba(param_1,param_2,*param_1 + param_1[2]);
    iVar2 = *(int *)(*param_1 + param_1[2]) + param_1[2] + 0x10;
    param_1[2] = iVar2;
    if (iVar2 == param_1[1]) {
      param_1[2] = 0;
    }
    if (param_1[2] == param_1[3]) {
      FUN_6010155c(param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


