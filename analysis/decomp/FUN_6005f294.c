// 6005f294  FUN_6005f294  size=84 bytes
// --- callers ---
//   6006ff00 FUN_6006ff00
// --- callees ---


bool FUN_6005f294(uint param_1)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  
  iVar3 = DAT_6005f2e8;
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  sVar1 = *(short *)(DAT_6005f2e8 + param_1 * 2);
  if (sVar1 != 0) {
    *(short *)(DAT_6005f2e8 + param_1 * 2) = sVar1 + -1;
    if (sVar1 != 1) goto LAB_6005f2b4;
    pcVar4 = *(code **)(iVar3 + 0xc);
    do {
      (*pcVar4)(param_1);
LAB_6005f2b4:
      do {
        if (**(byte **)(iVar3 + 4) != param_1) {
          iVar3 = 0;
          goto LAB_6005f2d8;
        }
        param_1 = (uint)(*(byte **)(iVar3 + 4))[1];
        sVar1 = *(short *)(iVar3 + param_1 * 2);
        if (sVar1 == 0) goto LAB_6005f2d6;
        *(short *)(iVar3 + param_1 * 2) = sVar1 + -1;
      } while (sVar1 != 1);
      pcVar4 = *(code **)(iVar3 + 0xc);
    } while( true );
  }
LAB_6005f2d6:
  iVar3 = 9;
LAB_6005f2d8:
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar5 & 1) == 1);
  }
  return iVar3 == 0;
}


