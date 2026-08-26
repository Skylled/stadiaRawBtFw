// 60100424  FUN_60100424  size=142 bytes
// --- callers ---
//   600c8acc FUN_600c8acc
//   600c8fd8 FUN_600c8fd8
//   600c9aac FUN_600c9aac
//   600c8a54 FUN_600c8a54
// --- callees ---


uint FUN_60100424(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  for (local_10 = 0; local_10 < param_4; local_10 = local_10 + 1) {
    uVar1 = *(int *)(local_10 * 4 + param_2) + local_c;
    uVar2 = *(int *)(local_10 * 4 + param_3) + uVar1;
    local_c = (uint)(uVar1 < local_c || uVar2 < *(uint *)(local_10 * 4 + param_3));
    *(uint *)(local_10 * 4 + param_1) = uVar2;
  }
  return local_c;
}


