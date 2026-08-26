// 60100a60  FUN_60100a60  size=82 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


int FUN_60100a60(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = *(uint *)(param_1 + 0xc);
  iVar6 = 0;
  do {
    uVar4 = *(uint *)(param_1 + 0x10);
    iVar3 = *(int *)(param_1 + 8);
    if (uVar4 <= uVar5) {
      uVar4 = uVar4 + iVar3;
    }
    iVar1 = *(int *)(param_1 + 4) + uVar5;
    uVar2 = (uVar4 - 1) - uVar5;
    uVar4 = iVar3 - uVar5;
    if (param_3 <= iVar3 - uVar5) {
      uVar4 = param_3;
    }
    if (uVar2 <= uVar4) {
      uVar4 = uVar2;
    }
    uVar5 = uVar5 + uVar4;
    thunk_EXT_FUN_0000b572(iVar1,param_2,uVar4,iVar3,param_4);
    iVar6 = iVar6 + uVar4;
    param_2 = param_2 + uVar4;
    if (*(uint *)(param_1 + 8) == uVar5) {
      uVar5 = 0;
    }
    param_3 = param_3 - uVar4;
    *(uint *)(param_1 + 0xc) = uVar5;
  } while (param_3 != 0);
  return iVar6;
}


