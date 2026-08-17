// 60068ae0  battery_gauge_bq2742X__60068ae0  size=152 bytes
// src: battery_gauge_bq2742X.cc
// --- callers ---
//   600d87f4 FUN_600d87f4
//   600d855e FUN_600d855e
//   60068b80 battery_gauge_bq2742X__60068b80
// --- callees ---
//   600d83bc FUN_600d83bc
//   6013d0b0 thunk_EXT_FUN_00001ea4
//   6013cef8 thunk_EXT_FUN_0000737c
//   6010165c FUN_6010165c


/* src: battery_gauge_bq2742X.cc */

uint battery_gauge_bq2742X__60068ae0
               (undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 local_1c [3];
  byte local_19 [5];
  
  uVar1 = FUN_600d83bc(param_1,0x60,param_2,200);
  if ((uVar1 & 0xff) == 0) {
    thunk_EXT_FUN_0000737c(5);
    uVar1 = FUN_600d83bc(param_1,0x3e,param_3,200);
    if ((uVar1 & 0xff) == 0) {
      thunk_EXT_FUN_0000737c(5);
      uVar1 = FUN_600d83bc(param_1,0x3f,param_4,200);
      if ((uVar1 & 0xff) == 0) {
        thunk_EXT_FUN_0000737c(5);
        local_1c[0] = 0x60;
        uVar1 = thunk_EXT_FUN_00001ea4
                          (*param_1,*(undefined1 *)(param_1 + 1),local_1c,1,local_19,1,200);
        if ((uVar1 & 0xff) == 0) {
          if (local_19[0] == param_2) {
            uVar1 = 0;
          }
          else {
            FUN_6010165c(0x28,DAT_60068b7c,0x65,DAT_60068b78,param_2,(uint)local_19[0]);
            uVar1 = 0xd;
          }
        }
      }
    }
  }
  return uVar1;
}


