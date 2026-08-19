// 600db97e  FUN_600db97e  size=62 bytes
// --- callers ---
// --- callees ---
//   600db8e8 FUN_600db8e8
//   600db8b8 FUN_600db8b8


void FUN_600db97e(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  uVar3 = FUN_600db8b8();
  DataMemoryBarrier(0x1b);
  pcVar4 = (char *)(param_1 + 0x94b);
  *(undefined4 *)(param_1 + 0x964) = uVar3;
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(pcVar4);
    cVar1 = *pcVar4;
    bVar2 = (bool)hasExclusiveAccess(pcVar4);
  } while (!bVar2);
  *pcVar4 = '\0';
  DataMemoryBarrier(0x1b);
  if (cVar1 != '\0') {
    FUN_600db8e8(param_1 + 4);
  }
  return;
}


