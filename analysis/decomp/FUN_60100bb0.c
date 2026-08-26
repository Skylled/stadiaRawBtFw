// 60100bb0  FUN_60100bb0  size=50 bytes
// --- callers ---
//   60100f90 FUN_60100f90
//   600cb39c key_value_store__600cb39c
//   60100be2 FUN_60100be2
// --- callees ---
//   60100b96 FUN_60100b96
//   60100b38 FUN_60100b38


undefined4 FUN_60100bb0(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    uVar1 = FUN_60100b38(*param_1);
    if (uVar1 <= uVar3) {
      return 0;
    }
    if ((uVar3 != param_2) && (iVar2 = FUN_60100b96(param_1), param_1[uVar3 + 0x1a] == iVar2))
    break;
    uVar3 = uVar3 + 1;
  }
  return 1;
}


