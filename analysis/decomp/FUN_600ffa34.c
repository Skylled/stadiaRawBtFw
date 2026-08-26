// 600ffa34  FUN_600ffa34  size=166 bytes
// --- callers ---
//   600ffada FUN_600ffada
// --- callees ---
//   600aff88 FUN_600aff88
//   600ff986 FUN_600ff986
//   600f6a8a FUN_600f6a8a


char FUN_600ffa34(int param_1,undefined2 param_2,byte param_3,undefined4 param_4)

{
  undefined1 local_9;
  
  if (param_1 == 0) {
    local_9 = -0x7b;
  }
  else {
    param_3 = param_3 & 0x7f;
    if ((*(char *)(param_1 + 0xf8) == *(char *)(param_1 + 0xf9)) || (param_3 == 0x1e)) {
      local_9 = FUN_600ff986(param_1,param_4);
      if ((local_9 == -0x71) || (local_9 == '\0')) {
        if ((param_3 != 0x1e) && (param_3 != 0x52)) {
          FUN_600f6a8a(param_1);
          FUN_600aff88(param_1,param_2,0,param_3,0);
        }
        local_9 = '\0';
      }
    }
    else {
      local_9 = -0x7a;
      FUN_600aff88(param_1,param_2,1,param_3,param_4);
    }
  }
  return local_9;
}


