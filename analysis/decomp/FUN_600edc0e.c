// 600edc0e  FUN_600edc0e  size=54 bytes
// --- callers ---
//   60086740 FUN_60086740
// --- callees ---
//   600edbc8 FUN_600edbc8
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600edb2a FUN_600edb2a


undefined4 FUN_600edc0e(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)FUN_600edb2a(param_1,0,param_2,param_3,param_4,param_2,param_3);
  puVar2 = (undefined4 *)*piVar1;
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0;
  }
  else {
    *piVar1 = puVar2[1];
    uVar3 = *puVar2;
    thunk_EXT_FUN_0000ac5e(puVar2);
    *param_1 = *param_1 + -1;
    FUN_600edbc8(param_1);
  }
  return uVar3;
}


