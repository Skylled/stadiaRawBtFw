// 600d83e0  FUN_600d83e0  size=104 bytes
// --- callers ---
//   60068b80 battery_gauge_bq2742X__60068b80
//   600d87f4 FUN_600d87f4
//   600d855e FUN_600d855e
// --- callees ---
//   600d83bc FUN_600d83bc
//   6013cef8 thunk_EXT_FUN_0000737c
//   6013d0b0 thunk_EXT_FUN_00001ea4


uint FUN_600d83e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined1 local_14 [4];
  
  uVar1 = FUN_600d83bc(param_1,0x3e,param_2,200);
  if ((uVar1 & 0xff) == 0) {
    thunk_EXT_FUN_0000737c(5);
    uVar1 = FUN_600d83bc(param_1,0x3f,param_3,200);
    if ((uVar1 & 0xff) == 0) {
      thunk_EXT_FUN_0000737c(5);
      if (param_4 != 0) {
        local_14[0] = 0x60;
        uVar1 = thunk_EXT_FUN_00001ea4
                          (*param_1,*(undefined1 *)(param_1 + 1),local_14,1,param_4,1,200);
        if ((uVar1 & 0xff) != 0) {
          return uVar1;
        }
        thunk_EXT_FUN_0000737c(5);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


