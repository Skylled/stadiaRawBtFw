// 600d1662  FUN_600d1662  size=44 bytes
// --- callers ---
// --- callees ---
//   6013d3e0 thunk_EXT_FUN_00008802
//   6013d0f0 thunk_EXT_FUN_00007018
//   600d15e8 FUN_600d15e8


bool FUN_600d1662(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (param_1 != (undefined4 *)0x0) {
    uStack_14 = param_2;
    uStack_10 = param_3;
    thunk_EXT_FUN_00007018(*param_1);
    thunk_EXT_FUN_00008802((int)&uStack_14 + 3);
    *(undefined1 *)(param_1 + 0x15) = 0;
    FUN_600d15e8(uStack_14._3_1_);
  }
  return param_1 == (undefined4 *)0x0;
}


