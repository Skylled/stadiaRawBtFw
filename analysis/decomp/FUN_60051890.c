// 60051890  FUN_60051890  size=332 bytes
// --- callers ---
//   60051a14 FUN_60051a14
// --- callees ---
//   60101a64 FUN_60101a64
//   600ca570 FUN_600ca570
//   600cc450 FUN_600cc450
//   6010138c FUN_6010138c
//   600cdcc4 FUN_600cdcc4
//   600ca72c FUN_600ca72c
//   600dfe9e FUN_600dfe9e


uint FUN_60051890(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 local_7f4;
  undefined1 auStack_7f0 [4];
  undefined4 local_7ec;
  undefined2 local_7e8;
  undefined4 local_7e4 [16];
  char local_7a4 [308];
  undefined2 *local_670;
  undefined4 local_66c;
  undefined4 local_668;
  undefined1 local_664;
  undefined1 local_663;
  undefined2 local_662;
  undefined1 local_660;
  undefined4 local_460 [3];
  byte local_454 [1072];
  
  uVar1 = FUN_600ca570();
  iVar10 = 0;
  iVar2 = FUN_600ca72c(local_460,uVar1,auStack_7f0);
  local_664 = 0;
  local_670 = &local_662;
  local_663 = 0;
  local_66c = 0x1ff;
  local_660 = 0;
  local_662 = 0x7d7b;
  local_668 = 2;
  local_7ec = *DAT_600519dc;
  local_7e8 = *(undefined2 *)(DAT_600519dc + 1);
  iVar6 = getProcessStackPointer();
  local_7f4 = 0x600518b1;
  do {
    if (iVar2 == iVar10) {
      return 0;
    }
    piVar7 = (int *)local_460[iVar10 * 9];
    iVar11 = piVar7[0x11];
    if (param_2 == iVar11) {
      iVar8 = 0;
      uVar3 = 0x60051904;
      uVar1 = local_7f4;
      iVar5 = iVar6;
    }
    else {
      iVar5 = *piVar7;
      if (*(int *)(iVar5 + 0x20) << 0x1b < 0) {
        uVar1 = *(undefined4 *)(iVar5 + 0x38);
        uVar3 = *(undefined4 *)(iVar5 + 0x3c);
        iVar8 = *(int *)(iVar5 + 0x40);
        iVar5 = iVar5 + 0x44;
      }
      else {
        iVar8 = *(int *)(iVar5 + 0x80);
        uVar1 = *(undefined4 *)(iVar5 + 0x78);
        uVar3 = *(undefined4 *)(iVar5 + 0x7c);
        iVar5 = iVar5 + 0xcc;
      }
    }
    if (iVar8 << 0x1d < 0) {
      iVar5 = iVar5 + 4;
    }
    iVar11 = FUN_600dfe9e(uVar3,uVar1,iVar5,iVar11,local_7e4,0x10);
    FUN_600cc450(&local_670,DAT_600519e0,local_460[iVar10 * 9 + 1]);
    iVar5 = 0;
    uVar1 = DAT_600519ec;
    if (local_454[iVar10 * 0x24] < 5) {
      uVar1 = *(undefined4 *)(DAT_600519e8 + (uint)local_454[iVar10 * 0x24] * 4);
    }
    FUN_600cc450(&local_670,DAT_600519e4,uVar1);
    local_7a4[0] = '\0';
    for (; iVar5 < iVar11; iVar5 = iVar5 + 1) {
      uVar9 = 0;
      while (pcVar4 = local_7a4 + uVar9, local_7a4[uVar9] != '\0') {
        uVar9 = uVar9 + 1;
        if (uVar9 == 0x132) goto LAB_60051958;
      }
      if (uVar9 == 0) {
        iVar8 = 0x132;
        uVar3 = local_7e4[iVar5];
        pcVar4 = local_7a4;
        uVar1 = DAT_600519f4;
      }
      else {
        iVar8 = 0x132 - uVar9;
        if (0x124 < uVar9) {
LAB_60051958:
          FUN_600cdcc4(local_7a4 + uVar9,0x132 - uVar9,&local_7ec);
          break;
        }
        uVar3 = local_7e4[iVar5];
        uVar1 = DAT_600519f8;
      }
      FUN_600cdcc4(pcVar4,iVar8,uVar1,uVar3);
    }
    FUN_600cc450(&local_670,DAT_600519f0,local_7a4);
    uVar9 = FUN_6010138c(param_1,&local_670);
    if ((uVar9 & 0xff) != 0) {
      return uVar9;
    }
    iVar10 = iVar10 + 1;
    FUN_60101a64(&local_670);
  } while( true );
}


