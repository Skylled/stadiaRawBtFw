// 6005f22c  FUN_6005f22c  size=100 bytes
// --- callers ---
//   6006fd14 FUN_6006fd14
// --- callees ---


bool FUN_6005f22c(uint param_1)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar4 = DAT_6005f290;
  uVar8 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar8 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  bVar2 = false;
  uVar6 = 0;
  do {
    if ((bVar2) && (param_1 == uVar6)) {
      bVar2 = false;
      goto LAB_6005f27e;
    }
    uVar5 = param_1;
    do {
      uVar7 = uVar5;
      if (**(byte **)(iVar4 + 4) != uVar7) break;
      uVar5 = (uint)(*(byte **)(iVar4 + 4))[1];
    } while (uVar5 != uVar6);
    sVar1 = *(short *)(iVar4 + uVar7 * 2);
    if (sVar1 == -1) {
      bVar2 = true;
LAB_6005f27e:
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        enableIRQinterrupts((uVar8 & 1) == 1);
      }
      return !bVar2;
    }
    *(short *)(iVar4 + uVar7 * 2) = sVar1 + 1;
    if (sVar1 == 0) {
      (**(code **)(iVar4 + 8))(uVar7);
    }
    uVar6 = uVar7;
    if (!bVar2) {
      bVar2 = true;
    }
  } while( true );
}


