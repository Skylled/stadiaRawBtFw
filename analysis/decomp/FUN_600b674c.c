// 600b674c  FUN_600b674c  size=310 bytes
// --- callers ---
//   600b5e00 FUN_600b5e00
// --- callees ---
//   6006ddd8 FUN_6006ddd8
//   600f9906 FUN_600f9906
//   600f8de8 FUN_600f8de8
//   600bc00c FUN_600bc00c
//   600aa340 FUN_600aa340


void FUN_600b674c(undefined2 *param_1,undefined2 param_2,int param_3)

{
  undefined2 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 0xaa) + 0x1c);
  uVar1 = *param_1;
  switch(param_2) {
  case 3:
    FUN_600bc00c(param_1);
    (*pcVar2)(uVar1,0);
    break;
  case 0x13:
    FUN_600aa340(param_1 + 0x9e,3,0x3c);
    (**(code **)(*(int *)(param_1 + 0xaa) + 8))
              (*(int *)(param_1 + 0x96) + 4,*param_1,*(undefined2 *)(*(int *)(param_1 + 0xaa) + 2),
               *(undefined1 *)(param_1 + 4));
    break;
  case 0x14:
  case 0x1e:
    FUN_6006ddd8(param_3,DAT_600b68fc,0x29a);
    break;
  case 0x16:
    if ((param_3 == 0) || (*(short *)(param_3 + 10) == 0)) {
      FUN_600f8de8(param_1,0,0);
      *(undefined1 *)(param_1 + 2) = 5;
      FUN_600aa340(param_1 + 0x9e,3,0x1e);
    }
    else {
      FUN_600f8de8(param_1,*(undefined2 *)(param_3 + 10),*(undefined2 *)(param_3 + 0xc));
      FUN_600aa340(param_1 + 0x9e,3,0x78);
    }
    break;
  case 0x17:
    FUN_600f8de8(param_1,*(undefined2 *)(param_3 + 10),*(undefined2 *)(param_3 + 0xc));
    FUN_600bc00c(param_1);
    break;
  case 0x1b:
    FUN_600f9906(param_1);
    *(undefined1 *)(param_1 + 2) = 7;
    FUN_600aa340(param_1 + 0x9e,3,10);
    break;
  case 0x20:
    FUN_600f8de8(param_1,2,0);
    FUN_600bc00c(param_1);
    (*pcVar2)(uVar1,0);
  }
  return;
}


