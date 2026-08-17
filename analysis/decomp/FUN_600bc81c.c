// 600bc81c  FUN_600bc81c  size=24 bytes
// --- callers ---
//   60139ace FUN_60139ace
// --- callees ---
//   600b5e00 FUN_600b5e00


void FUN_600bc81c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int unaff_r7;
  
  while( true ) {
    FUN_600b5e00(param_1,param_2,param_3);
    *(undefined4 *)(unaff_r7 + 0x10) = *(undefined4 *)(unaff_r7 + 8);
    if (*(int *)(unaff_r7 + 0x10) == 0) break;
    *(undefined4 *)(unaff_r7 + 8) = *(undefined4 *)(*(int *)(unaff_r7 + 0x10) + 0x124);
    param_3 = 0;
    param_2 = 0x21;
    param_1 = *(undefined4 *)(unaff_r7 + 0x10);
  }
  return;
}


