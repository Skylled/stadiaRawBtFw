// 600a5840  FUN_600a5840  size=54 bytes
// --- callers ---
//   600a333c FUN_600a333c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600a5840(undefined1 param_1)

{
  *(undefined1 *)(DAT_600a5878 + 0x1174) = param_1;
  thunk_EXT_FUN_0000b5ba(DAT_600a587c,0xff,6);
  *(undefined4 *)(DAT_600a5878 + 0x116c) = 5000;
  return;
}


