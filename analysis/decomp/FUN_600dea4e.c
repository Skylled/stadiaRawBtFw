// 600dea4e  FUN_600dea4e  size=50 bytes
// --- callers ---
// --- callees ---
//   6013d138 thunk_EXT_FUN_0000645c


void FUN_600dea4e(int param_1)

{
  bool bVar1;
  uint *puVar2;
  
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  if (*(char *)(param_1 + 0x6c) != '\0') {
    puVar2 = (uint *)(param_1 + 0x70);
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(puVar2);
      bVar1 = (bool)hasExclusiveAccess(puVar2);
    } while (!bVar1);
    *puVar2 = *puVar2 | 4;
    DataMemoryBarrier(0x1b);
    thunk_EXT_FUN_0000645c();
  }
  return;
}


