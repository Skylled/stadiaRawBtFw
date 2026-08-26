// 60100f90  FUN_60100f90  size=108 bytes
// --- callers ---
//   600cb39c key_value_store__600cb39c
//   600cb428 key_value_store__600cb428
// --- callees ---
//   60100bb0 FUN_60100bb0
//   60100ed8 FUN_60100ed8
//   60100b38 FUN_60100b38
//   60100d98 FUN_60100d98


uint FUN_60100f90(undefined4 *param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar5 = param_1 + 0x2e;
  uVar4 = 0;
  do {
    uVar2 = FUN_60100b38(*param_1);
    if (uVar2 <= uVar4) {
      return 0;
    }
    uVar2 = *puVar5;
    puVar1 = puVar5 + 1;
    puVar5 = puVar5 + 2;
    uVar2 = (uint)((uVar2 & *puVar1) != 0xffffffff);
    if (uVar2 == param_2) {
      if ((param_2 == 0) &&
         (uVar2 = FUN_60100d98(param_1,uVar4,*puVar1,uVar2,param_4), (uVar2 & 0xff) != 0)) {
        return uVar2;
      }
      uVar2 = FUN_60100ed8(param_1,uVar4);
      if ((uVar2 & 0xf7) != 0) {
        return uVar2;
      }
      if ((param_3 != 0) && (iVar3 = FUN_60100bb0(param_1,0xffffffff), iVar3 != 0)) {
        return 0;
      }
    }
    uVar4 = uVar4 + 1;
  } while( true );
}


