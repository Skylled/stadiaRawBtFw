// 600eb8bc  FUN_600eb8bc  size=154 bytes
// --- callers ---
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90
//   600898ec FUN_600898ec
//   6013cf28 thunk_EXT_FUN_0000af88


undefined4 FUN_600eb8bc(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 != 0) {
    iVar2 = *(int *)(param_1 + 0x58);
    if (CARRY4(*(uint *)(param_1 + 0x10),param_3 * 8)) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    }
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) + param_3 * 8;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
    iVar1 = param_2;
    if (iVar2 != 0) {
      iVar4 = param_1 + 0x18;
      if ((param_3 < 0x40) && (param_3 + iVar2 < 0x40)) {
        thunk_EXT_FUN_0000af88(iVar4 + iVar2,param_2,param_3);
        *(uint *)(param_1 + 0x58) = param_3 + *(int *)(param_1 + 0x58);
        return 1;
      }
      iVar3 = 0x40 - iVar2;
      iVar1 = param_2 + iVar3;
      thunk_EXT_FUN_0000af88(iVar4 + iVar2,param_2,iVar3);
      FUN_600898ec(param_1,iVar4,1);
      *(undefined4 *)(param_1 + 0x58) = 0;
      param_3 = param_3 - iVar3;
      thunk_EXT_FUN_0000af90(iVar4,0,0x40);
    }
    if (param_3 >> 6 != 0) {
      FUN_600898ec(param_1,iVar1);
      iVar1 = iVar1 + (param_3 & 0xffffffc0);
      param_3 = param_3 - (param_3 & 0xffffffc0);
    }
    if (param_3 != 0) {
      *(uint *)(param_1 + 0x58) = param_3;
      thunk_EXT_FUN_0000af88(param_1 + 0x18,iVar1,param_3);
    }
  }
  return 1;
}


