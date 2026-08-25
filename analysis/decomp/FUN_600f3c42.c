// 600f3c42  FUN_600f3c42  size=104 bytes
// --- callers ---
//   600ff4de FUN_600ff4de
//   600fdab8 FUN_600fdab8
//   600ff31a FUN_600ff31a
//   600fda2c FUN_600fda2c
//   600aae30 FUN_600aae30
//   600ff21c FUN_600ff21c
// --- callees ---
//   600f74a8 FUN_600f74a8
//   600f5b32 FUN_600f5b32
//   600afd28 FUN_600afd28


undefined1 FUN_600f3c42(undefined1 param_1,undefined4 param_2,char param_3,char param_4)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0;
  iVar1 = FUN_600afd28(param_1);
  if (iVar1 == 0) {
    local_9 = 0;
  }
  else if (param_3 == '\0') {
    if (param_4 == '\x02') {
      local_9 = FUN_600f74a8(param_1,1,param_2,1);
    }
  }
  else {
    local_9 = FUN_600f5b32(iVar1,param_2,param_4);
  }
  return local_9;
}


