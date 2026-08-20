// 600e7f7a  FUN_600e7f7a  size=288 bytes
// --- callers ---
//   600e809a FUN_600e809a
// --- callees ---
//   600e7c2c FUN_600e7c2c


void FUN_600e7f7a(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = FUN_600e7c2c();
  if (param_5 != 0) {
    param_4 = param_4 * 4;
    piVar4 = (int *)(param_1 + param_4);
    if (param_5 < 0) {
      param_3 = param_3 + param_4 + 0x10;
      do {
        iVar3 = iVar1 + *(int *)(param_3 + -0x10);
        if (*(int *)(param_3 + -0x10) != 0) {
          iVar1 = 1;
        }
        *piVar4 = -iVar3;
        if (param_5 == -1) {
          return;
        }
        iVar3 = iVar1 + *(int *)(param_3 + -0xc);
        if (*(int *)(param_3 + -0xc) != 0) {
          iVar1 = 1;
        }
        piVar4[1] = -iVar3;
        if (param_5 == -2) {
          return;
        }
        iVar3 = iVar1 + *(int *)(param_3 + -8);
        if (*(int *)(param_3 + -8) != 0) {
          iVar1 = 1;
        }
        piVar4[2] = -iVar3;
        if (param_5 == -3) {
          return;
        }
        piVar2 = (int *)(param_3 + -4);
        param_3 = param_3 + 0x10;
        iVar3 = iVar1 + *piVar2;
        if (*piVar2 != 0) {
          iVar1 = 1;
        }
        param_5 = param_5 + 4;
        piVar4[3] = -iVar3;
        piVar4 = piVar4 + 4;
      } while (param_5 != 0);
    }
    else {
      piVar2 = (int *)(param_4 + param_2);
      while (iVar1 != 0) {
        iVar3 = *piVar2 - iVar1;
        if (*piVar2 != 0) {
          iVar1 = 0;
        }
        *piVar4 = iVar3;
        if (param_5 == 1) {
          return;
        }
        iVar3 = piVar2[1] - iVar1;
        if (piVar2[1] != 0) {
          iVar1 = 0;
        }
        piVar4[1] = iVar3;
        if (param_5 == 2) {
          return;
        }
        iVar3 = piVar2[2] - iVar1;
        if (piVar2[2] != 0) {
          iVar1 = 0;
        }
        piVar4[2] = iVar3;
        if (param_5 == 3) {
          return;
        }
        iVar3 = piVar2[3] - iVar1;
        if (piVar2[3] != 0) {
          iVar1 = 0;
        }
        param_5 = param_5 + -4;
        piVar4[3] = iVar3;
        if (param_5 == 0) {
          return;
        }
        piVar2 = piVar2 + 4;
        piVar4 = piVar4 + 4;
      }
      do {
        *piVar4 = *piVar2;
        if (param_5 == 1) {
          return;
        }
        piVar4[1] = piVar2[1];
        if (param_5 == 2) {
          return;
        }
        piVar4[2] = piVar2[2];
        if (param_5 == 3) {
          return;
        }
        param_5 = param_5 + -4;
        piVar4[3] = piVar2[3];
        piVar2 = piVar2 + 4;
        piVar4 = piVar4 + 4;
      } while (param_5 != 0);
    }
  }
  return;
}


