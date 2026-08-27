// 600ca844  FUN_600ca844  size=362 bytes
// --- callers ---
//   60083730 FUN_60083730
// --- callees ---
//   601009b2 FUN_601009b2
//   6010088c FUN_6010088c
//   6013d1c0 thunk_EXT_FUN_00001434


int FUN_600ca844(int param_1,uint param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  
  if (param_2 < *DAT_600ca9b0) {
    return 0;
  }
  iVar7 = 0x20;
  iVar6 = 0;
  iVar10 = param_1;
  puVar11 = param_3;
  do {
    iVar7 = iVar7 + -1;
    iVar9 = iVar6 * 0x24;
    uVar5 = iVar7 * 0x14 + DAT_600ca9b4;
    iVar8 = param_1 + iVar9;
    if ((param_4 == 0) ||
       (iVar3 = FUN_6010088c(uVar5,param_4,0x24,uVar5,iVar10,uVar5,puVar11), param_2 = uVar5,
       iVar3 == 0)) {
      iVar8 = FUN_601009b2(iVar8,uVar5,1,uVar5,iVar10,param_2);
      iVar6 = iVar6 + iVar8;
    }
    else {
      iVar6 = iVar6 + 1;
      *(undefined4 *)(iVar8 + 4) = DAT_600ca9b8;
      *(uint *)(param_1 + iVar9) = uVar5;
      *(int *)(iVar8 + 8) = iVar7;
      *(undefined1 *)(iVar8 + 0xc) = 5;
    }
    puVar2 = DAT_600ca9d8;
    puVar1 = DAT_600ca9bc;
  } while (iVar7 != 0);
  iVar10 = param_1 + iVar6 * 0x24;
  if ((param_4 == 0) || (iVar7 = FUN_6010088c(*DAT_600ca9d8,param_4), iVar7 == 0)) {
    iVar7 = FUN_601009b2(iVar10,*puVar2,2);
    iVar7 = iVar6 + iVar7;
    if (param_4 != 0) goto LAB_600ca8da;
LAB_600ca970:
    iVar10 = FUN_601009b2(iVar7 * 0x24 + param_1,*puVar1,2);
    iVar10 = iVar7 + iVar10;
    if (param_4 != 0) goto LAB_600ca8fa;
LAB_600ca984:
    iVar6 = FUN_601009b2(iVar10 * 0x24 + param_1,DAT_600ca9c8,4);
    iVar6 = iVar10 + iVar6;
    if (param_4 != 0) goto LAB_600ca91a;
  }
  else {
    iVar7 = iVar6 + 1;
    *(undefined4 *)(iVar10 + 4) = DAT_600ca9c0;
    *(undefined4 *)(param_1 + iVar6 * 0x24) = *puVar2;
    *(undefined1 *)(iVar10 + 0xc) = 5;
LAB_600ca8da:
    iVar10 = FUN_6010088c(*puVar1,param_4);
    if (iVar10 == 0) goto LAB_600ca970;
    iVar10 = iVar7 + 1;
    iVar6 = param_1 + iVar7 * 0x24;
    *(undefined4 *)(iVar6 + 4) = DAT_600ca9c4;
    *(undefined4 *)(param_1 + iVar7 * 0x24) = *puVar1;
    *(undefined1 *)(iVar6 + 0xc) = 5;
LAB_600ca8fa:
    uVar4 = DAT_600ca9c8;
    iVar6 = FUN_6010088c(DAT_600ca9c8,param_4);
    if (iVar6 == 0) goto LAB_600ca984;
    iVar6 = iVar10 + 1;
    iVar7 = param_1 + iVar10 * 0x24;
    *(undefined4 *)(iVar7 + 4) = DAT_600ca9cc;
    *(undefined4 *)(param_1 + iVar10 * 0x24) = uVar4;
    *(undefined1 *)(iVar7 + 0xc) = 5;
LAB_600ca91a:
    uVar4 = DAT_600ca9d0;
    iVar10 = FUN_6010088c(DAT_600ca9d0,param_4);
    if (iVar10 != 0) {
      iVar10 = iVar6 + 1;
      iVar7 = param_1 + iVar6 * 0x24;
      *(undefined4 *)(iVar7 + 4) = DAT_600ca9d4;
      *(undefined4 *)(param_1 + iVar6 * 0x24) = uVar4;
      *(undefined1 *)(iVar7 + 0xc) = 5;
      goto LAB_600ca93a;
    }
  }
  iVar10 = FUN_601009b2(iVar6 * 0x24 + param_1,DAT_600ca9d0,3);
  iVar10 = iVar6 + iVar10;
LAB_600ca93a:
  if (param_3 != (undefined4 *)0x0) {
    uVar4 = thunk_EXT_FUN_00001434();
    *param_3 = uVar4;
  }
  return iVar10;
}


