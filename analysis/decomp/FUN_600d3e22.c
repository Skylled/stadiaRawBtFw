// 600d3e22  FUN_600d3e22  size=40 bytes
// --- callers ---
//   6005b1c0 application_state__6005b1c0
// --- callees ---
//   6005ae68 FUN_6005ae68


void FUN_600d3e22(int param_1,undefined3 param_2,undefined4 param_3)

{
  DataMemoryBarrier(0x1b);
  *(char *)(param_1 + 4) = (char)param_2;
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  FUN_6005ae68(param_1 + 8,&stack0xfffffff7,param_3,*(undefined1 *)(param_1 + 4),param_1,
               CONCAT13(*(undefined1 *)(param_1 + 4),param_2));
  return;
}


