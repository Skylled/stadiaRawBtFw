// 60043028  FUN_60043028  size=516 bytes
// --- callers ---
//   600432e8 FUN_600432e8
// --- callees ---
//   60042e5c FUN_60042e5c
//   60042d44 FUN_60042d44
//   600492ee FUN_600492ee
//   60046de0 FUN_60046de0
//   60049096 FUN_60049096
//   6004bcde FUN_6004bcde


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_60043028(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  iVar12 = _DAT_6004322c;
  iStack_44 = _DAT_6004322c;
  FUN_6004bcde(_DAT_6004322c);
  piVar3 = *(int **)(param_1 + 0x3f4);
  if (piVar3 == (int *)0x0) {
    uVar4 = func_0x60042ee0(iVar12 + -0x1b0,param_2);
    func_0x6004bfd4();
    iVar5 = FUN_600492ee();
    FUN_60046de0();
    iVar6 = FUN_600492ee();
    iVar15 = *(int *)(param_1 + 0x74);
    iVar13 = *(int *)(iVar15 + 0x2c);
    if (*(int *)(iVar15 + 0x2c) < iVar5) {
      iVar13 = iVar5;
    }
    iVar14 = *(int *)(iVar15 + 0x30);
    if (*(int *)(iVar15 + 0x30) < iVar6) {
      iVar14 = iVar6;
    }
    if (iVar5 < 0x401) {
      uVar17 = (uint)*(byte *)(iVar15 + 0x12);
    }
    else {
      uVar17 = 1;
    }
    if (iVar6 < 0x401) {
      uVar16 = (uint)*(byte *)(iVar15 + 0x13);
    }
    else {
      uVar16 = 1;
    }
    bVar1 = *(byte *)(iVar12 + 0x6a);
    bVar2 = *(byte *)(iVar12 + 0x6b);
    uVar7 = func_0x6004bf9c();
    func_0x6004949a(&iStack_30,uVar7);
    uVar4 = uVar4 & 0xff | uVar17 ^ bVar1 | uVar16 ^ bVar2;
    if ((iStack_30 == 0x800) && (iStack_2c == 0x800)) {
      iStack_40 = *(int *)(*(int *)(param_1 + 0x74) + 0x1c);
      iStack_3c = *(int *)(*(int *)(param_1 + 0x74) + 0x20);
    }
    else {
      iStack_40 = iStack_30;
      iStack_3c = iStack_2c;
    }
    uVar7 = func_0x6004c00c();
    func_0x6004949a(&iStack_30,uVar7);
    if ((iStack_30 == 0x800) && (iStack_2c == 0x800)) {
      iStack_38 = *(int *)(*(int *)(param_1 + 0x74) + 0x24);
      iStack_34 = *(int *)(*(int *)(param_1 + 0x74) + 0x28);
    }
    else {
      iStack_38 = iStack_30;
      iStack_34 = iStack_2c;
    }
    if (uVar4 == 0) {
      uVar8 = FUN_60042e5c(param_1,&iStack_40,*(undefined4 *)(iVar12 + 0x74),
                           *(undefined4 *)(iVar12 + 0x78),param_2);
      uVar9 = FUN_60042e5c(param_1,&iStack_38,*(undefined4 *)(iVar12 + 0x7c),
                           *(undefined4 *)(iVar12 + 0x80),param_2);
      uVar10 = func_0x6004bfa4(param_1,iVar13,*(undefined4 *)(iVar12 + 0x84),param_2);
      uVar11 = func_0x6004bfa4(param_1,iVar14,*(undefined4 *)(iVar12 + 0x88),param_2);
      iVar12 = func_0x6004bef4(param_1,&iStack_40,&iStack_38,iVar13,iVar14);
      if ((iVar12 != 0) && (iVar12 = func_0x6004c0dc(param_1,_DAT_60043230), iVar12 == 0)) {
        *(undefined4 *)(param_1 + 0x41c) = 3;
      }
      if (*(int *)(param_1 + 0x41c) < 1) {
        uVar8 = (uVar11 | uVar10 | uVar8 | uVar9) & 0xff;
        if (uVar8 == 0) goto LAB_600431fa;
      }
      else {
        uVar8 = 1;
        *(int *)(param_1 + 0x41c) = *(int *)(param_1 + 0x41c) + -1;
      }
    }
    else {
      uVar8 = 0;
    }
    iVar12 = _DAT_60043234;
    *(undefined4 *)(param_1 + 0x70) = param_2;
    *(int *)(iVar12 + 0x224) = iStack_40;
    *(int *)(iVar12 + 0x234) = iVar13;
    *(int *)(iVar12 + 0x228) = iStack_3c;
    *(char *)(iVar12 + 0x21a) = (char)uVar17;
    *(int *)(iVar12 + 0x22c) = iStack_38;
    *(char *)(iVar12 + 0x21b) = (char)uVar16;
    *(int *)(iVar12 + 0x230) = iStack_34;
    *(int *)(iVar12 + 0x238) = iVar14;
    if ((uVar4 == 0) && (uVar8 == 0)) {
LAB_6004321e:
      uVar8 = 0;
      goto LAB_600431fa;
    }
  }
  else {
    uVar4 = (**(code **)(*piVar3 + 8))(piVar3,*(undefined4 *)(_DAT_60043238 + 4),iVar12 + 0x58);
    if (uVar4 == 0) goto LAB_6004321e;
    uVar8 = 0;
  }
  *(undefined4 *)(param_1 + 0x208) = param_3;
  *(undefined4 *)(param_1 + 0x20c) = param_4;
  if (uVar4 != 0) {
    FUN_60042d44(param_1,param_2);
    uVar8 = uVar4;
  }
LAB_600431fa:
  FUN_60049096(&iStack_44);
  return uVar8;
}


