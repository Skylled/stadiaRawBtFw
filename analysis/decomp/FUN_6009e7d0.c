// 6009e7d0  FUN_6009e7d0  size=102 bytes
// --- callers ---
//   6009e84c FUN_6009e84c
// --- callees ---


undefined1 FUN_6009e7d0(code *param_1,undefined1 param_2)

{
  undefined1 local_9;
  
  local_9 = 0;
  switch(param_2) {
  case 0:
    local_9 = (*param_1)(1);
    break;
  case 1:
    local_9 = (*param_1)(0x20);
    break;
  case 2:
    local_9 = (*param_1)(0x200);
    break;
  case 3:
    local_9 = (*param_1)(0x40);
    break;
  case 4:
    local_9 = (*param_1)(0x10);
  }
  return local_9;
}


