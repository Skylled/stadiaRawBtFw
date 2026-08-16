// 600cbe5c  FUN_600cbe5c  size=90 bytes
// --- callers ---
//   60058574 system_tasks__60058574
//   60079270 FUN_60079270
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2


int FUN_600cbe5c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x174);
  if (*(int *)(param_1 + 0x15c) == DAT_600cbeb8) {
    iVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x164) == DAT_600cbeb8) {
    iVar2 = 1;
  }
  else {
    if (*(int *)(param_1 + 0x16c) != DAT_600cbeb8) {
      iVar2 = -1;
      goto LAB_600cbe9c;
    }
    iVar2 = 2;
  }
  iVar1 = param_1 + iVar2 * 8;
  *(undefined4 *)(iVar1 + 0x15c) = param_2;
  *(undefined4 *)(iVar1 + 0x160) = param_3;
LAB_600cbe9c:
  thunk_EXT_FUN_00007d10(param_1 + 0x174);
  return iVar2;
}


