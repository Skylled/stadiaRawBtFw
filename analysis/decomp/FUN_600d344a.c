// 600d344a  FUN_600d344a  size=112 bytes
// --- callers ---
// --- callees ---


int * FUN_600d344a(int *param_1,int param_2,uint param_3)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  
  *param_1 = param_2;
  *(char *)(param_1 + 1) = (char)param_3;
  bVar5 = false;
  if (param_2 != 0) {
    uVar7 = 0;
    bVar5 = (bool)isCurrentModePrivileged();
    if (bVar5) {
      uVar7 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    bVar5 = false;
    uVar4 = 0;
LAB_600d3468:
    if ((bVar5) && (param_3 == uVar4)) {
      bVar5 = false;
      goto LAB_600d34a4;
    }
    uVar3 = param_3;
    do {
      uVar6 = uVar3;
      if (**(byte **)(param_2 + 4) != uVar6) break;
      uVar3 = (uint)(*(byte **)(param_2 + 4))[1];
    } while (uVar3 != uVar4);
    sVar1 = *(short *)(param_2 + uVar6 * 2);
    if (sVar1 != -1) {
      *(short *)(param_2 + uVar6 * 2) = sVar1 + 1;
      if (sVar1 == 0) {
        (**(code **)(param_2 + 8))(uVar6);
      }
      uVar4 = uVar6;
      if (!bVar5) {
        bVar5 = true;
      }
      goto LAB_600d3468;
    }
    bVar5 = true;
LAB_600d34a4:
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      enableIRQinterrupts((uVar7 & 1) == 1);
    }
    bVar5 = !bVar5;
  }
  *(bool *)((int)param_1 + 5) = bVar5;
  return param_1;
}


