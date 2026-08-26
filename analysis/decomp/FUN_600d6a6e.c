// 600d6a6e  FUN_600d6a6e  size=88 bytes
// --- callers ---
// --- callees ---
//   600d15e4 thunk_EXT_FUN_000080d8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d15c8 FUN_600d15c8
//   600d6956 FUN_600d6956
//   600d6908 FUN_600d6908


void FUN_600d6a6e(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_600d15c8(*(undefined2 *)(param_1 + 0x28c));
  iVar2 = *(int *)(param_1 + 0x290);
  *(undefined4 *)(param_1 + 0x290) = uVar1;
  if (iVar2 != 0) {
    thunk_EXT_FUN_000080d8(iVar2);
  }
  if ((*(int *)(param_1 + 0x290) != 0) && (param_4 == 0)) {
    thunk_EXT_FUN_0000b572
              (*(int *)(param_1 + 0x290),*(undefined4 *)(param_1 + 0x294),
               *(undefined2 *)(param_1 + 0x28c));
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x298) = 1;
    DataMemoryBarrier(0x1b);
  }
  FUN_600d6956(param_1 + 0x294,0);
  FUN_600d6908(param_1,param_4,0,param_4);
  return;
}


