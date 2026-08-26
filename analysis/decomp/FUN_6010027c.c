// 6010027c  FUN_6010027c  size=64 bytes
// --- callers ---
//   600c9aac FUN_600c9aac
//   600c8798 FUN_600c8798
// --- callees ---


void FUN_6010027c(int param_1,int param_2,uint param_3)

{
  undefined4 local_c;
  
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    *(undefined4 *)(local_c * 4 + param_1) = *(undefined4 *)(param_2 + local_c * 4);
  }
  return;
}


