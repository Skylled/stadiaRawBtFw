// 600caec8  FUN_600caec8  size=98 bytes
// --- callers ---
//   600caf30 FUN_600caf30
// --- callees ---
//   60100a26 FUN_60100a26
//   60100a0a FUN_60100a0a
//   60100a60 FUN_60100a60


uint FUN_600caec8(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 * 0x18 + 0x18 + DAT_600caf2c;
  iVar3 = *(int *)(param_1 * 0x18 + DAT_600caf2c + 0x2c);
  if (iVar3 == 1) {
    uVar1 = FUN_60100a0a(iVar4);
    uVar2 = param_3;
    if (uVar1 <= param_3) {
      uVar2 = uVar1;
    }
    FUN_60100a26(iVar4,param_2,uVar2);
  }
  else if (iVar3 == 0) {
    uVar1 = FUN_60100a0a(iVar4);
    uVar2 = 0;
    if (param_3 <= uVar1) {
      FUN_60100a26(iVar4,param_2,param_3);
      uVar2 = param_3;
    }
  }
  else {
    if (iVar3 == 2) {
      uVar2 = FUN_60100a60(iVar4,param_2,param_3,param_4);
      return uVar2;
    }
    uVar2 = 0;
  }
  return uVar2;
}


