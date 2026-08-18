// 600a1368  FUN_600a1368  size=38 bytes
// --- callers ---
//   60095df4 FUN_60095df4
// --- callees ---


undefined4 FUN_600a1368(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(DAT_600a1390 + 0x6f0);
  *(undefined4 *)(DAT_600a1390 + 0x6f0) = param_1;
  return uVar1;
}


