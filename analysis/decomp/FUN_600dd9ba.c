// 600dd9ba  FUN_600dd9ba  size=320 bytes
// --- callers ---
// --- callees ---
//   6007da70 FUN_6007da70
//   6013d238 thunk_EXT_FUN_0000b588
//   6007d978 FUN_6007d978
//   6013d278 thunk_EXT_FUN_00005ab4


void FUN_600dd9ba(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar9 = *(int *)(param_1 + 0x14);
  iVar7 = *(int *)(param_1 + 0x2c);
  if (iVar9 < *(int *)(param_1 + 4) + -1) {
    iVar10 = iVar9 + 1;
  }
  else {
    iVar10 = 0;
  }
  *(int *)(param_1 + 0x14) = iVar10;
  if (iVar7 < 1) {
    iVar7 = *(int *)(param_1 + 0x1c);
  }
  *(int *)(param_1 + 0x2c) = iVar7 + -1;
  iVar7 = *(int *)(param_1 + 0x44);
  if (iVar7 < 1) {
    iVar7 = *(int *)(param_1 + 0x34);
  }
  iVar11 = *param_2;
  iVar12 = param_2[1];
  *(int *)(param_1 + 0x44) = iVar7 + -1;
  iVar7 = iVar12 - iVar11;
  if (*(char *)(param_1 + 100) == '\0') {
    iVar1 = iVar7 >> 2;
    iVar5 = iVar11;
    if (iVar1 == 0) {
      iVar5 = 0;
    }
    iVar1 = FUN_6007da70(param_1,iVar5,iVar1);
    uVar2 = iVar1 + *(int *)(param_1 + 0x68);
    *(uint *)(param_1 + 0x68) = uVar2;
    *(bool *)(param_1 + 100) = 0x13 < uVar2;
  }
  if (iVar12 != iVar11) {
    thunk_EXT_FUN_0000b588(*(undefined4 *)(*(int *)(param_1 + 8) + iVar10 * 0xc),iVar11,iVar7);
  }
  iVar11 = *param_2;
  iVar10 = *(int *)(*(int *)(param_1 + 8) + iVar9 * 0xc);
  iVar7 = param_2[1] - iVar11 >> 2;
  if (iVar7 == 0) {
    iVar11 = 0;
  }
  iVar9 = *(int *)(*(int *)(param_1 + 8) + iVar9 * 0xc + 4) - iVar10 >> 2;
  if (iVar9 == 0) {
    iVar10 = 0;
  }
  if (iVar7 == 0) {
    iVar11 = 0;
  }
  if (iVar9 == 0) {
    iVar10 = 0;
  }
  thunk_EXT_FUN_00005ab4
            (param_1 + 0x5c,iVar11,iVar7,iVar10,iVar9,0,
             *(int *)(param_1 + 0x44) * 0x208 + *(int *)(param_1 + 0x38));
  pfVar8 = (float *)(*(int *)(param_1 + 0x44) * 0x208 + *(int *)(param_1 + 0x38));
  iVar7 = *(int *)(param_1 + 0x2c) * 0xc;
  pfVar3 = pfVar8 + 0x41;
  pfVar6 = *(float **)(*(int *)(param_1 + 0x20) + iVar7);
  pfVar4 = pfVar3;
  if (*(float **)(*(int *)(param_1 + 0x20) + iVar7 + 4) == pfVar6) {
    pfVar6 = (float *)0x0;
  }
  for (; pfVar3 != pfVar8; pfVar8 = pfVar8 + 1) {
    *pfVar6 = *pfVar4 * *pfVar4 + *pfVar8 * *pfVar8;
    pfVar6 = pfVar6 + 1;
    pfVar4 = pfVar4 + 1;
  }
  if (*(int *)(param_1 + 0x18) != *(int *)(param_1 + 0x14)) {
    return;
  }
  FUN_6007d978(param_1);
  return;
}


