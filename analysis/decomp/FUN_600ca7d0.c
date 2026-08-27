// 600ca7d0  FUN_600ca7d0  size=110 bytes
// --- callers ---
//   601009b2 FUN_601009b2
// --- callees ---
//   600ca350 tasks__600ca350


void FUN_600ca7d0(int param_1,int *param_2,int param_3,int param_4)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    param_1 = *DAT_600ca840;
  }
  *param_2 = param_1;
  param_2[1] = param_1 + 0x34;
  param_2[4] = *(int *)(param_1 + 0x2c);
  param_2[7] = *(int *)(param_1 + 0x30);
  param_2[2] = *(int *)(param_1 + 0x48);
  param_2[5] = *(int *)(param_1 + 0x50);
  param_2[6] = *(int *)(param_1 + 0x60);
  if (param_4 == 5) {
    uVar2 = tasks__600ca350(param_1);
    *(undefined1 *)(param_2 + 3) = uVar2;
  }
  else {
    if (*DAT_600ca840 == param_1) {
      uVar2 = 0;
    }
    else {
      *(char *)(param_2 + 3) = (char)param_4;
      if ((param_4 != 3) || (*(int *)(param_1 + 0x28) == 0)) goto LAB_600ca80a;
      uVar2 = 2;
    }
    *(undefined1 *)(param_2 + 3) = uVar2;
  }
LAB_600ca80a:
  if (param_3 == 0) {
    *(undefined2 *)(param_2 + 8) = 0;
  }
  else {
    pcVar3 = *(char **)(param_1 + 0x30);
    do {
      uVar4 = (int)pcVar3 - (int)*(char **)(param_1 + 0x30);
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 == -0x5b);
    *(short *)(param_2 + 8) = (short)(uVar4 >> 2);
  }
  return;
}


