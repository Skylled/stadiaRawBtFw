// 60041e9c  FUN_60041e9c  size=116 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_60041e9c(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = (int *)*param_1;
  if (piVar4 != (int *)0x0) {
    if (_DAT_60041f10 == 0) {
      iVar2 = piVar4[1];
      piVar4[1] = iVar2 + -1;
      if (iVar2 != 1) {
        return param_1;
      }
      (**(code **)(*piVar4 + 8))(piVar4);
      iVar2 = piVar4[2];
      piVar4[2] = iVar2 + -1;
    }
    else {
      piVar3 = piVar4 + 1;
      DataMemoryBarrier(0x1b);
      do {
        ExclusiveAccess(piVar3);
        iVar2 = *piVar3;
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = iVar2 + -1;
      DataMemoryBarrier(0x1b);
      if (iVar2 != 1) {
        return param_1;
      }
      (**(code **)(*piVar4 + 8))(piVar4);
      piVar3 = piVar4 + 2;
      DataMemoryBarrier(0x1b);
      do {
        ExclusiveAccess(piVar3);
        iVar2 = *piVar3;
        bVar1 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar1);
      *piVar3 = iVar2 + -1;
      DataMemoryBarrier(0x1b);
    }
    if (iVar2 == 1) {
      (**(code **)(*piVar4 + 0xc))(piVar4);
    }
  }
  return param_1;
}


