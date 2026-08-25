// 600f3f70  FUN_600f3f70  size=232 bytes
// --- callers ---
// --- callees ---
//   600abd38 FUN_600abd38
//   600abcb4 FUN_600abcb4
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f38d0 FUN_600f38d0


void FUN_600f3f70(undefined2 param_1,undefined4 param_2,byte param_3,int param_4)

{
  undefined1 auStack_274 [610];
  char local_12;
  undefined1 local_11;
  
  local_11 = 4;
  local_12 = '\0';
  thunk_EXT_FUN_0000b5ba(auStack_274,0,0x262);
  if (param_3 != 3) {
    if (param_3 < 4) {
      if (param_3 == 1) {
        local_11 = FUN_600abcb4(1,param_4,auStack_274);
      }
      else if (param_3 == 2) {
        if (*(char *)(param_4 + 0x25e) == '\0') {
          local_12 = '\x01';
        }
        local_11 = FUN_600abd38(2,param_4);
      }
      goto LAB_600f402c;
    }
    if (param_3 == 4) {
      local_12 = '\x01';
      goto LAB_600f402c;
    }
    if (param_3 != 0x52) goto LAB_600f402c;
  }
  local_12 = '\x01';
LAB_600f402c:
  if (local_12 == '\0') {
    FUN_600f38d0(param_1,param_2,local_11,auStack_274);
  }
  return;
}


