// 600bc00c  FUN_600bc00c  size=322 bytes
// --- callers ---
//   600f9db4 FUN_600f9db4
//   600b61c4 FUN_600b61c4
//   600b542c FUN_600b542c
//   600bcae8 FUN_600bcae8
//   600b6d30 FUN_600b6d30
//   600b8ba4 FUN_600b8ba4
//   600bc9e4 FUN_600bc9e4
//   600b6fcc FUN_600b6fcc
//   600bb534 FUN_600bb534
//   600b70f4 FUN_600b70f4
//   600b5ec8 FUN_600b5ec8
//   600b674c FUN_600b674c
//   600b6378 FUN_600b6378
//   600b6900 FUN_600b6900
//   600b6550 FUN_600b6550
// --- callees ---
//   600f19d2 FUN_600f19d2
//   600b7374 FUN_600b7374
//   600d9250 FUN_600d9250
//   600a4270 FUN_600a4270
//   6006ddd8 FUN_6006ddd8
//   600aa3cc FUN_600aa3cc
//   600f9c4e FUN_600f9c4e
//   600b90d8 FUN_600b90d8
//   600fa0d6 FUN_600fa0d6


void FUN_600bc00c(ushort *param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = *(char **)(param_1 + 0x96);
  iVar3 = *(int *)(param_1 + 0xaa);
  if (*(char *)((int)param_1 + 5) != '\0') {
    if ((iVar3 != 0) && (*(short *)(iVar3 + 2) != *(short *)(iVar3 + 4))) {
      FUN_600a4270(*(undefined2 *)(iVar3 + 2));
    }
    if (pcVar2 != (char *)0x0) {
      FUN_600f19d2(pcVar2 + 4);
    }
    FUN_600aa3cc(param_1 + 0x9e);
    while (*(int *)(param_1 + 0x98) != 0) {
      uVar1 = FUN_600d9250(param_1 + 0x98);
      FUN_6006ddd8(uVar1,DAT_600bc150,0x6bc);
    }
    FUN_600b7374(param_1);
    if ((pcVar2 != (char *)0x0) && (0x3f < *param_1)) {
      FUN_600f9c4e(param_1);
      param_1[0x96] = 0;
      param_1[0x97] = 0;
    }
    if (*(int *)(DAT_600bc154 + 0xe94) == 0) {
      *(ushort **)(DAT_600bc154 + 0xe94) = param_1;
      *(ushort **)(DAT_600bc154 + 0xe98) = param_1;
      param_1[0x92] = 0;
      param_1[0x93] = 0;
      param_1[0x94] = 0;
      param_1[0x95] = 0;
    }
    else {
      param_1[0x92] = 0;
      param_1[0x93] = 0;
      *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(DAT_600bc154 + 0xe98);
      *(ushort **)(*(int *)(DAT_600bc154 + 0xe98) + 0x124) = param_1;
      *(ushort **)(DAT_600bc154 + 0xe98) = param_1;
    }
    *(undefined1 *)((int)param_1 + 5) = 0;
    if (((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) &&
       ((pcVar2[1] == '\x04' || ((pcVar2[1] == '\x03' && (pcVar2[0x32] == '\x02')))))) {
      if (*(int *)(pcVar2 + 0x5c) == 0) {
        FUN_600fa0d6(pcVar2);
      }
      else {
        FUN_600b90d8();
      }
    }
  }
  return;
}


