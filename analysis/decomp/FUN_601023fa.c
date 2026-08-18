// 601023fa  FUN_601023fa  size=80 bytes
// --- callers ---
// --- callees ---
//   6010244a thunk_FUN_600ce1d8


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_601023fa(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_lr;
  
  if (param_2 < 0x20) {
    iVar1 = param_1[0x11];
    if ((iVar1 == 0) || (pcVar3 = *(code **)(iVar1 + param_2 * 4), pcVar3 == (code *)0x0)) {
      uVar2 = thunk_FUN_600ce1d8(param_1);
      _DAT_2002a820 = 0;
      iVar1 = FUN_600ce1e8(uVar2,param_2,param_2,0,param_4,unaff_r4,unaff_r5,unaff_lr);
      if ((iVar1 == -1) && (_DAT_2002a820 != 0)) {
        *param_1 = _DAT_2002a820;
      }
      return iVar1;
    }
    if (pcVar3 != (code *)0x1) {
      if (pcVar3 == (code *)0xffffffff) {
        *param_1 = 0x16;
        return 1;
      }
      *(undefined4 *)(iVar1 + param_2 * 4) = 0;
      (*pcVar3)(param_2);
    }
    iVar1 = 0;
  }
  else {
    *param_1 = 0x16;
    iVar1 = -1;
  }
  return iVar1;
}


