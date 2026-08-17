// 60090c3c  tasn_new__60090c3c  size=98 bytes
// src: tasn_new.c
// --- callers ---
//   600ecb4a tasn_new__600ecb4a
// --- callees ---
//   600eca86 FUN_600eca86
//   600e0aac FUN_600e0aac
//   600e0552 FUN_600e0552


/* src: tasn_new.c */

undefined4 tasn_new__60090c3c(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  uVar4 = *param_2;
  puVar3 = (undefined1 *)param_2[4];
  if ((int)(uVar4 << 0x1f) < 0) {
    if ((uVar4 & 0x306) == 0) {
      FUN_600eca86();
      return 1;
    }
LAB_60090c52:
    *param_1 = 0;
    return 1;
  }
  if ((uVar4 & 0x300) != 0) goto LAB_60090c52;
  if ((uVar4 & 6) != 0) {
    iVar2 = FUN_600e0aac();
    if (iVar2 != 0) {
      *param_1 = iVar2;
      return 1;
    }
    FUN_600e0552(0xc,0,0x41,DAT_60090ca0,0x11b);
    return 0;
  }
  uVar4 = uVar4 & 0x400;
  puVar5 = *(undefined4 **)(puVar3 + 0x10);
  if (puVar5 == (undefined4 *)0x0) {
    pcVar6 = (code *)0x0;
  }
  else {
    pcVar6 = (code *)puVar5[3];
  }
  switch(*puVar3) {
  case 0:
    if (*(int *)(puVar3 + 8) == 0) goto switchD_60090ade_caseD_5;
    iVar2 = tasn_new__60090c3c(param_1);
    break;
  case 1:
  case 6:
    if (pcVar6 == (code *)0x0) {
LAB_60090ba4:
      if (uVar4 == 0) {
        iVar2 = FUN_600e092c(*(undefined4 *)(puVar3 + 0x14));
        *param_1 = iVar2;
        if (iVar2 == 0) goto LAB_60090b04;
        if (*(int *)(puVar3 + 0x14) != 0) {
          thunk_EXT_FUN_0000b5ba(iVar2,0);
        }
        FUN_600ecbca(param_1,puVar3);
        FUN_600ecbec(param_1,puVar3);
      }
      iVar8 = *(int *)(puVar3 + 8);
      for (iVar2 = 0; iVar7 = iVar2 * 0x14 + iVar8, iVar2 < *(int *)(puVar3 + 0xc);
          iVar2 = iVar2 + 1) {
        uVar1 = FUN_600eccd4(param_1,iVar7);
        iVar7 = tasn_new__60090c3c(uVar1,iVar7);
        if (iVar7 == 0) {
          FUN_60090940(param_1,puVar3,uVar4);
          goto LAB_60090b04;
        }
      }
LAB_60090b7c:
      if (pcVar6 == (code *)0x0) {
        return 1;
      }
LAB_60090b80:
      iVar2 = (*pcVar6)(1,param_1,puVar3,0);
      if (iVar2 != 0) {
        return 1;
      }
      FUN_60090940(param_1,puVar3,uVar4);
    }
    else {
      iVar2 = (*pcVar6)(0,param_1,puVar3);
      if (iVar2 != 0) {
        if (iVar2 == 2) {
          return 1;
        }
        goto LAB_60090ba4;
      }
    }
LAB_60090b98:
    uVar1 = 0x65;
    uVar9 = 0xd9;
    goto LAB_60090b0c;
  case 2:
    if (pcVar6 != (code *)0x0) {
      iVar2 = (*pcVar6)(0,param_1,puVar3);
      if (iVar2 == 0) goto LAB_60090b98;
      if (iVar2 == 2) {
        return 1;
      }
      if (uVar4 == 0) goto LAB_60090b5a;
      FUN_600ecbbe(param_1,0xffffffff,puVar3);
      goto LAB_60090b80;
    }
    if (uVar4 != 0) {
      FUN_600ecbbe(param_1,0xffffffff,puVar3);
      return 1;
    }
LAB_60090b5a:
    iVar2 = FUN_600e092c(*(undefined4 *)(puVar3 + 0x14));
    *param_1 = iVar2;
    if (iVar2 != 0) {
      if (*(int *)(puVar3 + 0x14) != 0) {
        thunk_EXT_FUN_0000b5ba(iVar2,0);
      }
      FUN_600ecbbe(param_1,0xffffffff,puVar3);
      goto LAB_60090b7c;
    }
    goto LAB_60090b04;
  case 3:
    if (puVar5 == (undefined4 *)0x0) {
      return 1;
    }
    if ((code *)*puVar5 == (code *)0x0) {
      return 1;
    }
    iVar2 = (*(code *)*puVar5)();
    *param_1 = iVar2;
    break;
  case 4:
    if (puVar5 == (undefined4 *)0x0) {
      return 1;
    }
    pcVar6 = (code *)puVar5[1];
    if (pcVar6 == (code *)0x0) {
      return 1;
    }
    iVar2 = (*pcVar6)(param_1,puVar3,*puVar3,pcVar6,param_1,puVar3,uVar4);
    break;
  case 5:
switchD_60090ade_caseD_5:
    iVar2 = FUN_600ecabe(param_1,puVar3);
    break;
  default:
    goto switchD_60090ade_default;
  }
  if (iVar2 != 0) {
switchD_60090ade_default:
    return 1;
  }
LAB_60090b04:
  uVar1 = 0x41;
  uVar9 = 0xcf;
LAB_60090b0c:
  FUN_600e0552(0xc,0,uVar1,DAT_60090c38,uVar9);
  return 0;
}


