// 600d6256  FUN_600d6256  size=162 bytes
// --- callers ---
//   600d62f8 FUN_600d62f8
// --- callees ---
//   60101d4a thunk_FUN_60101ccc
//   6013d378 thunk_EXT_FUN_0000b532
//   60101d4e FUN_60101d4e
//   600d5be6 FUN_600d5be6


int * FUN_600d6256(int *param_1,int param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_2 + 4;
  iVar1 = 1;
  iVar5 = iVar6;
  iVar2 = *(int *)(param_2 + 8);
  while (iVar2 != 0) {
    iVar1 = FUN_600d5be6(param_3,iVar2 + 0x10);
    iVar5 = iVar2;
    if (iVar1 == 0) {
      iVar2 = *(int *)(iVar2 + 0xc);
    }
    else {
      iVar2 = *(int *)(iVar2 + 8);
    }
  }
  iVar2 = iVar5;
  if (iVar1 != 0) {
    if (*(int *)(param_2 + 0xc) == iVar5) goto LAB_600d62ee;
    iVar2 = thunk_FUN_60101ccc(iVar5);
  }
  iVar1 = FUN_600d5be6(iVar2 + 0x10,param_3);
  if (iVar1 == 0) {
    *param_1 = iVar2;
    *(undefined1 *)(param_1 + 1) = 0;
    return param_1;
  }
LAB_600d62ee:
  if (iVar6 == iVar5) {
    uVar3 = 1;
  }
  else {
    uVar3 = FUN_600d5be6(param_3,iVar5 + 0x10);
  }
  iVar2 = thunk_EXT_FUN_0000b532(0x18);
  *(undefined2 *)(iVar2 + 0x10) = *param_3;
  uVar4 = *(undefined4 *)(param_3 + 2);
  *(undefined4 *)(param_3 + 2) = 0;
  *(undefined4 *)(iVar2 + 0x14) = uVar4;
  FUN_60101d4e(uVar3,iVar2,iVar5,iVar6);
  iVar5 = *(int *)(param_2 + 0x14);
  *param_1 = iVar2;
  *(int *)(param_2 + 0x14) = iVar5 + 1;
  *(undefined1 *)(param_1 + 1) = 1;
  return param_1;
}


