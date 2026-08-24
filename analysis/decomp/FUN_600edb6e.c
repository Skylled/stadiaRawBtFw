// 600edb6e  FUN_600edb6e  size=90 bytes
// --- callers ---
//   600edbc8 FUN_600edbc8
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600e092c FUN_600e092c


void FUN_600edb6e(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_2 & 0xc0000000) == 0) {
    iVar5 = param_2 << 2;
    iVar1 = FUN_600e092c(iVar5);
    if (iVar1 != 0) {
      if (iVar5 != 0) {
        thunk_EXT_FUN_0000b5ba(iVar1,0,iVar5);
      }
      iVar5 = *(int *)(param_1 + 4);
      iVar6 = *(int *)(param_1 + 8);
      for (iVar3 = 0; iVar6 != iVar3; iVar3 = iVar3 + 1) {
        iVar4 = *(int *)(iVar5 + iVar3 * 4);
        while (iVar4 != 0) {
          iVar7 = *(int *)(iVar4 + 4);
          iVar2 = *(uint *)(iVar4 + 8) - param_2 * (*(uint *)(iVar4 + 8) / param_2);
          *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar1 + iVar2 * 4);
          *(int *)(iVar1 + iVar2 * 4) = iVar4;
          iVar4 = iVar7;
        }
      }
      thunk_EXT_FUN_0000ac5e();
      *(int *)(param_1 + 4) = iVar1;
      *(uint *)(param_1 + 8) = param_2;
    }
  }
  return;
}


