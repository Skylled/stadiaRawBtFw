// 600d3a78  FUN_600d3a78  size=76 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600d3a78(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0xc) + iVar3;
  if (*(uint *)(param_1 + 8) < (uint)(iVar3 + param_3)) {
    thunk_EXT_FUN_0000b572(iVar1,param_2,*(uint *)(param_1 + 8) - iVar3);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 8);
    if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
    }
    uVar2 = 0xf;
  }
  else {
    thunk_EXT_FUN_0000b572(iVar1,param_2,param_3);
    param_3 = param_3 + *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = param_3;
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      **(int **)(param_1 + 0x10) = param_3;
    }
    uVar2 = 0;
  }
  return uVar2;
}


