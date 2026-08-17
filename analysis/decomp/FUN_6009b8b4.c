// 6009b8b4  FUN_6009b8b4  size=84 bytes
// --- callers ---
//   6009b9b0 FUN_6009b9b0
//   6009b914 FUN_6009b914
// --- callees ---


void FUN_6009b8b4(char param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if (*(int *)(DAT_6009b908 + 0x113c) != 0) {
    if (param_1 == '\x01') {
      local_c = DAT_6009b90c;
    }
    else if (param_1 == '\x02') {
      local_c = DAT_6009b910;
    }
    if (local_c != 0) {
      (**(code **)(DAT_6009b908 + 0x113c))(param_1,local_c);
    }
  }
  return;
}


