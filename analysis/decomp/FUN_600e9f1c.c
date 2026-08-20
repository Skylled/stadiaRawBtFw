// 600e9f1c  FUN_600e9f1c  size=198 bytes
// --- callers ---
//   60085f2c pem_lib__60085f2c
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   600e9e24 FUN_600e9e24


uint FUN_600e9f1c(int *param_1,int param_2,int *param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  if ((*(uint *)(iVar4 + 0x14) & 0x400) == 0) {
    if (param_5 < 1) {
      *param_3 = 0;
      return (uint)(param_5 == 0);
    }
    if (param_1[5] << 0x14 < 0) {
      uVar1 = FUN_600e9e24();
      return uVar1;
    }
    iVar2 = param_1[0x18];
    uVar1 = *(uint *)(iVar4 + 4);
    iVar4 = param_2;
    if (iVar2 != 0) {
      iVar4 = param_2 + uVar1;
      thunk_EXT_FUN_0000af88(param_2,param_1 + 0x1a,uVar1,param_4,param_1,param_2);
    }
    uVar3 = (uint)(iVar2 != 0);
    iVar2 = FUN_600e9e24(param_1,iVar4,param_3,param_4,param_5);
    if (iVar2 == 0) {
      return 0;
    }
    if ((uVar1 < 2) || (param_1[0x16] != 0)) {
      param_1[0x18] = 0;
    }
    else {
      *param_3 = *param_3 - uVar1;
      param_1[0x18] = 1;
      thunk_EXT_FUN_0000af88(param_1 + 0x1a,*param_3 + iVar4,uVar1);
    }
    if (uVar3 != 0) {
      *param_3 = uVar1 + *param_3;
      return uVar3;
    }
  }
  else {
    iVar4 = (**(code **)(iVar4 + 0x20))(param_1,param_2,param_4,param_5);
    if (iVar4 < 0) {
      *param_3 = 0;
      return 0;
    }
    *param_3 = iVar4;
  }
  return 1;
}


