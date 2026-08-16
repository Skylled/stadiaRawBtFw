// 600b6900  FUN_600b6900  size=940 bytes
// --- callers ---
//   600b5e00 FUN_600b5e00
// --- callees ---
//   600bc2a0 FUN_600bc2a0
//   600f9db4 FUN_600f9db4
//   600f9462 FUN_600f9462
//   600fa018 FUN_600fa018
//   6006ddd8 FUN_6006ddd8
//   600b731c FUN_600b731c
//   600f8f7a FUN_600f8f7a
//   600b9408 FUN_600b9408
//   600bc00c FUN_600bc00c
//   600f85a8 FUN_600f85a8
//   600f8664 FUN_600f8664
//   600aa340 FUN_600aa340
//   600f9df0 FUN_600f9df0
//   600aa3cc FUN_600aa3cc
//   600b720c FUN_600b720c
//   600f9906 FUN_600f9906
//   600bc1f8 FUN_600bc1f8
//   600b90d8 FUN_600b90d8


void FUN_600b6900(ushort *param_1,undefined2 param_2,short *param_3)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  
  pcVar4 = *(code **)(*(int *)(param_1 + 0xaa) + 0x1c);
  uVar1 = *param_1;
  switch(param_2) {
  case 3:
    FUN_600bc00c(param_1);
    (*pcVar4)(uVar1,0);
    break;
  case 0xe:
    cVar2 = FUN_600f9df0(param_1,param_3);
    if (cVar2 == '\x01') {
      (**(code **)(*(int *)(param_1 + 0xaa) + 0x14))(*param_1,param_3);
    }
    else if (cVar2 == '\x02') {
      FUN_600f9db4(param_1);
    }
    else {
      FUN_600f9462(param_1,param_3);
    }
    break;
  case 0xf:
    FUN_600bc1f8(param_1,param_3);
    if ((*param_3 != 4) && (*(byte *)(param_1 + 3) = (byte)param_1[3] | 2, (param_1[3] & 1) != 0)) {
      if ((char)param_1[0x19] != (char)param_1[0x3f]) {
        FUN_600f9906(param_1);
        FUN_600bc00c(param_1);
        (*pcVar4)(uVar1,0);
        return;
      }
      *(byte *)(param_1 + 3) = (byte)param_1[3] | 4;
      *(undefined1 *)(param_1 + 2) = 6;
      FUN_600b90d8();
      FUN_600aa3cc(param_1 + 0x9e);
      if ((char)param_1[0x5d] != '\0') {
        FUN_600b731c(param_1);
      }
      if (((char)param_1[0x19] == '\x03') && ((param_1[0x1c] == 0 || (param_1[0x1b] != 0)))) {
        FUN_600f85a8(param_1);
      }
      if (param_1[0x9c] != 0) {
        FUN_600b9408(*(undefined4 *)(param_1 + 0x96),0,0);
      }
    }
    (**(code **)(*(int *)(param_1 + 0xaa) + 0x18))(*param_1,param_3);
    break;
  case 0x10:
    FUN_600aa3cc(param_1 + 0x9e);
    iVar3 = FUN_600f8664(param_1,param_3);
    if (iVar3 == 0) {
      (**(code **)(*(int *)(param_1 + 0xaa) + 0x18))(*param_1,param_3);
    }
    break;
  case 0x11:
    FUN_600aa340(param_1 + 0x9e,3,10);
    *(undefined1 *)(param_1 + 2) = 8;
    (**(code **)(*(int *)(param_1 + 0xaa) + 0x1c))(*param_1,1);
    break;
  case 0x14:
    if (*param_1 < 0x40) {
      uVar1 = *param_1 - 4;
      if ((uVar1 < 4) && (*(int *)((uint)uVar1 * 0x1c + DAT_600b6d28 + 0xed4) != 0)) {
        (**(code **)((uint)uVar1 * 0x1c + DAT_600b6d28 + 0xed4))
                  (*(int *)(param_1 + 0x96) + 4,param_3);
      }
      else {
        FUN_6006ddd8(param_3,DAT_600b6d2c,0x394);
      }
    }
    else {
      (**(code **)(*(int *)(param_1 + 0xaa) + 0x28))(*param_1,param_3);
    }
    break;
  case 0x18:
    FUN_600bc2a0(param_1,param_3);
    FUN_600f8f7a(param_1,param_3);
    FUN_600aa340(param_1 + 0x9e,3,0x1e);
    break;
  case 0x19:
    FUN_600fa018(param_1,param_3);
    if (((param_3[0x22] & 1U) == 0) && (*param_3 != 4)) {
      *(undefined1 *)(param_1 + 0x2d) = 0;
      *(undefined1 *)(param_1 + 0x3c) = 0;
      *(undefined1 *)(param_1 + 0x2f) = 0;
      *(byte *)(param_1 + 3) = (byte)param_1[3] | 1;
      if ((param_1[3] & 2) != 0) {
        if ((char)param_1[0x19] != (char)param_1[0x3f]) {
          FUN_600f9906(param_1);
          FUN_600bc00c(param_1);
          (*pcVar4)(uVar1,0);
          return;
        }
        *(byte *)(param_1 + 3) = (byte)param_1[3] | 4;
        *(undefined1 *)(param_1 + 2) = 6;
        FUN_600b90d8();
        FUN_600aa3cc(param_1 + 0x9e);
      }
      FUN_600f9462(param_1,param_3);
      if ((char)param_1[0x5d] != '\0') {
        FUN_600b731c(param_1);
      }
      if (((char)param_1[2] == '\x06') && (param_1[0x9c] != 0)) {
        FUN_600b9408(*(undefined4 *)(param_1 + 0x96),0,0);
      }
    }
    else {
      FUN_600f9462(param_1,param_3);
    }
    break;
  case 0x1a:
    FUN_600f9462(param_1,param_3);
    FUN_600aa340(param_1 + 0x9e,3,0x1e);
    break;
  case 0x1b:
    FUN_600f9906(param_1);
    *(undefined1 *)(param_1 + 2) = 7;
    FUN_600aa340(param_1 + 0x9e,3,10);
    break;
  case 0x1e:
    if ((param_1[3] & 2) == 0) {
      FUN_6006ddd8(param_3,DAT_600b6d2c,0x3a5);
    }
    else {
      FUN_600b720c(param_1,param_3);
    }
    break;
  case 0x20:
    FUN_600f9906(param_1);
    FUN_600bc00c(param_1);
    (*pcVar4)(uVar1,0);
  }
  return;
}


