// 600d8df2  FUN_600d8df2  size=58 bytes
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   600926a0 FUN_600926a0


void FUN_600d8df2(int param_1,uint param_2)

{
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  if ((*(char *)(param_1 + 0x181) != '\0') != param_2) {
    DataMemoryBarrier(0x1b);
    *(char *)(param_1 + 0x181) = (char)param_2;
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x182) = 1;
    DataMemoryBarrier(0x1b);
    FUN_600926a0();
    return;
  }
  return;
}


