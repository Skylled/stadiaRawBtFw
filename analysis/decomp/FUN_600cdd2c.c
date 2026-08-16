// 600cdd2c  FUN_600cdd2c  size=56 bytes
// --- callers ---
//   600b0444 FUN_600b0444
//   60092744 FUN_60092744
//   6006be9c FUN_6006be9c
//   600a86d0 FUN_600a86d0
//   6006d864 FUN_6006d864
//   600aa5e4 FUN_600aa5e4
//   600a8778 FUN_600a8778
// --- callees ---
//   600cddc8 FUN_600cddc8


void FUN_600cdd2c(undefined1 *param_1,undefined4 param_2)

{
  undefined1 *local_78 [2];
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined4 local_64;
  
  local_64 = 0x7fffffff;
  local_70 = 0x7fffffff;
  local_6c = DAT_600cdd68;
  local_78[0] = param_1;
  local_68 = param_1;
  FUN_600cddc8(*DAT_600cdd64,local_78,param_2);
  *local_78[0] = 0;
  return;
}


