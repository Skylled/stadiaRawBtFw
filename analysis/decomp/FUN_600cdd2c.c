// 600cdd2c  FUN_600cdd2c  size=64 bytes
// --- callers ---
//   600a86d0 FUN_600a86d0
//   600aa5e4 FUN_600aa5e4
//   600b0444 FUN_600b0444
//   60092744 FUN_60092744
//   6006be9c FUN_6006be9c
//   6006d864 FUN_6006d864
//   600a8778 FUN_600a8778
// --- callees ---
//   600cddc8 FUN_600cddc8


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_600cdd2c(undefined1 *param_1,undefined4 param_2)

{
  undefined1 *local_78 [2];
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined4 local_64;
  
  local_64 = 0x7fffffff;
  local_70 = 0x7fffffff;
  local_6c = 0xffff0208;
  local_78[0] = param_1;
  local_68 = param_1;
  FUN_600cddc8(_DAT_20003d80,local_78,param_2);
  *local_78[0] = 0;
  return;
}


