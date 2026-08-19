// 600d3a16  thunk_FUN_60059eb8  size=4 bytes
// --- callers ---
//   60078340 firmware_image_upload__60078340
//   6005c15c FUN_6005c15c
//   6005c07c FUN_6005c07c
//   6005be94 FUN_6005be94
//   6005b1c0 application_state__6005b1c0
// --- callees ---


undefined4 thunk_FUN_60059eb8(uint param_1,uint param_2,int param_3)

{
  uint *puVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint auStack_18 [4];
  
  iVar3 = DAT_60059efc;
  pcVar2 = DAT_60059ef8;
  iVar6 = 0;
  auStack_18[0] = param_1 | 0x80000000;
  if (param_3 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 4;
  }
  auStack_18[2] = 0;
  auStack_18[3] = 0;
  auStack_18[1] = param_2 | uVar5;
  do {
    if (*pcVar2 == '\0') {
      return 9;
    }
    puVar1 = auStack_18 + iVar6;
    iVar4 = iVar6 + 0x40;
    iVar6 = iVar6 + 1;
    *(uint *)(iVar3 + iVar4 * 4) = *puVar1;
  } while (iVar6 != 4);
  return 0;
}


