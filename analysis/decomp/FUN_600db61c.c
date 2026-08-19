// 600db61c  FUN_600db61c  size=38 bytes
// --- callers ---
//   60078e00 FUN_60078e00
// --- callees ---
//   600cbb14 FUN_600cbb14
//   60101b76 FUN_60101b76


int * FUN_600db61c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 uStack_10;
  
  *(undefined1 *)(*param_1 + 0x18) = 1;
  local_14 = param_2;
  uStack_10 = param_3;
  uVar1 = FUN_600cbb14(&local_14);
  FUN_60101b76(param_1 + 1,uVar1);
  return param_1;
}


