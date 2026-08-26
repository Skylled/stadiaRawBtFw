// 60100544  FUN_60100544  size=104 bytes
// --- callers ---
//   600c9aac FUN_600c9aac
//   60100166 FUN_60100166
// --- callees ---


void FUN_60100544(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  while (local_10 = param_3 + -1, -1 < local_10) {
    uVar1 = *(uint *)(local_10 * 4 + param_2);
    *(uint *)(local_10 * 4 + param_1) = local_c | uVar1 >> 1;
    local_c = uVar1 << 0x1f;
    param_3 = local_10;
  }
  return;
}


