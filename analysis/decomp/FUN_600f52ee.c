// 600f52ee  FUN_600f52ee  size=174 bytes
// --- callers ---
//   600f3540 FUN_600f3540
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f56fe FUN_600f56fe
//   600f578e FUN_600f578e
//   600f55a4 FUN_600f55a4


undefined2 FUN_600f52ee(undefined4 param_1,short param_2,short param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_4;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_28 = 2;
  local_24 = 0x2802;
  local_4._0_2_ = (short)param_4;
  if (((((short)local_4 != 0) && (param_2 != 0)) && (param_3 != 0)) &&
     (local_4 = param_4, local_14 = FUN_600f55a4(param_1,&local_28,1), local_14 != 0)) {
    iVar1 = FUN_600f578e(param_1,local_14 + 4,0x1c);
    if (iVar1 != 0) {
      *(short *)(*(int *)(local_14 + 4) + 0x16) = param_2;
      *(short *)(*(int *)(local_14 + 4) + 0x18) = param_3;
      thunk_EXT_FUN_0000b572(*(undefined4 *)(local_14 + 4),&local_4,0x14);
      return *(undefined2 *)(local_14 + 0xc);
    }
    FUN_600f56fe(param_1,local_14);
  }
  return 0;
}


