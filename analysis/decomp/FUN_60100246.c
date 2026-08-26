// 60100246  FUN_60100246  size=54 bytes
// --- callers ---
//   600fffbc FUN_600fffbc
//   600ffe42 FUN_600ffe42
//   60100680 FUN_60100680
//   600c9aac FUN_600c9aac
//   600c8798 FUN_600c8798
// --- callees ---


void FUN_60100246(int param_1,uint param_2)

{
  undefined4 local_c;
  
  for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
    *(undefined4 *)(local_c * 4 + param_1) = 0;
  }
  return;
}


