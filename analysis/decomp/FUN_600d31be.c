// 600d31be  FUN_600d31be  size=14 bytes
// --- callers ---
//   6005663c FUN_6005663c
// --- callees ---
//   600d3196 FUN_600d3196


void FUN_600d31be(undefined4 param_1,int param_2,byte *param_3)

{
  *(ushort *)(*(int *)(param_2 + 0x1c) + 2) = (ushort)*param_3;
  FUN_600d3196(param_1,param_2,0);
  return;
}


