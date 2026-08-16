// 600b7db8  FUN_600b7db8  size=725 bytes
// --- callers ---
//   600b7800 FUN_600b7800
// --- callees ---
//   600b742c FUN_600b742c
//   600aa4c4 FUN_600aa4c4
//   6006e084 FUN_6006e084
//   600f82ea FUN_600f82ea
//   6006ddd8 FUN_6006ddd8
//   600b842c FUN_600b842c
//   600b7674 FUN_600b7674
//   600f9db4 FUN_600f9db4
//   600b81ec FUN_600b81ec
//   6006dfa4 FUN_6006dfa4
//   600aa438 FUN_600aa438


void FUN_600b7db8(int param_1,int param_2,ushort param_3,char param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined1 local_23;
  undefined4 local_20;
  
  if (((param_3 & 0x80) == 0) || (iVar3 = FUN_600b842c(param_1,0xff), iVar3 != 0)) {
    bVar1 = (byte)((int)(uint)param_3 >> 1) & 0x3f;
    if ((bVar1 == *(byte *)(param_1 + 0xb2)) || (*(char *)(param_1 + 0xb7) == '\0')) {
      iVar3 = FUN_6006e084(*(undefined1 *)(param_1 + 0xa9));
      if (iVar3 == 0) {
        FUN_6006ddd8(param_2,DAT_600b8090,0x46d);
      }
      else if (bVar1 == *(byte *)(param_1 + 0xb2)) {
        *(undefined1 *)(param_1 + 0xb9) = 0;
        *(undefined1 *)(param_1 + 0xb8) = *(undefined1 *)(param_1 + 0xb9);
        *(byte *)(param_1 + 0xb2) = bVar1 + 1 & 0x3f;
        iVar3 = FUN_600b81ec(param_1,param_2,param_3);
        if (iVar3 == 0) {
          FUN_600f9db4(param_1);
        }
        else {
          bVar1 = *(char *)(param_1 + 0xb2) - *(char *)(param_1 + 0xb3) & 0x3f;
          local_23 = param_4;
          if ((bVar1 < *(byte *)(param_1 + 0xb5)) && (*(char *)(param_1 + 0xb7) == '\0')) {
            local_23 = '\x01';
          }
          if (((bVar1 != 0) && (*(char *)(param_1 + 5) != '\0')) &&
             (*(char *)(param_1 + 4) == '\x06')) {
            if (local_23 == '\0') {
              if (((*(short *)(param_1 + 0x138) == 0) || (iVar3 = FUN_600f82ea(param_1), iVar3 != 0)
                  ) && (*(short *)(param_1 + 0xd8) == 0)) {
                if (*(char *)(param_1 + 0xb7) == '\0') {
                  FUN_600b7674(param_1,0,0);
                }
                else {
                  FUN_600b7674(param_1,2,0);
                }
              }
            }
            else if (*(char *)(param_1 + 0xfe) == '\0') {
              FUN_600aa438(param_1 + 0xe8,0x2a,2);
            }
          }
        }
      }
      else {
        bVar2 = bVar1 - *(char *)(param_1 + 0xb2) & 0x3f;
        if (bVar2 < *(byte *)(param_1 + 0x33)) {
          if (*(char *)(param_1 + 0xb9) == '\0') {
            if (*(char *)(param_1 + 0xb8) == '\0') {
              if (bVar2 < 2) {
                *(ushort *)(param_2 + 6) = (ushort)bVar1;
                FUN_6006dfa4(param_1 + 0xd0,param_2);
                *(undefined1 *)(param_1 + 0xb9) = 1;
                FUN_600b7674(param_1,3,0);
              }
              else {
                FUN_6006ddd8(param_2,DAT_600b8090,0x4bb);
                *(undefined1 *)(param_1 + 0xb8) = 1;
                FUN_600b7674(param_1,1,0);
              }
              FUN_600aa4c4(param_1 + 0xe8);
            }
            else {
              FUN_6006ddd8(param_2,DAT_600b8090,0x4b1);
            }
          }
          else if ((bVar1 == ((char)*(undefined2 *)(*(int *)(param_1 + 0xd4) + 6) + 1U & 0x3f)) &&
                  (*(ushort *)(param_1 + 0xd8) < (ushort)*(byte *)(param_1 + 0x33))) {
            local_20 = param_2;
            if (*(char *)(param_1 + 0xab) != '\x02') {
              *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -2;
              *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 2;
              iVar3 = FUN_600b742c(param_2,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2)
                                   ,*(undefined1 *)(param_1 + 0xab));
              local_20 = param_2;
              if (iVar3 != 0) {
                FUN_6006ddd8(param_2,DAT_600b8090,0x496);
                local_20 = iVar3;
              }
              *(short *)(local_20 + 4) = *(short *)(local_20 + 4) + 2;
              *(short *)(local_20 + 2) = *(short *)(local_20 + 2) + -2;
            }
            *(ushort *)(local_20 + 6) = (ushort)bVar1;
            FUN_6006dfa4(param_1 + 0xd0,local_20);
          }
          else {
            *(undefined1 *)(param_1 + 0xbb) = 1;
            FUN_6006ddd8(param_2,DAT_600b8090,0x4a8);
          }
        }
        else {
          FUN_6006ddd8(param_2,DAT_600b8090,0x47b);
        }
      }
    }
    else {
      FUN_600b7674(param_1,2,0);
      FUN_6006ddd8(param_2,DAT_600b8090,0x462);
    }
  }
  else {
    FUN_6006ddd8(param_2,DAT_600b8090,0x450);
  }
  return;
}


