// 6008b79c  bcm__6008b79c  size=398 bytes
// src: bcm.c
// --- callers ---
//   600e94ca FUN_600e94ca
//   600e99a2 FUN_600e99a2
// --- callees ---
//   600e77c0 FUN_600e77c0
//   600e7718 FUN_600e7718
//   6008b43c bcm__6008b43c
//   600e7a32 FUN_600e7a32
//   600e7dc0 FUN_600e7dc0
//   600e75c2 FUN_600e75c2
//   6008b570 bcm__6008b570
//   600e72fc FUN_600e72fc
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e0552 FUN_600e0552


/* src: bcm.c */

bool bcm__6008b79c(int *param_1,int *param_2,int *param_3,int *param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  bool bVar12;
  bool bVar13;
  undefined4 uVar14;
  
  if ((param_3[3] == 0) && (param_4[3] == 0)) {
    iVar2 = FUN_600e75c2(param_4);
    if (iVar2 == 0) {
      FUN_600e7718(param_5);
      if (((param_1 == (int *)0x0) || (param_3 == param_1)) ||
         (piVar3 = param_1, param_4 == param_1)) {
        piVar3 = (int *)bcm__6008b570(param_5);
      }
      if (((param_2 == (int *)0x0) || (param_3 == param_2)) ||
         (piVar4 = param_2, param_4 == param_2)) {
        piVar4 = (int *)bcm__6008b570(param_5);
      }
      puVar5 = (undefined4 *)bcm__6008b570(param_5);
      bVar12 = false;
      if (((piVar3 != (int *)0x0) && (piVar4 != (int *)0x0)) &&
         ((puVar5 != (undefined4 *)0x0 &&
          (((iVar2 = bcm__6008b43c(piVar3,param_3[1]), iVar2 != 0 &&
            (iVar2 = bcm__6008b43c(piVar4,param_4[1]), iVar2 != 0)) &&
           (iVar2 = bcm__6008b43c(puVar5,param_4[1]), iVar2 != 0)))))) {
        thunk_EXT_FUN_0000af90(*piVar3,0,param_3[1] << 2);
        iVar2 = param_3[1];
        piVar3[3] = 0;
        piVar3[1] = iVar2;
        thunk_EXT_FUN_0000af90(*piVar4,0,param_4[1] << 2);
        iVar2 = param_4[1];
        piVar4[3] = 0;
        piVar4[1] = iVar2;
        iVar2 = param_3[1];
        while (iVar2 = iVar2 + -1, -1 < iVar2) {
          uVar10 = 0x1f;
          iVar9 = iVar2 * 4;
          do {
            iVar8 = *piVar4;
            uVar7 = FUN_600e7a32(iVar8,iVar8,iVar8,param_4[1]);
            puVar11 = (uint *)*piVar4;
            iVar8 = *param_4;
            *puVar11 = *(uint *)(*param_3 + iVar9) >> (uVar10 & 0xff) & 1 | *puVar11;
            uVar6 = FUN_600e7dc0(puVar11,uVar7,iVar8,*puVar5,param_4[1]);
            uVar1 = uVar10 & 0xff;
            bVar13 = uVar10 != 0;
            uVar10 = uVar10 - 1;
            *(uint *)(*piVar3 + iVar9) = (~uVar6 & 1) << uVar1 | *(uint *)(*piVar3 + iVar9);
          } while (bVar13);
        }
        if ((param_1 == (int *)0x0) || (iVar2 = FUN_600e72fc(param_1,piVar3), iVar2 != 0)) {
          if (param_2 == (int *)0x0) {
            bVar12 = true;
          }
          else {
            iVar2 = FUN_600e72fc(param_2,piVar4);
            bVar12 = iVar2 != 0;
          }
        }
      }
      FUN_600e77c0(param_5);
      return bVar12;
    }
    uVar7 = 0x69;
    uVar14 = 0x1d3;
  }
  else {
    uVar7 = 0x6d;
    uVar14 = 0x1cf;
  }
  FUN_600e0552(3,0,uVar7,DAT_6008b92c,uVar14);
  return false;
}


