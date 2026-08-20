// 600e89f8  FUN_600e89f8  size=386 bytes
// --- callers ---
//   600e94b6 FUN_600e94b6
//   6008b9f0 bcm__6008b9f0
// --- callees ---
//   600e87fa FUN_600e87fa
//   600e7718 FUN_600e7718
//   6008b43c bcm__6008b43c
//   600e7276 FUN_600e7276
//   600e863c FUN_600e863c
//   600e77c0 FUN_600e77c0
//   600e72fc FUN_600e72fc
//   600e7930 FUN_600e7930
//   6008b570 bcm__6008b570
//   600e80e2 FUN_600e80e2


undefined4
FUN_600e89f8(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar8 = param_2[1];
  if ((iVar8 == 0) || (iVar9 = param_3[1], iVar9 == 0)) {
    param_1[3] = 0;
    param_1[1] = 0;
    return 1;
  }
  FUN_600e7718(param_4);
  if (((param_2 != param_1) && (puVar1 = param_1, param_3 != param_1)) ||
     (puVar1 = (undefined4 *)bcm__6008b570(param_4), puVar1 != (undefined4 *)0x0)) {
    puVar1[3] = param_2[3] ^ param_3[3];
    iVar7 = iVar8 - iVar9;
    if ((iVar7 == 0) && (iVar8 == 8)) {
      iVar8 = bcm__6008b43c(puVar1,0x10);
      if (iVar8 != 0) {
        uVar5 = *param_3;
        uVar4 = *param_2;
        puVar1[1] = 0x10;
        FUN_600e80e2(*puVar1,uVar4,uVar5);
LAB_600e8a74:
        if (puVar1 == param_1) {
          bVar10 = true;
        }
        else {
          iVar8 = FUN_600e72fc(param_1,puVar1);
          bVar10 = iVar8 != 0;
        }
        goto LAB_600e8a38;
      }
    }
    else if ((iVar8 < 0x10) || ((iVar9 < 0x10 || (2 < iVar7 + 1U)))) {
      iVar7 = bcm__6008b43c(puVar1,iVar8 + iVar9);
      if (iVar7 != 0) {
        uVar4 = *param_2;
        puVar1[1] = iVar8 + iVar9;
        FUN_600e7930(*puVar1,uVar4,iVar8,*param_3,iVar9);
        goto LAB_600e8a74;
      }
    }
    else {
      iVar3 = iVar8;
      if (iVar7 == -1) {
        iVar3 = iVar9;
      }
      iVar7 = FUN_600e7276(iVar3);
      puVar2 = (undefined4 *)bcm__6008b570(param_4);
      if (puVar2 != (undefined4 *)0x0) {
        uVar6 = iVar7 - 1;
        iVar7 = 1 << (uVar6 & 0xff);
        if ((iVar7 < iVar8) || (iVar7 < iVar9)) {
          iVar3 = bcm__6008b43c(puVar2,8 << (uVar6 & 0xff));
          if ((iVar3 != 0) && (iVar3 = bcm__6008b43c(puVar1,4 << (uVar6 & 0xff)), iVar3 != 0)) {
            FUN_600e87fa(*puVar1,*param_2,*param_3,iVar7,iVar8 - iVar7,iVar9 - iVar7,*puVar2);
            goto LAB_600e8b08;
          }
        }
        else {
          iVar3 = bcm__6008b43c(puVar2,4 << (uVar6 & 0xff));
          if ((iVar3 != 0) && (iVar3 = bcm__6008b43c(puVar1,2 << (uVar6 & 0xff)), iVar3 != 0)) {
            FUN_600e863c(*puVar1,*param_2,*param_3,iVar7,iVar8 - iVar7,iVar9 - iVar7,*puVar2);
LAB_600e8b08:
            puVar1[1] = iVar8 + iVar9;
            goto LAB_600e8a74;
          }
        }
      }
    }
  }
  bVar10 = false;
LAB_600e8a38:
  FUN_600e77c0(param_4,bVar10);
  return extraout_r1;
}


