// 600ec016  FUN_600ec016  size=278 bytes
// --- callers ---
//   6007991c http_flash_writer__6007991c
//   60079668 http_flash_writer__60079668
// --- callees ---
//   60089fc8 FUN_60089fc8
//   6013cee8 thunk_EXT_FUN_0000af90


undefined4 FUN_600ec016(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int extraout_r3;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  
  iVar2 = param_2 + *(int *)(param_2 + 0x68);
  uVar1 = *(int *)(param_2 + 0x68) + 1;
  iVar9 = param_2 + 0x28;
  *(undefined1 *)(iVar2 + 0x28) = 0x80;
  if (0x38 < uVar1) {
    thunk_EXT_FUN_0000af90(uVar1 + iVar9,0,0x40 - uVar1,iVar2,param_4);
    FUN_60089fc8(param_2,iVar9,1);
    uVar1 = 0;
    iVar2 = extraout_r3;
  }
  uVar8 = 0;
  thunk_EXT_FUN_0000af90(uVar1 + iVar9,0,0x38 - uVar1,iVar2,param_4);
  uVar3 = *(undefined4 *)(param_2 + 0x24);
  *(char *)(param_2 + 99) = (char)uVar3;
  *(char *)(param_2 + 0x60) = (char)((uint)uVar3 >> 0x18);
  *(char *)(param_2 + 0x61) = (char)((uint)uVar3 >> 0x10);
  uVar4 = *(undefined4 *)(param_2 + 0x20);
  *(char *)(param_2 + 0x62) = (char)((uint)uVar3 >> 8);
  *(char *)(param_2 + 0x67) = (char)uVar4;
  *(char *)(param_2 + 100) = (char)((uint)uVar4 >> 0x18);
  *(char *)(param_2 + 0x65) = (char)((uint)uVar4 >> 0x10);
  *(char *)(param_2 + 0x66) = (char)((uint)uVar4 >> 8);
  FUN_60089fc8(param_2,iVar9,1);
  *(undefined4 *)(param_2 + 0x68) = 0;
  thunk_EXT_FUN_0000af90(iVar9,0,0x40);
  uVar1 = *(uint *)(param_2 + 0x6c);
  if (uVar1 == 0x1c) {
    puVar7 = (undefined4 *)(param_2 + -4);
    puVar5 = param_1 + 4;
    do {
      puVar7 = puVar7 + 1;
      uVar3 = *puVar7;
      puVar6 = puVar5 + 4;
      puVar5[-1] = (char)uVar3;
      puVar5[-4] = (char)((uint)uVar3 >> 0x18);
      puVar5[-3] = (char)((uint)uVar3 >> 0x10);
      puVar5[-2] = (char)((uint)uVar3 >> 8);
      puVar5 = puVar6;
    } while (puVar6 != param_1 + 0x20);
  }
  else if (uVar1 == 0x20) {
    puVar7 = (undefined4 *)(param_2 + -4);
    puVar5 = param_1 + 4;
    do {
      puVar7 = puVar7 + 1;
      uVar3 = *puVar7;
      puVar6 = puVar5 + 4;
      puVar5[-1] = (char)uVar3;
      puVar5[-4] = (char)((uint)uVar3 >> 0x18);
      puVar5[-3] = (char)((uint)uVar3 >> 0x10);
      puVar5[-2] = (char)((uint)uVar3 >> 8);
      puVar5 = puVar6;
    } while (puVar6 != param_1 + 0x24);
  }
  else {
    if (0x20 < uVar1) {
      return 0;
    }
    for (; uVar8 < *(uint *)(param_2 + 0x6c) >> 2; uVar8 = uVar8 + 1) {
      uVar3 = *(undefined4 *)(param_2 + uVar8 * 4);
      param_1[3] = (char)uVar3;
      *param_1 = (char)((uint)uVar3 >> 0x18);
      param_1[1] = (char)((uint)uVar3 >> 0x10);
      param_1[2] = (char)((uint)uVar3 >> 8);
      param_1 = param_1 + 4;
    }
  }
  return 1;
}


