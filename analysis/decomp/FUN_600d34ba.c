// 600d34ba  FUN_600d34ba  size=60 bytes
// --- callers ---
// --- callees ---


int * FUN_600d34ba(int *param_1)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if (*(char *)((int)param_1 + 5) != '\0') {
    iVar5 = *param_1;
    bVar1 = *(byte *)(param_1 + 1);
    uVar6 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar6 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    while( true ) {
      uVar4 = (uint)bVar1;
      sVar2 = *(short *)(iVar5 + uVar4 * 2);
      if (sVar2 == 0) break;
      *(short *)(iVar5 + uVar4 * 2) = sVar2 + -1;
      if (sVar2 == 1) {
        (**(code **)(iVar5 + 0xc))(uVar4);
      }
      if (**(byte **)(iVar5 + 4) != uVar4) break;
      bVar1 = (*(byte **)(iVar5 + 4))[1];
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      enableIRQinterrupts((uVar6 & 1) == 1);
    }
  }
  return param_1;
}


