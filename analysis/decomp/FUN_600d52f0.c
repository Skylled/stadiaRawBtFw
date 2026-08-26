// 600d52f0  FUN_600d52f0  size=104 bytes
// --- callers ---
//   6007a0b0 usb_audio_receive__6007a0b0
// --- callees ---
//   600d0658 FUN_600d0658
//   600d4946 FUN_600d4946


uint FUN_600d52f0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  char *pcVar4;
  
  if (*(char *)(param_1 + 0xad) == '\0') {
    uVar3 = 0xe;
  }
  else {
    pcVar4 = (char *)(param_1 + 0xaf);
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(pcVar4);
      cVar1 = *pcVar4;
      bVar2 = (bool)hasExclusiveAccess(pcVar4);
    } while (!bVar2);
    *pcVar4 = '\x01';
    DataMemoryBarrier(0x1b);
    if (cVar1 == '\0') {
      if (0x1ff < param_2) {
        param_2 = 0x200;
      }
      FUN_600d0658(*(undefined4 *)(param_1 + 4),5,param_1 + 0x120,param_2,param_4);
      uVar3 = FUN_600d4946();
      if ((uVar3 & 0xff) != 0) {
        DataMemoryBarrier(0x1b);
        *(undefined1 *)(param_1 + 0xaf) = 0;
        DataMemoryBarrier(0x1b);
      }
    }
    else {
      uVar3 = 9;
    }
  }
  return uVar3;
}


