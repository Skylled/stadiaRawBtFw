// 6004a4e6  FUN_6004a4e6  size=840 bytes
// --- callers ---
//   6004a3c4 FUN_6004a3c4
// --- callees ---
//   6004bda4 FUN_6004bda4
//   60045508 FUN_60045508
//   60049c32 FUN_60049c32
//   6004bfec thunk_FUN_600ddcc4
//   60046588 FUN_60046588
//   60045738 FUN_60045738
//   6004c3fc thunk_FUN_600dd82c
//   6004c1ac thunk_FUN_600dd938
//   6004abfe FUN_6004abfe
//   60045b40 FUN_60045b40
//   6004a9ac FUN_6004a9ac
//   6004bfcc thunk_FUN_6007dac0
//   6004c144 thunk_FUN_600dde0a
//   6004c30c thunk_FUN_600ddd92
//   60046370 FUN_60046370
//   6004a862 FUN_6004a862
//   6004bffc thunk_FUN_600ddef8
//   6004bf3c thunk_FUN_6007d91c
//   6004c1c4 thunk_FUN_600de54a


void FUN_6004a4e6(int param_1,uint param_2,int param_3,undefined4 param_4,undefined1 param_5,
                 int *param_6,undefined4 *param_7)

{
  undefined1 uVar1;
  int *piVar2;
  float *pfVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  int iVar12;
  int iVar13;
  float *pfVar14;
  int iVar15;
  undefined4 in_cr7;
  float fVar16;
  uint local_179c;
  int local_1798;
  undefined4 uStack_1794;
  undefined4 local_1790;
  undefined1 auStack_178c [256];
  float local_168c [65];
  float local_1588 [65];
  float afStack_1484 [65];
  float local_1380 [65];
  undefined1 auStack_127c [260];
  float local_1178 [65];
  float local_1074 [65];
  float local_f70 [65];
  float local_e6c [65];
  float local_d68 [65];
  undefined1 *local_c64;
  undefined4 uStack_c60;
  undefined1 *local_a5c;
  undefined4 local_a58;
  undefined1 auStack_854 [2096];
  float *pfVar11;
  
  *(int *)(param_1 + 0x12b8) = *(int *)(param_1 + 0x12b8) + 1;
  piVar2 = (int *)*param_6;
  iVar12 = *piVar2;
  iVar9 = piVar2[5];
  iVar5 = piVar2[1];
  iVar13 = param_1 + 0x10;
  iVar6 = param_1 + 0x22c;
  piVar2 = (int *)*param_7;
  *(undefined1 *)(param_1 + 0xf5c) = param_5;
  local_179c = param_2;
  local_1798 = param_3;
  uStack_1794 = param_4;
  if ((param_2 & 0xff) == 0) {
    if (param_3 != 0) goto LAB_6004a550;
  }
  else {
    if (*(int *)(param_1 + 0x12bc) == 0) {
      *(undefined4 *)(param_1 + 0x12bc) = 3;
    }
    else {
      local_179c = param_2 & 0xffffff00;
    }
LAB_6004a550:
    thunk_FUN_600ddcc4(iVar13,&local_179c);
    thunk_FUN_600de54a(param_1 + 0xee8,&local_179c);
    if (local_1798 != 0) {
      thunk_FUN_600ddef8(iVar6,1);
    }
  }
  if (0 < *(int *)(param_1 + 0x12bc)) {
    *(int *)(param_1 + 0x12bc) = *(int *)(param_1 + 0x12bc) + -1;
  }
  FUN_6004a9ac(auStack_854);
  FUN_6004a862(param_1 + 0xddc,param_6,*(undefined4 *)(param_1 + 0xf00));
  if (*(char *)(param_1 + 0xef4) != '\0') {
    thunk_FUN_600ddd92(iVar13);
    thunk_FUN_600ddef8(iVar6,0);
  }
  iVar15 = param_1 + 0xee8;
  FUN_60049c32(&local_a5c,piVar2);
  pfVar14 = local_1074;
  FUN_60045738(iVar13,param_6,local_a5c,local_a58,param_1 + 0xddc,iVar15,auStack_854);
  local_a5c = auStack_178c;
  local_a58 = 0x40;
  FUN_60045508(param_1,auStack_854,local_a5c,0x40);
  FUN_60049c32(&local_c64,piVar2);
  local_a5c = (undefined1 *)(param_1 + 0x11b8);
  local_a58 = 0x40;
  thunk_FUN_600dd938(param_1 + 4,local_c64,uStack_c60,local_a5c,0x40,pfVar14);
  local_c64 = auStack_178c;
  uStack_c60 = 0x40;
  local_a5c = (undefined1 *)(param_1 + 0xfb8);
  local_a58 = 0x40;
  thunk_FUN_600dd938(param_1 + 4,local_c64,0x40,local_a5c,0x40,local_e6c);
  pfVar3 = local_1380;
  pfVar8 = pfVar14;
  pfVar7 = local_e6c;
  do {
    pfVar10 = pfVar8 + 1;
    *pfVar3 = (pfVar8[0x41] - pfVar7[0x41]) * (pfVar8[0x41] - pfVar7[0x41]) +
              (*pfVar8 - *pfVar7) * (*pfVar8 - *pfVar7);
    pfVar3 = pfVar3 + 1;
    pfVar8 = pfVar10;
    pfVar7 = pfVar7 + 1;
  } while (local_f70 != pfVar10);
  pfVar8 = local_168c;
  pfVar7 = pfVar8;
  pfVar3 = pfVar14;
  do {
    pfVar10 = pfVar3 + 1;
    *pfVar7 = pfVar3[0x41] * pfVar3[0x41] + *pfVar3 * *pfVar3;
    pfVar7 = pfVar7 + 1;
    pfVar3 = pfVar10;
  } while (pfVar10 != local_f70);
  pfVar7 = local_1588;
  pfVar3 = pfVar7;
  pfVar10 = local_e6c;
  do {
    pfVar11 = pfVar10 + 1;
    *pfVar3 = pfVar10[0x41] * pfVar10[0x41] + *pfVar10 * *pfVar10;
    pfVar3 = pfVar3 + 1;
    pfVar10 = pfVar11;
  } while (local_d68 != pfVar11);
  FUN_60046370(iVar15,param_1 + 0x44,param_6,auStack_854);
  iVar13 = thunk_FUN_600dd82c(iVar15);
  if (iVar13 == 0) {
    if (*(char *)(param_1 + 0x12c1) == '\0') goto LAB_6004a732;
    FUN_60049c32(&local_a5c,piVar2);
    iVar13 = *piVar2;
    puVar4 = auStack_178c;
    if (piVar2[1] == iVar13) {
      iVar13 = 0;
    }
  }
  else {
    if (*(char *)(param_1 + 0x12c1) != '\0') {
      FUN_6004bda4(*piVar2,auStack_178c,0x100);
      goto LAB_6004a732;
    }
    FUN_60049c32(&local_c64,piVar2);
    local_a5c = auStack_178c;
    local_a58 = 0x40;
    iVar13 = *piVar2;
    puVar4 = local_c64;
    if (piVar2[1] == iVar13) {
      iVar13 = 0;
    }
  }
  thunk_FUN_6007d91c(puVar4,local_a5c,local_a58,iVar13);
LAB_6004a732:
  uVar1 = thunk_FUN_600dd82c(iVar15);
  *(undefined1 *)(param_1 + 0x12c1) = uVar1;
  iVar13 = thunk_FUN_600dd82c(iVar15);
  if (iVar13 != 0) {
    pfVar14 = local_e6c;
  }
  thunk_FUN_6007dac0(param_1 + 0xedc,iVar15,param_6,local_1380,pfVar8,afStack_1484);
  FUN_60046588(param_1 + 0xbb4,iVar15,pfVar8,&local_c64,&local_a5c);
  iVar13 = thunk_FUN_600dd82c(iVar15);
  if (iVar13 != 0) {
    pfVar3 = local_1178;
    do {
      fVar16 = *pfVar7;
      pfVar7 = pfVar7 + 1;
      coprocessor_function2(10,7,1,in_cr7,in_cr7,in_cr7);
      *pfVar3 = fVar16;
      pfVar3 = pfVar3 + 1;
    } while (pfVar7 != afStack_1484);
  }
  iVar13 = thunk_FUN_600dd82c(iVar15);
  if (iVar13 != 0) {
    pfVar8 = local_1178;
  }
  FUN_6004abfe(iVar6,pfVar8,afStack_1484,param_1 + 0xcc0,iVar15,
               ((iVar9 + iVar12) - iVar12 * ((iVar9 + iVar12) / iVar12)) * 0xc + iVar5,&local_1790,
               auStack_127c);
  FUN_60045b40(local_1790,param_1 + 0xdc8,&local_c64,&local_a5c,auStack_127c,pfVar14,param_7);
  thunk_FUN_600dde0a(auStack_854);
  return;
}


