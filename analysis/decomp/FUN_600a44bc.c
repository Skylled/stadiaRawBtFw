// 600a44bc  FUN_600a44bc  size=850 bytes
// --- callers ---
//   600f1ad4 FUN_600f1ad4
//   600f1b34 FUN_600f1b34
// --- callees ---
//   600f1800 FUN_600f1800
//   600b33a4 FUN_600b33a4
//   600f1746 FUN_600f1746
//   60098ec8 FUN_60098ec8
//   600f8c0a FUN_600f8c0a
//   600a42d0 FUN_600a42d0
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f1ecc FUN_600f1ecc
//   600a5964 FUN_600a5964
//   600f0f48 FUN_600f0f48
//   600c0578 FUN_600c0578
//   600a8108 FUN_600a8108
//   600a1560 FUN_600a1560


char FUN_600a44bc(undefined4 param_1,char param_2,byte param_3,int param_4,int param_5)

{
  char cVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  uint local_10;
  byte local_9;
  
  psVar2 = (short *)FUN_60098ec8(param_1,param_2);
  if (*(char *)(DAT_600a47a8 + 0x118c) == '\0') {
    iVar3 = FUN_600f1746(param_1);
    if (iVar3 == 0) {
      cVar1 = '\x03';
    }
    else if ((((*(short *)(iVar3 + 0xc) == -1) || (param_2 != '\x01')) ||
             ((*(ushort *)(iVar3 + 0x2a) & 2) == 0)) &&
            (((*(short *)(iVar3 + 0x5e) == -1 || (param_2 != '\x02')) ||
             ((*(ushort *)(iVar3 + 0x2a) & 0x200) == 0)))) {
      iVar4 = FUN_600a1560(param_1,0);
      if (iVar4 == 0) {
        if (((param_4 != 0) && (param_3 < 0x11)) && (param_3 != 0)) {
          *(byte *)(DAT_600a47a8 + 0x117b) = param_3;
          thunk_EXT_FUN_0000b572(DAT_600a47ac,param_4,0x10);
        }
        thunk_EXT_FUN_0000b572(DAT_600a47b0,param_1,6);
        *(undefined1 *)(DAT_600a47a8 + 0x118d) = 1;
        *(undefined2 *)(iVar3 + 0x54) = 0x10;
        *(undefined1 *)(iVar3 + 0x51) = 1;
        if (param_5 != 0) {
          for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
            *(undefined4 *)(local_10 * 4 + iVar3 + 4) = *(undefined4 *)(param_5 + local_10 * 4);
          }
        }
        if (param_2 == '\x02') {
          FUN_600f0f48(iVar3,param_1);
          *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) & 0xc9ff;
          iVar4 = FUN_600c0578(param_1);
          if (iVar4 == 0x15) {
            *(byte *)(DAT_600a47a8 + 0x118d) = *(byte *)(DAT_600a47a8 + 0x118d) | 0x80;
            *(undefined1 *)(iVar3 + 0x50) = 1;
            FUN_600a8108(9);
            cVar1 = '\x01';
          }
          else {
            *(undefined1 *)(DAT_600a47a8 + 0x118d) = 0;
            cVar1 = '\x03';
          }
        }
        else {
          *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) & 0xff89;
          if (((((*(byte *)(DAT_600a47a8 + 0x819) & 8) == 0) &&
               ((*(byte *)(iVar3 + 0x17) & 0x1f) == 5)) && ((*(byte *)(iVar3 + 0x18) & 0x40) != 0))
             && (*(char *)(DAT_600a47a8 + 0xf9) != '\x01')) {
            *(undefined1 *)(DAT_600a47a8 + 0x1179) = 1;
            FUN_600b33a4(1);
          }
          for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
          }
          *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) & 0xfff7;
          if ((psVar2 == (short *)0x0) || (*psVar2 == -1)) {
            if (((*(byte *)(DAT_600a47a8 + 0x819) & 8) == 0) || (*(char *)(iVar3 + 0x59) == '\x10'))
            {
              FUN_600a8108(3);
              if (*(char *)(DAT_600a47a8 + 0x117b) == '\0') {
                if ((*(int *)(DAT_600a47a8 + 0x111c) != 0) &&
                   ((*(byte *)(DAT_600a47a8 + 0x118d) & 8) == 0)) {
                  *(byte *)(DAT_600a47a8 + 0x118d) = *(byte *)(DAT_600a47a8 + 0x118d) | 8;
                  if (psVar2 == (short *)0x0) {
                    *(byte *)(DAT_600a47a8 + 0x118d) = *(byte *)(DAT_600a47a8 + 0x118d) | 0x10;
                  }
                  (**(code **)(DAT_600a47a8 + 0x111c))(param_1,iVar3 + 0x16,iVar3 + 0x2c);
                }
              }
              else {
                FUN_600a42d0(param_1,0,param_3,param_4,param_5);
              }
              cVar1 = '\x01';
            }
            else if ((*(byte *)(DAT_600a481c + 0x1174) < 4) ||
                    ((*(byte *)(iVar3 + 0x59) & 0x11) != 0)) {
              cVar1 = FUN_600a5964(iVar3);
              if (cVar1 != '\x01') {
                FUN_600a8108(0);
              }
            }
            else {
              if ((*(byte *)(iVar3 + 0x59) & 0x40) == 0) {
                FUN_600a8108(1);
                FUN_600f1800(param_1,0,1);
              }
              else {
                FUN_600a8108(2);
              }
              cVar1 = '\x01';
            }
          }
          else {
            iVar3 = FUN_600f1ecc(iVar3);
            if (iVar3 == 0) {
              cVar1 = '\x03';
            }
            else {
              FUN_600a8108(2);
              FUN_600f8c0a(param_1,1);
              cVar1 = '\x01';
            }
          }
        }
      }
      else {
        cVar1 = '\x03';
      }
    }
    else {
      cVar1 = '\0';
    }
  }
  else {
    cVar1 = '\x06';
  }
  return cVar1;
}


