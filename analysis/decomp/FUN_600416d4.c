// 600416d4  FUN_600416d4  size=172 bytes
// --- callers ---
// --- callees ---
//   6004baa8 FUN_6004baa8
//   6004bab0 FUN_6004bab0
//   60047968 FUN_60047968


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_600416d4(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int extraout_r2;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  
  uVar5 = _DAT_60041794;
  if (param_1 == 1) {
    if (param_2 != (int *)0x0) {
      FUN_6004baa8(_DAT_6004178c);
      uVar5 = FUN_60047968();
      lVar1 = (ulonglong)(*_DAT_60041790 + uVar5) * (ulonglong)_DAT_60041794;
      iVar8 = (int)lVar1;
      iVar6 = func_0x6004bee4(iVar8,_DAT_60041794 *
                                    (_DAT_60041790[1] + (uint)CARRY4(*_DAT_60041790,uVar5)) +
                                    (int)((ulonglong)lVar1 >> 0x20),uRam60041784,uRam60041788,
                              param_4);
      iVar4 = _DAT_60041798;
      iVar8 = iVar8 - iVar6 * _DAT_60041798;
      *param_2 = iVar6;
      param_2[1] = iVar6 >> 0x1f;
      if (iVar8 < 0) {
        param_2[2] = iVar8 + iVar4;
        *param_2 = iVar6 + -1;
        param_2[1] = (iVar6 >> 0x1f) + -1 + (uint)(iVar6 != 0);
      }
      else {
        param_2[2] = iVar8;
      }
      FUN_6004bab0(_DAT_6004178c);
    }
  }
  else {
    if (param_1 != 4) {
      return 0x16;
    }
    if (param_2 != (int *)0x0) {
      uVar7 = FUN_60047968();
      uVar9 = (undefined4)((ulonglong)uVar7 * (ulonglong)uVar5);
      uVar10 = (undefined4)((ulonglong)uVar7 * (ulonglong)uVar5 >> 0x20);
      uVar11 = func_0x6004bee4(uVar9,uVar10,uRam60041784,uRam60041788);
      uVar3 = uRam60041788;
      uVar2 = uRam60041784;
      *(undefined8 *)param_2 = uVar11;
      func_0x6004bee4(uVar9,uVar10,uVar2,uVar3);
      param_2[2] = extraout_r2;
    }
  }
  return 0;
}


