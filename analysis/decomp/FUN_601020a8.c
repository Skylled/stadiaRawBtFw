// 601020a8  FUN_601020a8  size=68 bytes
// --- callers ---
//   60091b94 FUN_60091b94
// --- callees ---


int FUN_601020a8(undefined4 param_1,int param_2,uint param_3,int param_4,code *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    uVar4 = 0;
    while (uVar2 = param_3, uVar4 < uVar2) {
      param_3 = uVar4 + uVar2 >> 1;
      iVar3 = param_3 * param_4 + param_2;
      iVar1 = (*param_5)(param_1,iVar3);
      if (-1 < iVar1) {
        if (iVar1 == 0) {
          return iVar3;
        }
        uVar4 = param_3 + 1;
        param_3 = uVar2;
      }
    }
  }
  return 0;
}


