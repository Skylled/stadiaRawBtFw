// 6005f664  FUN_6005f664  size=172 bytes
// --- callers ---
//   6005f8c0 FUN_6005f8c0
//   6005f728 FUN_6005f728
// --- callees ---


void FUN_6005f664(uint param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  iVar2 = DAT_6005f724;
  iVar1 = DAT_6005f720;
  iVar3 = 0;
  do {
    iVar8 = 0x1b;
    iVar6 = 0;
    do {
      iVar7 = iVar6 + iVar8 >> 1;
      iVar4 = iVar1 + iVar7 * 0x1c;
      uVar9 = (uint)*(byte *)(iVar1 + iVar7 * 0x1c);
      if (param_1 == uVar9) goto LAB_6005f6b4;
      if (param_1 < uVar9) {
        iVar8 = iVar7 + -1;
      }
      else {
        iVar6 = iVar7 + 1;
      }
    } while (iVar6 < iVar8);
    if ((param_1 < *(byte *)(iVar1 + iVar6 * 0x1c)) && (iVar6 != 0)) {
      iVar4 = (iVar6 + -1) * 0x1c + iVar1;
    }
    else {
      iVar4 = iVar6 * 0x1c + iVar1;
    }
LAB_6005f6b4:
    switch(*(undefined4 *)(iVar4 + iVar3 * 4 + 4)) {
    case 1:
      uVar5 = *(undefined4 *)(iVar2 + 0x28);
      break;
    case 2:
    case 3:
      uVar5 = *(undefined4 *)(param_2 + 0x58);
      break;
    case 4:
      if (*DAT_6005f71c != 0) {
        *(undefined4 *)(param_3 + iVar3 * 4) = *(undefined4 *)(*DAT_6005f71c + 0x34);
      }
      goto LAB_6005f6f0;
    case 5:
      uVar5 = *(undefined4 *)(iVar2 + 0x34);
      break;
    case 6:
      uVar5 = *(undefined4 *)(iVar2 + 0x38);
      break;
    case 7:
      uVar5 = *(undefined4 *)(iVar2 + 0x2c);
      break;
    case 8:
      *(undefined4 *)(param_3 + iVar3 * 4) = param_4;
      goto LAB_6005f6f0;
    case 9:
      uVar5 = param_5;
      break;
    default:
      uVar5 = 0;
    }
    *(undefined4 *)(param_3 + iVar3 * 4) = uVar5;
LAB_6005f6f0:
    iVar3 = iVar3 + 1;
    if (iVar3 == 3) {
      return;
    }
  } while( true );
}


