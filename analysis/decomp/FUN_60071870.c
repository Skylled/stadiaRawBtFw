// 60071870  FUN_60071870  size=16 bytes
// --- callers ---
//   6005ea2c FUN_6005ea2c
//   6005e734 FUN_6005e734
//   6005e884 FUN_6005e884
//   600d4664 FUN_600d4664
// --- callees ---


uint FUN_60071870(void)

{
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  return *DAT_60071880 & 0xff;
}


