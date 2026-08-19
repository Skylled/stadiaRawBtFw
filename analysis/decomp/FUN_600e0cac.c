// 600e0cac  FUN_600e0cac  size=56 bytes
// --- callers ---
// --- callees ---
//   600e0ab2 FUN_600e0ab2
//   600edc52 FUN_600edc52
//   600e0ab8 FUN_600e0ab8


uint FUN_600e0cac(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == (undefined4 *)0x0) {
LAB_600e0cb2:
    param_3 = 0xffffffff;
  }
  else {
    uVar4 = *param_1;
    param_3 = param_3 | (int)param_3 >> 0x1f;
    iVar1 = FUN_600e0ab2(uVar4);
    do {
      param_3 = param_3 + 1;
      if (iVar1 <= (int)param_3) goto LAB_600e0cb2;
      puVar2 = (undefined4 *)FUN_600e0ab8(uVar4,param_3);
      iVar3 = FUN_600edc52(*puVar2,param_2);
    } while (iVar3 != 0);
  }
  return param_3;
}


