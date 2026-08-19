// 600e0bfe  FUN_600e0bfe  size=76 bytes
// --- callers ---
//   600919d4 ex_data__600919d4
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600e0a70 FUN_600e0a70
//   600e093e FUN_600e093e
//   600e0ae2 FUN_600e0ae2


int * FUN_600e0bfe(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_600e0a70(param_1[4]);
    if ((piVar1 == (int *)0x0) || (iVar2 = FUN_600e093e(piVar1[1],param_1[3] << 2), iVar2 == 0)) {
      piVar4 = (int *)0x0;
      FUN_600e0ae2(piVar1);
    }
    else {
      iVar3 = *param_1;
      piVar1[1] = iVar2;
      *piVar1 = iVar3;
      if (*param_1 << 2 != 0) {
        thunk_EXT_FUN_0000b572(iVar2,param_1[1],*param_1 << 2,iVar3,param_4);
      }
      piVar1[2] = param_1[2];
      piVar1[3] = param_1[3];
      piVar1[4] = param_1[4];
      piVar4 = piVar1;
    }
  }
  return piVar4;
}


