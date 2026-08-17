// 600985f8  FUN_600985f8  size=106 bytes
// --- callers ---
//   600ee1fe FUN_600ee1fe
// --- callees ---
//   60098530 FUN_60098530
//   6009837c FUN_6009837c


char FUN_600985f8(char param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined4 param_5)

{
  undefined1 local_11;
  
  if (param_1 == '\0') {
    *(undefined4 *)(DAT_60098664 + 0xc4) = 0;
  }
  else {
    *(undefined4 *)(DAT_60098664 + 0xc4) = param_5;
  }
  local_11 = FUN_6009837c();
  if (local_11 != '\x03') {
    local_11 = FUN_60098530(2,0,param_1,param_2,param_3,param_4);
  }
  return local_11;
}


