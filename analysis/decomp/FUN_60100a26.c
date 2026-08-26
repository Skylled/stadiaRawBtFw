// 60100a26  FUN_60100a26  size=58 bytes
// --- callers ---
//   600caec8 FUN_600caec8
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_60100a26(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  uVar2 = *(int *)(param_1 + 8) - iVar3;
  iVar1 = *(int *)(param_1 + 4) + iVar3;
  if (param_3 < uVar2) {
    iVar3 = param_3 + iVar3;
    thunk_EXT_FUN_0000b572(iVar1);
  }
  else {
    iVar3 = param_3 - uVar2;
    thunk_EXT_FUN_0000b572(iVar1,param_2,uVar2);
    thunk_EXT_FUN_0000b572(*(undefined4 *)(param_1 + 4),param_2 + uVar2,iVar3);
  }
  *(int *)(param_1 + 0xc) = iVar3;
  return;
}


