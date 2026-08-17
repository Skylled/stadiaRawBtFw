// 6007f7a0  FUN_6007f7a0  size=184 bytes
// --- callers ---
// --- callees ---
//   60101a80 FUN_60101a80
//   600cc3cc FUN_600cc3cc
//   601019da FUN_601019da
//   60050c18 FUN_60050c18
//   60101a64 FUN_60101a64
//   6010138c FUN_6010138c
//   600cc450 FUN_600cc450


uint FUN_6007f7a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  
  uVar2 = DAT_6007f86c;
  iVar1 = DAT_6007f85c;
  uVar8 = *DAT_6007f858;
  uVar7 = uVar8;
  while( true ) {
    do {
      uVar7 = (uVar7 + 1) % 0x1e;
      if (uVar7 == uVar8) {
        return 0;
      }
    } while (*(int *)(iVar1 + uVar7 * 8) == 0);
    piVar3 = (int *)FUN_60101a80(*(undefined4 *)(param_1 + 0x14));
    uVar10 = *(undefined4 *)(iVar1 + uVar7 * 8);
    iVar9 = piVar3[2];
    iVar4 = FUN_600cc3cc(piVar3,uVar2);
    if (iVar4 != 0) {
      uVar10 = FUN_60050c18(uVar10,0,piVar3[2] + *piVar3,piVar3[1] - piVar3[2],param_4);
      FUN_601019da(piVar3,uVar10,iVar9,0x7d);
    }
    iVar4 = iVar1 + uVar7 * 8;
    piVar5 = *(int **)(iVar4 + 4);
    uVar10 = DAT_6007f864;
    if ((piVar5 != (int *)0x0) &&
       (iVar9 = (**(code **)(*piVar5 + 8))(), uVar10 = DAT_6007f868, iVar9 != 0)) {
      uVar10 = (**(code **)(**(int **)(iVar4 + 4) + 8))();
    }
    FUN_600cc450(piVar3,DAT_6007f860,uVar10);
    uVar6 = FUN_6010138c(param_1,piVar3);
    if ((uVar6 & 0xff) != 0) break;
    FUN_60101a64(piVar3);
  }
  return uVar6;
}


