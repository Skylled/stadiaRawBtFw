// 600da77c  FUN_600da77c  size=52 bytes
// --- callers ---
//   600da7b0 FUN_600da7b0
// --- callees ---
//   600da766 FUN_600da766
//   6010209a FUN_6010209a


undefined4 FUN_600da77c(int *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int *piStack_18;
  uint local_14;
  undefined4 local_10;
  uint local_c;
  
  piStack_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  FUN_600da766(&piStack_18,param_1);
  if ((local_14 & 0xff) == 0) {
    local_10 = (**(code **)(*param_1 + 0x10))(param_1);
  }
  else {
    FUN_600da766(&local_10,param_1);
    if ((local_c & 0xff) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_6010209a();
    }
  }
  return local_10;
}


