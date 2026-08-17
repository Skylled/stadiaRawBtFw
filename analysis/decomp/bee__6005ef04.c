// 6005ef04  bee__6005ef04  size=344 bytes
// src: bee.cc
// --- callers ---
//   6005f07c FUN_6005f07c
// --- callees ---
//   6013d178 thunk_EXT_FUN_00008996
//   6010165c FUN_6010165c
//   60052378 FUN_60052378
//   600d4772 FUN_600d4772
//   600ce96e FUN_600ce96e
//   600ce95c FUN_600ce95c


/* src: bee.cc */

uint bee__6005ef04(uint *param_1,int param_2,int param_3)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  undefined1 local_34 [4];
  uint local_30;
  uint uStack_2c;
  undefined4 local_28;
  undefined1 local_24;
  
  uVar10 = *param_1;
  uVar9 = uVar10 + param_1[1];
  if (((uVar10 | uVar9) & 0xf) != 0) {
    FUN_6010165c(0x28,DAT_6005f060,0x65,DAT_6005f05c,uVar10,uVar9);
    return 3;
  }
  if ((char)param_1[4] != '\0') {
    if (param_2 == 0) {
      uVar8 = *(int *)(DAT_6005f06c + 0x460) << 0x12;
LAB_6005ef68:
      uVar8 = uVar8 >> 0x1e;
      cVar1 = *(char *)param_1[2];
      if (cVar1 == '\0') {
        if (uVar8 != 0) goto LAB_6005efc2;
        goto LAB_6005ef90;
      }
      if (cVar1 == '\x01') {
        iVar11 = *(int *)((char *)param_1[2] + 4);
        if (uVar8 == 1) {
          iVar3 = FUN_600d4772();
          if (iVar3 == 0) {
            bVar12 = iVar11 == 1;
          }
          else {
            bVar12 = iVar11 == 3;
          }
LAB_6005efae:
          if (bVar12) goto LAB_6005ef90;
        }
        else if (uVar8 == 2) {
          if (iVar11 == 0) goto LAB_6005ef90;
        }
        else if (uVar8 == 3) {
          bVar12 = iVar11 == 2;
          goto LAB_6005efae;
        }
LAB_6005efc2:
        FUN_6010165c(0x28,DAT_6005f060,0x53,DAT_6005f074,param_2,uVar8);
      }
      else {
        FUN_6010165c(0x28,DAT_6005f060,0x4e,DAT_6005f070,cVar1);
      }
    }
    else {
      if (param_2 == 1) {
        uVar8 = *(int *)(DAT_6005f06c + 0x460) << 0x10;
        goto LAB_6005ef68;
      }
      FUN_6010165c(0x28,DAT_6005f060,0x31,DAT_6005f064);
    }
    FUN_6010165c(0x1e,DAT_6005f060,0x6b,DAT_6005f068);
  }
LAB_6005ef90:
  if (param_1[3] == 0) {
    if (param_3 == 0) {
      uVar7 = 0;
LAB_6005efe8:
      FUN_600ce95c(local_34);
      puVar2 = DAT_6005f078;
      local_28 = 0;
      local_24 = (undefined1)param_1[4];
      local_34[0] = uVar7;
      local_30 = uVar10;
      uStack_2c = uVar9;
      FUN_60052378(DAT_6005f078,param_2,local_34);
      uVar9 = thunk_EXT_FUN_00008996();
      if ((uVar9 & 0xff) != 0) {
        return uVar9;
      }
      if ((char)param_1[4] != '\0') {
        *puVar2 = *puVar2 | 0x11;
        puVar2 = DAT_6005f078;
        pcVar6 = (char *)param_1[2];
        uVar5 = 0;
        if (*pcVar6 == '\0') {
          uVar5 = *(undefined4 *)(pcVar6 + 4);
        }
        if (param_3 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x10;
        }
        FUN_600ce96e(DAT_6005f078,param_2,uVar5,*(undefined4 *)(pcVar6 + 8),param_3,uVar4);
        uVar9 = thunk_EXT_FUN_00008996();
        *puVar2 = *puVar2 & 0xffffffee;
        if ((uVar9 & 0xff) != 0) {
          return uVar9;
        }
      }
      return 0;
    }
  }
  else if ((param_1[3] == 2) && (param_3 != 0)) {
    uVar7 = 1;
    goto LAB_6005efe8;
  }
  return 3;
}


