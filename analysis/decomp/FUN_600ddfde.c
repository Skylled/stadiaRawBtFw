// 600ddfde  FUN_600ddfde  size=194 bytes
// --- callers ---
//   600dd83c FUN_600dd83c
// --- callees ---
//   6007dbbc FUN_6007dbbc
//   600de85a FUN_600de85a


int * FUN_600ddfde(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint in_fpscr;
  float fVar10;
  
  uVar3 = *(undefined4 *)(param_2 + 0xa0);
  param_1[1] = *(int *)(param_2 + 0x60);
  *param_1 = param_2;
  param_1[0xc6] = 0x4e800000;
  param_1[200] = 0;
  *(undefined1 *)(param_1 + 199) = 1;
  FUN_600de85a(param_1 + 0xc9,0x41,uVar3,1,param_4);
  FUN_6007dbbc(param_1 + 0xd0,*param_1 + 0xc4);
  FUN_6007dbbc(param_1 + 0x195,*param_1 + 0xa4);
  iVar5 = *param_1;
  fVar10 = (float)VectorSignedToFloat(param_1[1],(byte)(in_fpscr >> 0x16) & 3);
  iVar9 = *(int *)(iVar5 + 0xec);
  uVar1 = *(undefined1 *)(iVar5 + 0xf8);
  iVar8 = *(int *)(iVar5 + 0xf0);
  iVar2 = *(int *)(iVar5 + 0xf4);
  iVar6 = *(int *)(iVar5 + 0xe4);
  param_1[0x25b] = *(int *)(iVar5 + 0xe8);
  param_1[0x25a] = iVar6;
  param_1[0x25c] = iVar9;
  piVar4 = param_1 + 3;
  param_1[0x25d] = iVar8;
  param_1[0x25e] = iVar2;
  *(undefined1 *)(param_1 + 0x25f) = uVar1;
  *(undefined1 *)((int)param_1 + 0x97d) = 0;
  param_1[0x260] = 0;
  param_1[0x261] = 0;
  param_1[2] = (int)(1.0 / fVar10);
  do {
    *piVar4 = 0x3f800000;
    piVar4 = piVar4 + 1;
  } while (param_1 + 0x44 != piVar4);
  piVar4 = param_1 + 0x44;
  do {
    piVar7 = piVar4 + 1;
    *piVar4 = 0;
    piVar4 = piVar7;
  } while (piVar7 != param_1 + 0x85);
  do {
    piVar4 = piVar7 + 1;
    *piVar7 = 0;
    piVar7 = piVar4;
  } while (piVar4 != param_1 + 0xc6);
  return param_1;
}


