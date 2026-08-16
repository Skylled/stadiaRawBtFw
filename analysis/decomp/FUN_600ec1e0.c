// 600ec1e0  FUN_600ec1e0  size=316 bytes
// --- callers ---
//   600ec31c FUN_600ec31c
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90
//   6004cdb8 FUN_6004cdb8


undefined4 FUN_600ec1e0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = param_2 + 0x50;
  iVar1 = *(int *)(param_2 + 0xd0);
  *(undefined1 *)(iVar6 + iVar1) = 0x80;
  uVar2 = iVar1 + 1;
  if (0x70 < uVar2) {
    thunk_EXT_FUN_0000af90(uVar2 + iVar6,0,0x80 - uVar2);
    FUN_6004cdb8(param_2,iVar6,1);
    uVar2 = 0;
  }
  thunk_EXT_FUN_0000af90(uVar2 + iVar6,0,0x70 - uVar2);
  uVar3 = *(undefined4 *)(param_2 + 0x40);
  uVar4 = *(undefined4 *)(param_2 + 0x44);
  *(char *)(param_2 + 0xcf) = (char)uVar3;
  *(char *)(param_2 + 0xcb) = (char)uVar4;
  *(char *)(param_2 + 0xce) = (char)((uint)uVar3 >> 8);
  *(char *)(param_2 + 0xcd) = (char)((uint)uVar3 >> 0x10);
  *(char *)(param_2 + 0xcc) = (char)((uint)uVar3 >> 0x18);
  *(char *)(param_2 + 0xca) = (char)((uint)uVar4 >> 8);
  *(char *)(param_2 + 0xc9) = (char)((uint)uVar4 >> 0x10);
  *(char *)(param_2 + 200) = (char)((uint)uVar4 >> 0x18);
  uVar3 = *(undefined4 *)(param_2 + 0x48);
  uVar4 = *(undefined4 *)(param_2 + 0x4c);
  *(char *)(param_2 + 199) = (char)uVar3;
  *(char *)(param_2 + 0xc3) = (char)uVar4;
  *(char *)(param_2 + 0xc6) = (char)((uint)uVar3 >> 8);
  *(char *)(param_2 + 0xc5) = (char)((uint)uVar3 >> 0x10);
  *(char *)(param_2 + 0xc4) = (char)((uint)uVar3 >> 0x18);
  *(char *)(param_2 + 0xc2) = (char)((uint)uVar4 >> 8);
  *(char *)(param_2 + 0xc1) = (char)((uint)uVar4 >> 0x10);
  *(char *)(param_2 + 0xc0) = (char)((uint)uVar4 >> 0x18);
  FUN_6004cdb8(param_2,iVar6,1);
  if (param_1 == 0) {
LAB_600ec292:
    uVar3 = 0;
  }
  else {
    if (*(int *)(param_2 + 0xd4) == 0x30) {
      iVar1 = param_1 + 8;
      puVar5 = (undefined4 *)(param_2 + -8);
      do {
        uVar4 = puVar5[2];
        iVar6 = iVar1 + 8;
        uVar3 = puVar5[3];
        *(char *)(iVar1 + -1) = (char)uVar4;
        *(char *)(iVar1 + -5) = (char)uVar3;
        *(char *)(iVar1 + -8) = (char)((uint)uVar3 >> 0x18);
        *(char *)(iVar1 + -7) = (char)((uint)uVar3 >> 0x10);
        *(char *)(iVar1 + -6) = (char)((uint)uVar3 >> 8);
        *(char *)(iVar1 + -4) = (char)((uint)uVar4 >> 0x18);
        *(char *)(iVar1 + -3) = (char)((uint)uVar4 >> 0x10);
        *(char *)(iVar1 + -2) = (char)((uint)uVar4 >> 8);
        iVar1 = iVar6;
        puVar5 = puVar5 + 2;
      } while (param_1 + 0x38 != iVar6);
    }
    else {
      if (*(int *)(param_2 + 0xd4) != 0x40) goto LAB_600ec292;
      iVar1 = param_1 + 8;
      puVar5 = (undefined4 *)(param_2 + -8);
      do {
        uVar4 = puVar5[2];
        iVar6 = iVar1 + 8;
        uVar3 = puVar5[3];
        *(char *)(iVar1 + -1) = (char)uVar4;
        *(char *)(iVar1 + -5) = (char)uVar3;
        *(char *)(iVar1 + -8) = (char)((uint)uVar3 >> 0x18);
        *(char *)(iVar1 + -7) = (char)((uint)uVar3 >> 0x10);
        *(char *)(iVar1 + -6) = (char)((uint)uVar3 >> 8);
        *(char *)(iVar1 + -4) = (char)((uint)uVar4 >> 0x18);
        *(char *)(iVar1 + -3) = (char)((uint)uVar4 >> 0x10);
        *(char *)(iVar1 + -2) = (char)((uint)uVar4 >> 8);
        iVar1 = iVar6;
        puVar5 = puVar5 + 2;
      } while (iVar6 != param_1 + 0x48);
    }
    uVar3 = 1;
  }
  return uVar3;
}


