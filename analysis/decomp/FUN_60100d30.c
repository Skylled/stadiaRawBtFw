// 60100d30  FUN_60100d30  size=104 bytes
// --- callers ---
//   60100ed8 FUN_60100ed8
// --- callees ---
//   600cb210 key_value_store__600cb210


uint FUN_60100d30(undefined4 *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  uVar5 = param_4;
  while( true ) {
    if (param_4 <= uVar4) {
      return 0;
    }
    uVar1 = key_value_store__600cb210(param_1);
    uVar2 = param_4 - uVar4;
    if (uVar1 <= param_4 - uVar4) {
      uVar2 = uVar1;
    }
    uVar1 = (**(code **)(*(int *)*param_1 + 4))
                      ((int *)*param_1,(int)param_1 + 0xac9,uVar4 + param_3,uVar2,uVar5);
    if ((uVar1 & 0xff) != 0) break;
    uVar2 = (**(code **)(*(int *)*param_1 + 8))
                      ((int *)*param_1,uVar4 + param_2,(int)param_1 + 0xac9,uVar2);
    if ((uVar2 & 0xff) != 0) {
      return uVar2;
    }
    iVar3 = key_value_store__600cb210(param_1);
    uVar4 = uVar4 + iVar3;
  }
  return uVar1;
}


