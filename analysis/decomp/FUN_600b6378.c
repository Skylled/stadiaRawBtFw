// 600b6378  FUN_600b6378  size=260 bytes
// --- callers ---
//   600b5e00 FUN_600b5e00
// --- callees ---
//   600a4c5c FUN_600a4c5c
//   600bc00c FUN_600bc00c
//   600f99ee FUN_600f99ee
//   600aa340 FUN_600aa340
//   600b218c FUN_600b218c
//   600f8de8 FUN_600f8de8
//   6006ddd8 FUN_6006ddd8
//   600a58f0 FUN_600a58f0


void FUN_600b6378(undefined2 *param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  
  switch(param_2) {
  case 3:
    FUN_600a58f0(*(int *)(param_1 + 0x96) + 4);
    FUN_600bc00c(param_1);
    break;
  case 7:
    *(undefined1 *)(param_1 + 2) = 4;
    if (*(char *)(*(int *)(param_1 + 0x96) + 0xa3) == '\0') {
      FUN_600aa340(param_1 + 0x9e,3,0x3c);
      (**(code **)(*(int *)(param_1 + 0xaa) + 8))
                (*(int *)(param_1 + 0x96) + 4,*param_1,*(undefined2 *)(*(int *)(param_1 + 0xaa) + 2)
                 ,*(undefined1 *)(param_1 + 4));
    }
    else {
      FUN_600f8de8(param_1,1,0);
    }
    break;
  case 8:
    if (*(char *)(param_3 + 6) == '\x0f') {
      FUN_600aa340(param_1 + 0x9e,3,2);
    }
    else {
      FUN_600f8de8(param_1,3,0);
      FUN_600bc00c(param_1);
    }
    break;
  case 0x11:
    FUN_600f99ee(*(undefined4 *)(param_1 + 0x96),*(undefined1 *)(param_1 + 4),*param_1,param_1[1]);
    FUN_600a58f0(*(int *)(param_1 + 0x96) + 4);
    FUN_600bc00c(param_1);
    break;
  case 0x14:
  case 0x1e:
    FUN_6006ddd8(param_3,DAT_600b6548,0x1c9);
    break;
  case 0x1b:
    FUN_600bc00c(param_1);
    break;
  case 0x20:
    iVar1 = FUN_600b218c(*(undefined2 *)(*(int *)(param_1 + 0x96) + 2),5);
    if (iVar1 == 0) {
      FUN_600aa340(param_1 + 0x9e,3,1);
    }
    break;
  case 0x21:
    FUN_600a4c5c(*(int *)(param_1 + 0x96) + 4,*(undefined2 *)(*(int *)(param_1 + 0xaa) + 2),
                 *(undefined2 *)(*(int *)(param_1 + 0x96) + 2),0,DAT_600b654c,param_1);
  }
  return;
}


