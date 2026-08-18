// 600c6cb0  FUN_600c6cb0  size=110 bytes
// --- callers ---
// --- callees ---
//   600f3540 FUN_600f3540


void FUN_600c6cb0(int param_1,int param_2)

{
  undefined1 local_24 [2];
  undefined2 local_22;
  short local_20;
  undefined1 local_18;
  short local_e;
  int local_c;
  
  local_c = (uint)*(byte *)(param_1 + 0x17) * 0x20 + DAT_600c6d20 + 4;
  local_e = 0;
  local_20 = FUN_600f3540(*(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8));
  local_24[0] = *(undefined1 *)(local_c + 0x1c);
  local_22 = *(undefined2 *)(param_2 + 6);
  if (local_20 == 0) {
    local_18 = 0x85;
  }
  else {
    local_18 = 0;
  }
  if (*(int *)(local_c + 0x18) != 0) {
    local_e = local_20;
    (**(code **)(local_c + 0x18))(8,local_24);
  }
  return;
}


