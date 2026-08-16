// 600b61c4  FUN_600b61c4  size=288 bytes
// --- callers ---
//   600b5e00 FUN_600b5e00
// --- callees ---
//   600a4c5c FUN_600a4c5c
//   600bc00c FUN_600bc00c
//   600aa340 FUN_600aa340
//   600f8d34 FUN_600f8d34
//   6006ddd8 FUN_6006ddd8
//   600f83f2 FUN_600f83f2
//   600a58f0 FUN_600a58f0


void FUN_600b61c4(undefined2 *param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  code *pcVar3;
  code *pcVar4;
  
  pcVar3 = *(code **)(*(int *)(param_1 + 0xaa) + 0x1c);
  pcVar4 = *(code **)(*(int *)(param_1 + 0xaa) + 0xc);
  uVar1 = *param_1;
  switch(param_2) {
  case 0:
  case 0x21:
    FUN_600a4c5c(*(int *)(param_1 + 0x96) + 4,*(undefined2 *)(*(int *)(param_1 + 0xaa) + 2),
                 *(undefined2 *)(*(int *)(param_1 + 0x96) + 2),1,DAT_600b6370,param_1);
    break;
  case 3:
    FUN_600bc00c(param_1);
    (*pcVar3)(uVar1,0);
    break;
  case 7:
    *(undefined1 *)(param_1 + 2) = 3;
    if (*(char *)(*(int *)(param_1 + 0x96) + 0xa3) == '\0') {
      iVar2 = FUN_600f83f2(param_1);
      if (iVar2 == 0) {
        FUN_600bc00c(param_1);
        (*pcVar4)(uVar1,0xff);
      }
      else {
        FUN_600aa340(param_1 + 0x9e,3,0x3c);
        FUN_600f8d34(param_1);
      }
    }
    break;
  case 8:
    if ((param_1 == *(undefined2 **)(*(int *)(param_1 + 0x96) + 0x5c)) &&
       (param_1 == *(undefined2 **)(*(int *)(param_1 + 0x96) + 0x60))) {
      *(undefined2 *)(*(int *)(param_1 + 0x96) + 0x14) = 0;
    }
    FUN_600bc00c(param_1);
    (*pcVar4)(uVar1,5);
    break;
  case 0x14:
  case 0x1e:
    FUN_6006ddd8(param_3,DAT_600b6374,0x169);
    break;
  case 0x1b:
    FUN_600a58f0(*(int *)(param_1 + 0x96) + 4);
    FUN_600bc00c(param_1);
  }
  return;
}


