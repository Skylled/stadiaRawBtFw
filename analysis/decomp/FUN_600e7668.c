// 600e7668  FUN_600e7668  size=134 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   6008d120 bcm__6008d120
//   600e75de FUN_600e75de
// --- callees ---
//   6008b43c bcm__6008b43c
//   600e75c2 FUN_600e75c2
//   600e75de FUN_600e75de
//   600e7372 FUN_600e7372


undefined4 FUN_600e7668(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  if (param_2 != 0) {
    iVar1 = FUN_600e75c2();
    if (iVar1 != 0) {
      uVar2 = FUN_600e7372(param_1,param_2);
      return uVar2;
    }
    if (param_1[3] != 0) {
      param_1[3] = 0;
      uVar2 = FUN_600e75de(param_1,param_2);
      iVar1 = FUN_600e75c2(param_1);
      if (iVar1 == 0) {
        param_1[3] = (uint)(param_1[3] == 0);
        return uVar2;
      }
      return uVar2;
    }
    iVar5 = param_1[1];
    iVar1 = 0;
    do {
      if (iVar5 <= iVar1) {
        if (iVar5 != iVar1) {
          return 1;
        }
        iVar1 = bcm__6008b43c(param_1,iVar5 + 1);
        if (iVar1 != 0) {
          param_1[1] = param_1[1] + 1;
          *(uint *)(*param_1 + iVar5 * 4) = param_2;
          return 1;
        }
        return 0;
      }
      iVar4 = iVar1 * 4;
      uVar3 = *(uint *)(*param_1 + iVar1 * 4);
      iVar1 = iVar1 + 1;
      bVar6 = CARRY4(uVar3,param_2);
      *(uint *)(*param_1 + iVar4) = uVar3 + param_2;
      param_2 = 1;
    } while (bVar6);
  }
  return 1;
}


