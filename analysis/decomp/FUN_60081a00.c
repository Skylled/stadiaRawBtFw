// 60081a00  FUN_60081a00  size=48 bytes
// --- callers ---
//   60081ab4 gatt_server__60081ab4
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   60101fd8 FUN_60101fd8


void FUN_60081a00(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (-1 < (int)uVar1) {
    if ((param_2 < uVar1) && (param_2 = param_2 * 2, uVar1 < param_2)) {
      if ((int)param_2 < 0) {
        *param_1 = 0x7fffffff;
      }
      else {
        *param_1 = param_2;
      }
    }
    thunk_EXT_FUN_0000b532(*param_1 + 1,param_2,param_3,param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_60101fd8(DAT_60081a30);
}


