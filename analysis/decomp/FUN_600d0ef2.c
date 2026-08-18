// 600d0ef2  FUN_600d0ef2  size=34 bytes
// --- callers ---
//   600d106e FUN_600d106e
//   60055350 FUN_60055350
// --- callees ---
//   600d15e8 FUN_600d15e8
//   6013d3e0 thunk_EXT_FUN_00008802


undefined4 FUN_600d0ef2(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_2;
  uStack_10 = param_3;
  thunk_EXT_FUN_00008802((int)&uStack_14 + 3);
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 0xcd) = 0;
  FUN_600d15e8(uStack_14._3_1_);
  return 0;
}


