// 601004b2  FUN_601004b2  size=146 bytes
// --- callers ---
//   600c8acc FUN_600c8acc
//   600c8fd8 FUN_600c8fd8
//   600c8798 FUN_600c8798
//   600c89e0 FUN_600c89e0
//   600c9aac FUN_600c9aac
//   600c8a54 FUN_600c8a54
//   600c8b24 FUN_600c8b24
// --- callees ---


uint FUN_601004b2(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  for (local_10 = 0; local_10 < param_4; local_10 = local_10 + 1) {
    local_c = *(int *)(local_10 * 4 + param_2) - local_c;
    uVar1 = *(uint *)(local_10 * 4 + param_2);
    *(uint *)(local_10 * 4 + param_1) = local_c - *(int *)(local_10 * 4 + param_3);
    local_c = (uint)(uVar1 < local_c || local_c < *(uint *)(local_10 * 4 + param_1));
  }
  return local_c;
}


