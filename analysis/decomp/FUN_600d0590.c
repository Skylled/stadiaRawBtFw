// 600d0590  FUN_600d0590  size=80 bytes
// --- callers ---
// --- callees ---
//   600cfe6a FUN_600cfe6a
//   600d15e8 FUN_600d15e8
//   600cfc8e FUN_600cfc8e
//   6013d3e0 thunk_EXT_FUN_00008802


undefined4 FUN_600d0590(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 3;
  }
  else {
    uStack_14 = param_2;
    uStack_10 = param_3;
    if (param_1[3] != 0) {
      FUN_600cfc8e(param_1,param_1 + 3,param_3,param_1[3],param_1);
    }
    if (param_1[4] != 0) {
      FUN_600cfc8e(param_1,param_1 + 4);
    }
    uVar1 = FUN_600cfe6a(param_1);
    thunk_EXT_FUN_00008802((int)&uStack_14 + 3);
    *(undefined1 *)(param_1 + 5) = 0;
    *(undefined1 *)((int)param_1 + 0x16) = 0;
    *(undefined1 *)(param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 0x1a) = 0;
    *param_1 = 0;
    param_1[1] = 0;
    FUN_600d15e8(uStack_14._3_1_);
  }
  return uVar1;
}


