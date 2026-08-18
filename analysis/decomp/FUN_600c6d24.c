// 600c6d24  FUN_600c6d24  size=122 bytes
// --- callers ---
// --- callees ---
//   600f35ae FUN_600f35ae


void FUN_600c6d24(int param_1,int param_2)

{
  undefined1 local_24 [2];
  undefined2 local_22;
  short local_20;
  int local_1c;
  undefined1 local_18;
  short local_e;
  int local_c;
  
  local_c = (uint)*(byte *)(param_1 + 0x17) * 0x20 + DAT_600c6da0 + 4;
  local_e = 0;
  local_20 = FUN_600f35ae(*(undefined2 *)(param_2 + 6),param_2 + 8,*(undefined2 *)(param_2 + 0x1c),
                          *(undefined1 *)(param_2 + 0x1e));
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
    (**(code **)(local_c + 0x18))(9,local_24);
  }
  return;
}


