// 60098d8c  FUN_60098d8c  size=166 bytes
// --- callers ---
// --- callees ---
//   60097298 FUN_60097298
//   60098d2c FUN_60098d2c
//   600f00cc FUN_600f00cc
//   600f00be FUN_600f00be
//   600f001c FUN_600f001c
//   600986a0 FUN_600986a0
//   600f0032 FUN_600f0032
//   60098c3c FUN_60098c3c
//   600f0048 FUN_600f0048


undefined1 FUN_60098d8c(undefined1 param_1,undefined2 *param_2)

{
  undefined1 local_9;
  
  local_9 = 1;
  switch(param_1) {
  case 1:
    FUN_600f00be();
    break;
  case 2:
    FUN_60098c3c();
    break;
  case 3:
    local_9 = FUN_600f0032(param_2);
    break;
  case 4:
    local_9 = FUN_600f0048(*param_2);
    break;
  case 5:
    local_9 = FUN_600f001c(param_2);
    break;
  case 6:
    break;
  default:
    local_9 = 0;
    break;
  case 8:
    local_9 = FUN_600f00cc(param_2);
    break;
  case 0xf:
    local_9 = FUN_600986a0(param_2);
    break;
  case 0x10:
    local_9 = FUN_60098d2c(param_2);
    break;
  case 0x11:
    local_9 = FUN_60097298(param_2);
  }
  return local_9;
}


