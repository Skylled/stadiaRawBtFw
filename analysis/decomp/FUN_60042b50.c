// 60042b50  FUN_60042b50  size=322 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60042b50(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  
  iVar3 = _DAT_60042c94;
  cVar2 = *(char *)(_DAT_60042c94 + 0x39b);
  *(uint *)(_DAT_60042c94 + 0x114) = *(int *)(_DAT_60042c94 + 0x114) + param_1;
  iVar5 = *(int *)(iVar3 + 0x124) - param_1;
  *(int *)(iVar3 + 0x124) = iVar5;
  if (cVar2 != '\0') {
    return;
  }
  *(undefined1 *)(iVar3 + 0x39b) = 1;
  uVar4 = *(uint *)(iVar3 + 0x128);
  if (uVar4 != 0) {
    if (uVar4 <= param_1) {
      if (*(code **)(iVar3 + 0x3a8) != (code *)0x0) {
        *(undefined1 *)(iVar3 + 0x3ac) = 0;
        (**(code **)(iVar3 + 0x3a8))(0);
      }
      *(undefined4 *)(iVar3 + 0x128) = 0;
      goto LAB_60042b94;
    }
    *(uint *)(iVar3 + 0x128) = uVar4 - param_1;
  }
  piVar7 = _DAT_60042c98;
  if (iVar5 < 1) {
    uVar4 = 0;
    iVar8 = 0x7fffffff;
    *(int *)(iVar3 + 300) = *(int *)(iVar3 + 300) - iVar5;
    do {
      piVar1 = piVar7 + 1;
      uVar9 = uVar4 & 0xff;
      if ((0 < *piVar1) && (iVar5 = *piVar1 - *(int *)(iVar3 + 300), *piVar1 = iVar5, iVar5 < 1)) {
        *(undefined1 *)(iVar3 + uVar4 + 0xec) = 1;
      }
      if (0 < piVar7[9]) {
        iVar5 = *(int *)(iVar3 + 300);
        iVar6 = piVar7[9] - iVar5;
        piVar7[9] = iVar6;
        if (iVar6 < 1) {
          piVar7[9] = piVar7[0x11];
          func_0x6004c21c(uVar9,0x10,iVar5,piVar7[0x11],param_4);
          iVar6 = piVar7[9];
          if (iVar6 < 1) goto LAB_60042c0a;
        }
        if (iVar6 <= iVar8) {
          iVar8 = iVar6;
        }
      }
LAB_60042c0a:
      if (0 < piVar7[0x19]) {
        iVar5 = *(int *)(iVar3 + 300);
        iVar6 = piVar7[0x19] - iVar5;
        piVar7[0x19] = iVar6;
        if (iVar6 < 1) {
          piVar7[0x19] = piVar7[0x21];
          func_0x6004c21c(uVar9,0x20,iVar5,piVar7[0x21],param_4);
          iVar6 = piVar7[0x19];
          if (iVar6 < 1) goto LAB_60042c36;
        }
        if (iVar6 <= iVar8) {
          iVar8 = iVar6;
        }
      }
LAB_60042c36:
      if (0 < piVar7[0x29]) {
        iVar5 = *(int *)(iVar3 + 300);
        iVar6 = piVar7[0x29] - iVar5;
        piVar7[0x29] = iVar6;
        if (iVar6 < 1) {
          piVar7[0x29] = piVar7[0x31];
          func_0x6004c21c(uVar9,0x40,iVar5,piVar7[0x31],param_4);
          iVar6 = piVar7[0x29];
          if (iVar6 < 1) goto LAB_60042c6a;
        }
        if (iVar6 <= iVar8) {
          iVar8 = iVar6;
        }
      }
LAB_60042c6a:
      uVar4 = uVar4 + 1;
      piVar7 = piVar1;
    } while (uVar4 != 8);
    if (iVar8 == 0x7fffffff) {
      *(undefined4 *)(iVar3 + 300) = 0;
      *(undefined4 *)(iVar3 + 0x124) = 0;
    }
    else {
      *(int *)(iVar3 + 300) = iVar8;
      *(int *)(iVar3 + 0x124) = iVar8;
    }
  }
LAB_60042b94:
  *(undefined1 *)(iVar3 + 0x39b) = 0;
  return;
}


