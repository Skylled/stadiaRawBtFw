// 600f4376  FUN_600f4376  size=74 bytes
// --- callers ---
//   600ac438 FUN_600ac438
// --- callees ---


undefined1 FUN_600f4376(char param_1,undefined1 *param_2)

{
  undefined1 local_9;
  
  local_9 = 1;
  if (param_1 == '\x04') {
    *param_2 = 2;
  }
  else if (param_1 == '\x05') {
    *param_2 = 3;
  }
  else if (param_1 == '\x03') {
    *param_2 = 1;
  }
  else {
    local_9 = 0;
  }
  return local_9;
}


