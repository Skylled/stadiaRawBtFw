// 600a333c  FUN_600a333c  size=54 bytes
// --- callers ---
// --- callees ---
//   600a5840 FUN_600a5840
//   60098ea0 FUN_60098ea0
//   600a0060 FUN_600a0060
//   600a24a8 FUN_600a24a8
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600a333c(void)

{
  thunk_EXT_FUN_0000b5ba(DAT_600a3374,0,&LAB_00001ae4);
  *(undefined1 *)(DAT_600a3374 + 0x1abc) = *DAT_600a3378;
  FUN_600a24a8();
  FUN_60098ea0();
  FUN_600a5840(4);
  FUN_600a0060();
  return;
}


