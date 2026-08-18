// 600c6da4  FUN_600c6da4  size=118 bytes
// --- callers ---
// --- callees ---
//   600f3620 FUN_600f3620


void FUN_600c6da4(int param_1,int param_2)

{
  undefined1 local_24 [2];
  undefined2 local_22;
  short local_20;
  int local_1c;
  undefined1 local_18;
  short local_e;
  int local_c;
  
  local_c = (uint)*(byte *)(param_1 + 0x17) * 0x20 + DAT_600c6e1c + 4;
  local_e = 0;
  local_20 = FUN_600f3620(*(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 0x1c),param_2 + 8);
  local_24[0] = *(undefined1 *)(local_c + 0x1c);
  local_22 = *(undefined2 *)(param_2 + 6);
  local_1c = param_2 + 8;
  if (local_20 == 0) {
    local_18 = 0x85;
  }
  else {
    local_18 = 0;
  }
  if (*(int *)(local_c + 0x18) != 0) {
    local_e = local_20;
    (**(code **)(local_c + 0x18))(10,local_24);
  }
  return;
}


