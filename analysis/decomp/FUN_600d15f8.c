// 600d15f8  FUN_600d15f8  size=46 bytes
// --- callers ---
//   600d2d94 FUN_600d2d94
// --- callees ---
//   6013d3e0 thunk_EXT_FUN_00008802
//   600d15e8 FUN_600d15e8
//   600c9d88 event_groups__600c9d88


undefined4 FUN_600d15f8(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 1;
  }
  else {
    uStack_14 = param_2;
    uStack_10 = param_3;
    if (*param_1 != 0) {
      event_groups__600c9d88();
    }
    thunk_EXT_FUN_00008802((int)&uStack_14 + 3);
    *(undefined1 *)(param_1 + 10) = 0;
    FUN_600d15e8(uStack_14._3_1_);
    uVar1 = 0;
  }
  return uVar1;
}


