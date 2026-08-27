// 6005f5d4  FUN_6005f5d4  size=50 bytes
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   60052d30 FUN_60052d30
//   600ceb7a FUN_600ceb7a
//   60052d20 FUN_60052d20


undefined4 FUN_6005f5d4(byte *param_1)

{
  uint local_14;
  
  local_14 = (uint)*param_1;
  if (local_14 == 0) {
    FUN_600ceb7a(&local_14);
    FUN_60052d30(DAT_6005f608,&local_14);
    FUN_60052d20(DAT_6005f60c);
    *param_1 = 1;
  }
  return 0;
}


