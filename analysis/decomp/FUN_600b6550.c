// 600b6550  FUN_600b6550  size=384 bytes
// --- callers ---
//   600b5e00 FUN_600b5e00
// --- callees ---
//   600bc00c FUN_600bc00c
//   600aa340 FUN_600aa340
//   600f8d34 FUN_600f8d34
//   600f9906 FUN_600f9906
//   6006ddd8 FUN_6006ddd8
//   600f83f2 FUN_600f83f2


void FUN_600b6550(undefined2 *param_1,undefined2 param_2,char *param_3)

{
  undefined2 uVar1;
  int iVar2;
  code *pcVar3;
  code *pcVar4;
  
  pcVar3 = *(code **)(*(int *)(param_1 + 0xaa) + 0x1c);
  pcVar4 = *(code **)(*(int *)(param_1 + 0xaa) + 0xc);
  uVar1 = *param_1;
  switch(param_2) {
  case 3:
    *(undefined1 *)(param_1 + 2) = 0;
    if ((((*(byte *)((int)param_1 + 9) & 1) != 0) || (param_3 == (char *)0x0)) ||
       (*param_3 != '\x13')) {
      FUN_600bc00c(param_1);
      (*pcVar3)(uVar1,0);
    }
    *(byte *)((int)param_1 + 9) = *(byte *)((int)param_1 + 9) | 1;
    break;
  case 0xb:
    param_1[1] = *(undefined2 *)(param_3 + 0xe);
    *(undefined1 *)(param_1 + 2) = 5;
    FUN_600aa340(param_1 + 0x9e,3,0x1e);
    (*pcVar4)(uVar1,0);
    break;
  case 0xc:
    param_1[1] = *(undefined2 *)(param_3 + 0xe);
    FUN_600aa340(param_1 + 0x9e,3,0x78);
    if (*(int *)(*(int *)(param_1 + 0xaa) + 0x10) != 0) {
      (**(code **)(*(int *)(param_1 + 0xaa) + 0x10))(*param_1);
    }
    break;
  case 0xd:
    FUN_600bc00c(param_1);
    (*pcVar4)(uVar1,*(undefined2 *)(param_3 + 10));
    break;
  case 0x13:
    iVar2 = FUN_600f83f2(param_1);
    if (iVar2 == 0) {
      FUN_600bc00c(param_1);
      (*pcVar4)(uVar1,0xff);
    }
    else {
      FUN_600aa340(param_1 + 0x9e,3,0x3c);
      FUN_600f8d34(param_1);
    }
    break;
  case 0x14:
  case 0x1e:
    FUN_6006ddd8(param_3,DAT_600b6748,0x246);
    break;
  case 0x1b:
    if (param_1[1] == 0) {
      FUN_600bc00c(param_1);
    }
    else {
      FUN_600f9906(param_1);
      *(undefined1 *)(param_1 + 2) = 7;
      FUN_600aa340(param_1 + 0x9e,3,10);
    }
    break;
  case 0x20:
    FUN_600bc00c(param_1);
    (*pcVar4)(uVar1,0xeeee);
  }
  return;
}


