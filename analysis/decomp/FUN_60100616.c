// 60100616  FUN_60100616  size=106 bytes
// --- callers ---
//   600c89e0 FUN_600c89e0
// --- callees ---


uint FUN_60100616(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
    uVar1 = *(uint *)(local_10 * 4 + param_2);
    *(uint *)(local_10 * 4 + param_1) = local_c | uVar1 << 1;
    local_c = uVar1 >> 0x1f;
  }
  return local_c;
}


