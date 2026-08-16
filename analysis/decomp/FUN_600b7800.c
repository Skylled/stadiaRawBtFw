// 600b7800  FUN_600b7800  size=830 bytes
// --- callers ---
//   600b9e28 FUN_600b9e28
// --- callees ---
//   600b7674 FUN_600b7674
//   600f82ea FUN_600f82ea
//   600b7b48 FUN_600b7b48
//   6006ddd8 FUN_6006ddd8
//   600d9250 FUN_600d9250
//   600b9408 FUN_600b9408
//   600aa438 FUN_600aa438
//   600f82c4 FUN_600f82c4
//   600b8094 FUN_600b8094
//   600f8290 FUN_600f8290
//   600b7c94 FUN_600b7c94
//   600d9246 FUN_600d9246
//   600b7db8 FUN_600b7db8


void FUN_600b7800(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  ushort local_12;
  byte *local_10;
  ushort local_c;
  ushort local_a;
  
  if (*(char *)(param_1 + 0x11f) == '\x03') {
    local_c = 2;
  }
  else {
    local_c = 4;
  }
  if (*(ushort *)(param_2 + 2) < local_c) {
    FUN_6006ddd8(param_2,DAT_600b7a80,0x281);
  }
  else if (*(char *)(param_1 + 0x7e) == '\x04') {
    FUN_600b8094(param_1,param_2);
  }
  else {
    if (*(char *)(param_1 + 0x11f) != '\x03') {
      local_10 = (byte *)((uint)*(ushort *)(param_2 + 2) + (uint)*(ushort *)(param_2 + 4) +
                         param_2 + 6);
      local_12 = (ushort)local_10[1] * 0x100 + (ushort)*local_10;
      local_10 = local_10 + 2;
      *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + -2;
      uVar1 = FUN_600f8290(param_2);
      if (local_12 != uVar1) {
        FUN_6006ddd8(param_2,DAT_600b7a80,0x2cc);
        return;
      }
    }
    local_10 = (byte *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
    local_a = (ushort)local_10[1] * 0x100 + (ushort)*local_10;
    local_10 = local_10 + 2;
    *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + -2;
    *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + 2;
    if (*(char *)(param_1 + 0xba) == '\0') {
      local_a = local_a & 0xff7f;
    }
    else {
      if ((local_a & 0x80) == 0) {
        if (((local_a & 0x10) != 0) && ((local_a & 1) != 0)) {
          if (*(char *)(param_1 + 0xb9) == '\0') {
            if (*(char *)(param_1 + 0xb7) == '\0') {
              FUN_600b7674(param_1,0,0x80);
            }
            else {
              FUN_600b7674(param_1,2,0x80);
            }
          }
          else {
            FUN_600b7674(param_1,3,0x80);
          }
          FUN_600aa438(param_1 + 0x100,3,10);
        }
        FUN_6006ddd8(param_2,DAT_600b7a80,0x2ee);
        return;
      }
      *(undefined1 *)(param_1 + 0xba) = 0;
      if ((local_a & 1) != 0) {
        local_a = local_a & 0xffef;
      }
      if (*(short *)(param_1 + 0xcc) == 0) {
        *(undefined1 *)(param_1 + 0xb4) = 0;
      }
      FUN_600f82c4(param_1);
    }
    iVar2 = FUN_600b7b48(param_1,local_a);
    if (iVar2 == 0) {
      FUN_6006ddd8(param_2,DAT_600b7a80,0x306);
    }
    else {
      if ((local_a & 1) == 0) {
        FUN_600b7db8(param_1,param_2,local_a,0);
      }
      else {
        FUN_600b7c94(param_1,param_2,local_a);
      }
      if ((*(char *)(param_1 + 5) != '\0') && (*(char *)(param_1 + 4) == '\x06')) {
        if ((*(char *)(param_1 + 0xb7) == '\0') &&
           ((*(char *)(param_1 + 0xb9) == '\0' && (*(short *)(param_1 + 0xd8) != 0)))) {
          local_20 = *(undefined4 *)(param_1 + 0xd0);
          uStack_1c = *(undefined4 *)(param_1 + 0xd4);
          uStack_18 = *(undefined4 *)(param_1 + 0xd8);
          FUN_600d9246(param_1 + 0xd0);
          while (iVar2 = FUN_600d9250(&local_20), iVar2 != 0) {
            if ((*(char *)(param_1 + 5) == '\0') || (*(char *)(param_1 + 4) != '\x06')) {
              FUN_6006ddd8(iVar2,DAT_600b7b44,0x32c);
            }
            else {
              local_10 = (byte *)((uint)*(ushort *)(iVar2 + 4) + iVar2 + 6);
              local_a = (ushort)local_10[1] * 0x100 + (ushort)*local_10;
              local_10 = local_10 + 2;
              FUN_600b7db8(param_1,iVar2,local_a,1);
            }
            if (*(char *)(param_1 + 0xbb) != '\0') {
              *(undefined1 *)(param_1 + 0xbb) = 0;
              *(undefined1 *)(param_1 + 0xb8) = 1;
              FUN_600b7674(param_1,1,0);
            }
          }
          if ((((*(char *)(param_1 + 0xb7) == '\0') && (*(char *)(param_1 + 0xb8) == '\0')) &&
              (*(char *)(param_1 + 0xb9) == '\0')) &&
             (*(char *)(param_1 + 0xb2) != *(char *)(param_1 + 0xb3))) {
            FUN_600b7674(param_1,0,0);
          }
        }
        if (((*(short *)(param_1 + 0xe4) != 0) || (*(short *)(param_1 + 0x138) != 0)) &&
           ((*(char *)(param_1 + 0xba) == '\0' && (iVar2 = FUN_600f82ea(param_1), iVar2 == 0)))) {
          FUN_600b9408(*(undefined4 *)(param_1 + 300),0,0);
        }
      }
    }
  }
  return;
}


