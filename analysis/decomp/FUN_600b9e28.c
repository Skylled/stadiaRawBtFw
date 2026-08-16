// 600b9e28  FUN_600b9e28  size=902 bytes
// --- callers ---
//   600a9f10 FUN_600a9f10
//   600bb15c FUN_600bb15c
// --- callees ---
//   600ba1c4 FUN_600ba1c4
//   6006dfa4 FUN_6006dfa4
//   600b7800 FUN_600b7800
//   6006ddd8 FUN_6006ddd8
//   600bcc30 FUN_600bcc30
//   600bc880 FUN_600bc880
//   600f7ca0 FUN_600f7ca0
//   600b5e00 FUN_600b5e00
//   600bcbe0 FUN_600bcbe0
//   600aa340 FUN_600aa340
//   600f7d88 FUN_600f7d88


void FUN_600b9e28(int param_1)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int local_c;
  
  pbVar6 = (byte *)(param_1 + 8 + (uint)*(ushort *)(param_1 + 4));
  local_c = 0;
  uVar1 = (ushort)pbVar6[1] * 0x100 + (ushort)*pbVar6;
  if (((byte)(uVar1 >> 0xc) & 3) == 1) {
    FUN_6006ddd8(param_1,DAT_600ba1a4,0xf8);
  }
  else {
    iVar4 = FUN_600bcbe0((ushort)(((uint)uVar1 << 0x14) >> 0x14));
    if (iVar4 == 0) {
      if (((*(short *)(param_1 + 6) == 0) &&
          ((ushort)((ushort)pbVar6[7] * 0x100 + (ushort)pbVar6[6]) == 1)) &&
         ((pbVar6[8] == 10 || (pbVar6[8] == 2)))) {
        *(undefined2 *)(param_1 + 6) = 2;
        FUN_6006dfa4(DAT_600ba198,param_1);
        if (*(short *)(DAT_600ba19c + 0xeac) == 1) {
          FUN_600aa340(DAT_600ba1a0,4,2);
        }
      }
      else {
        FUN_6006ddd8(param_1,DAT_600ba1a4,0xf1);
      }
    }
    else {
      uVar1 = (ushort)pbVar6[3] * 0x100 + (ushort)pbVar6[2];
      *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 4;
      sVar2 = (ushort)pbVar6[5] * 0x100 + (ushort)pbVar6[4];
      uVar3 = (ushort)pbVar6[7] * 0x100 + (ushort)pbVar6[6];
      if (uVar1 < 4) {
        FUN_6006ddd8(param_1,DAT_600ba1a4,0x11e);
      }
      else {
        *(ushort *)(param_1 + 2) = uVar1 - 4;
        *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 4;
        if (sVar2 == *(short *)(param_1 + 2)) {
          if (((iVar4 != 0) && (*(char *)(iVar4 + 0x32) == '\x02')) &&
             (*(char *)(iVar4 + 1) != '\x05')) {
            FUN_600f7ca0(iVar4 + 4);
          }
          if ((uVar3 < 0x40) || (local_c = FUN_600bcc30(iVar4,uVar3), local_c != 0)) {
            if (uVar3 == 1) {
              FUN_600ba1c4(iVar4,pbVar6 + 8,sVar2);
              FUN_6006ddd8(param_1,DAT_600ba1a4,0x14f);
            }
            else if (uVar3 == 2) {
              FUN_6006ddd8(param_1,DAT_600ba1a4,0x187);
            }
            else if (uVar3 == 5) {
              if (iVar4 != 0) {
                FUN_600f7d88(iVar4,pbVar6 + 8,sVar2);
              }
              FUN_6006ddd8(param_1,DAT_600ba1a4,0x194);
            }
            else if (((uVar3 < 4) || (7 < uVar3)) ||
                    (*(int *)((uVar3 - 4) * 0x1c + DAT_600ba19c + 0xed4) == 0)) {
              if (local_c == 0) {
                FUN_6006ddd8(param_1,DAT_600ba1a4,0x1b3);
              }
              else if (*(char *)(local_c + 0x7e) == '\0') {
                FUN_600b5e00(local_c,0x14,param_1);
              }
              else if ((*(char *)(local_c + 4) == '\x06') || (*(char *)(local_c + 4) == '\x05')) {
                FUN_600b7800(local_c,param_1);
              }
              else {
                FUN_6006ddd8(param_1,DAT_600ba1c0,0x1d3);
              }
            }
            else if (((iVar4 == 0) || (*(char *)(iVar4 + 1) == '\x05')) ||
                    (iVar5 = FUN_600bc880(iVar4,uVar3,(uVar3 - 4) * 0x1c + DAT_600ba19c + 0xedc),
                    iVar5 == 0)) {
              FUN_6006ddd8(param_1,DAT_600ba1a4,0x1ab);
            }
            else {
              iVar5 = *(int *)(iVar4 + (uVar3 + 0x20) * 4);
              if (*(char *)(iVar5 + 0x7e) == '\0') {
                (**(code **)((uVar3 - 4) * 0x1c + DAT_600ba19c + 0xed4))(iVar4 + 4,param_1);
              }
              else {
                FUN_600b7800(iVar5,param_1);
              }
            }
          }
          else {
            FUN_6006ddd8(param_1,DAT_600ba1a4,0x144);
          }
        }
        else {
          FUN_6006ddd8(param_1,DAT_600ba1a4,0x127);
        }
      }
    }
  }
  return;
}


