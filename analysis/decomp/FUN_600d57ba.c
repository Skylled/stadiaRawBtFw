// 600d57ba  FUN_600d57ba  size=26 bytes
// --- callers ---
//   60062f9c usb_host_audio__60062f9c
// --- callees ---


int FUN_600d57ba(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(param_1);
    iVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = iVar2 + 1;
  DataMemoryBarrier(0x1b);
  return iVar2;
}


