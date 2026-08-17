// 6009819c  FUN_6009819c  size=198 bytes
// --- callers ---
//   60092838 FUN_60092838
//   600987dc FUN_600987dc
// --- callees ---
//   60097904 FUN_60097904
//   60097dc8 FUN_60097dc8
//   600979e4 FUN_600979e4
//   600efe4c FUN_600efe4c
//   60097b20 FUN_60097b20
//   600977fc FUN_600977fc


char FUN_6009819c(undefined1 param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  char local_9;
  
  local_9 = '\x05';
  if (*(int *)(DAT_60098280 + 200) == 0) {
    switch(param_2) {
    case '\0':
      local_9 = FUN_600979e4(param_1,param_3);
      break;
    case '\x01':
      local_9 = FUN_600efe4c(param_1,param_3);
      break;
    case '\x02':
    case '\x03':
      local_9 = FUN_60097b20(param_1,param_2,param_3);
      break;
    case '\x04':
      local_9 = FUN_60097904(param_1,param_3);
      break;
    case '\x05':
      local_9 = FUN_600977fc(param_1,param_3,param_2);
      break;
    case '\x06':
      local_9 = FUN_60097dc8(param_1,param_3);
    }
    if ((local_9 == '\x01') && (param_2 != '\x01')) {
      *(byte *)(DAT_60098280 + 1) = param_2 << 4 | 2;
      *(undefined4 *)(DAT_60098280 + 200) = param_4;
    }
  }
  else {
    local_9 = '\x02';
  }
  return local_9;
}


