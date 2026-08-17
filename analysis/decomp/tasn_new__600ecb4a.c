// 600ecb4a  tasn_new__600ecb4a  size=366 bytes
// src: tasn_new.c
// --- callers ---
//   6008fa18 tasn_dec__6008fa18
//   60090ca4 FUN_60090ca4
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600ecbec FUN_600ecbec
//   600ecbca FUN_600ecbca
//   60090940 FUN_60090940
//   600eccd4 FUN_600eccd4
//   600e092c FUN_600e092c
//   600e0552 FUN_600e0552
//   600ecbbe FUN_600ecbbe
//   600ecabe FUN_600ecabe
//   60090c3c tasn_new__60090c3c


/* WARNING: Removing unreachable block (ram,0x60090c2a) */
/* WARNING: Removing unreachable block (ram,0x60090c1c) */
/* src: tasn_new.c */

undefined4 tasn_new__600ecb4a(int *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  puVar3 = *(undefined4 **)(param_2 + 0x10);
  if (puVar3 == (undefined4 *)0x0) {
    pcVar4 = (code *)0x0;
  }
  else {
    pcVar4 = (code *)puVar3[3];
  }
  switch(*param_2) {
  case 0:
    if (*(int *)(param_2 + 8) == 0) goto switchD_60090ade_caseD_5;
    iVar1 = tasn_new__60090c3c(param_1);
    break;
  case 1:
  case 6:
    if (pcVar4 != (code *)0x0) {
      iVar1 = (*pcVar4)(0,param_1,param_2);
      if (iVar1 != 0) {
        if (iVar1 == 2) {
          return 1;
        }
        goto LAB_60090ba4;
      }
LAB_60090b98:
      uVar2 = 0x65;
      uVar7 = 0xd9;
      goto LAB_60090b0c;
    }
LAB_60090ba4:
    iVar1 = FUN_600e092c(*(undefined4 *)(param_2 + 0x14));
    *param_1 = iVar1;
    if (iVar1 != 0) {
      if (*(int *)(param_2 + 0x14) != 0) {
        thunk_EXT_FUN_0000b5ba(iVar1,0);
      }
      FUN_600ecbca(param_1,param_2);
      FUN_600ecbec(param_1,param_2);
      iVar6 = *(int *)(param_2 + 8);
      for (iVar1 = 0; iVar5 = iVar1 * 0x14 + iVar6, iVar1 < *(int *)(param_2 + 0xc);
          iVar1 = iVar1 + 1) {
        uVar2 = FUN_600eccd4(param_1,iVar5);
        iVar5 = tasn_new__60090c3c(uVar2,iVar5);
        if (iVar5 == 0) {
          FUN_60090940(param_1,param_2,0);
          goto LAB_60090b04;
        }
      }
      goto LAB_60090b7c;
    }
    goto LAB_60090b04;
  case 2:
    if (pcVar4 != (code *)0x0) {
      iVar1 = (*pcVar4)(0,param_1,param_2);
      if (iVar1 == 0) goto LAB_60090b98;
      if (iVar1 == 2) {
        return 1;
      }
    }
    iVar1 = FUN_600e092c(*(undefined4 *)(param_2 + 0x14));
    *param_1 = iVar1;
    if (iVar1 != 0) {
      if (*(int *)(param_2 + 0x14) != 0) {
        thunk_EXT_FUN_0000b5ba(iVar1,0);
      }
      FUN_600ecbbe(param_1,0xffffffff,param_2);
LAB_60090b7c:
      if (pcVar4 == (code *)0x0) {
        return 1;
      }
      iVar1 = (*pcVar4)(1,param_1,param_2,0);
      if (iVar1 != 0) {
        return 1;
      }
      FUN_60090940(param_1,param_2,0);
      goto LAB_60090b98;
    }
    goto LAB_60090b04;
  case 3:
    if (puVar3 == (undefined4 *)0x0) {
      return 1;
    }
    if ((code *)*puVar3 == (code *)0x0) {
      return 1;
    }
    iVar1 = (*(code *)*puVar3)();
    *param_1 = iVar1;
    break;
  case 4:
    if (puVar3 == (undefined4 *)0x0) {
      return 1;
    }
    pcVar4 = (code *)puVar3[1];
    if (pcVar4 == (code *)0x0) {
      return 1;
    }
    iVar1 = (*pcVar4)(param_1,param_2,*param_2,pcVar4,param_1,param_2,0);
    break;
  case 5:
switchD_60090ade_caseD_5:
    iVar1 = FUN_600ecabe(param_1,param_2);
    break;
  default:
    goto switchD_60090ade_default;
  }
  if (iVar1 != 0) {
switchD_60090ade_default:
    return 1;
  }
LAB_60090b04:
  uVar2 = 0x41;
  uVar7 = 0xcf;
LAB_60090b0c:
  FUN_600e0552(0xc,0,uVar2,DAT_60090c38,uVar7);
  return 0;
}


