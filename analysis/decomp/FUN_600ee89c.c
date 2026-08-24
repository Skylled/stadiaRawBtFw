// 600ee89c  FUN_600ee89c  size=86 bytes
// --- callers ---
//   600fe05a FUN_600fe05a
// --- callees ---
//   600ee8f2 FUN_600ee8f2
//   6009496c FUN_6009496c
//   6009506c FUN_6009506c


undefined1 FUN_600ee89c(undefined2 param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  undefined1 local_9;
  
  iVar1 = FUN_6009506c(param_1);
  local_9 = 0x85;
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 8) == '\x02') {
      local_9 = FUN_600ee8f2(param_1,param_2,param_3);
    }
    else {
      local_9 = FUN_6009496c(param_1,param_2);
    }
  }
  return local_9;
}


