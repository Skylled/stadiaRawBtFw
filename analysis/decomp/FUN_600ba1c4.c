// 600ba1c4  FUN_600ba1c4  size=3898 bytes
// --- callers ---
//   600b9e28 FUN_600b9e28
// --- callees ---
//   600b5e00 FUN_600b5e00
//   600f8ed0 FUN_600f8ed0
//   600f99ee FUN_600f99ee
//   600f8c6a FUN_600f8c6a
//   600bb904 FUN_600bb904
//   600bc1a8 FUN_600bc1a8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600bcc30 FUN_600bcc30
//   600aa3cc FUN_600aa3cc
//   600bc994 FUN_600bc994
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600bb760 FUN_600bb760
//   600bbd3c FUN_600bbd3c
//   600bbbf8 FUN_600bbbf8
//   600f9ae6 FUN_600f9ae6
//   600bbb2c FUN_600bbb2c


void FUN_600ba1c4(int param_1,byte *param_2,ushort param_3)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *local_b0;
  undefined1 auStack_a8 [6];
  undefined1 local_a2;
  short local_98;
  undefined1 local_96;
  short local_94;
  undefined1 local_92;
  byte local_90;
  byte local_8f;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  undefined1 local_78;
  short local_76;
  undefined1 local_74;
  byte local_72;
  byte local_71;
  byte local_70;
  short local_6e;
  short local_6c;
  short local_6a;
  undefined1 local_68;
  byte local_67;
  undefined1 local_66;
  byte local_64;
  byte local_63;
  short local_62;
  int local_60;
  int local_5c;
  int local_58;
  short local_54;
  undefined1 auStack_50 [8];
  short local_48;
  short local_46;
  short local_44;
  short local_42;
  short local_40;
  short local_3e;
  int local_3c;
  byte *local_38;
  byte local_32;
  byte local_31;
  byte *local_30;
  code *local_2c;
  short local_28;
  ushort local_26;
  ushort local_24;
  byte local_22;
  byte local_21;
  byte *local_20;
  ushort local_1a;
  short local_18;
  char local_16;
  char local_15;
  int local_14;
  short local_e;
  byte *local_c;
  
  local_1a = 0;
  local_e = 0;
  if (*(char *)(param_1 + 0x32) != '\x02') {
    local_16 = 0x2a0 < param_3;
    local_20 = param_2 + param_3;
    local_c = param_2;
    thunk_EXT_FUN_0000b5ba(&local_98,0,0x48);
LAB_600ba21c:
    do {
      if (local_20 + -4 < local_c) {
        return;
      }
      local_21 = *local_c;
      local_22 = local_c[1];
      local_24 = (ushort)local_c[3] * 0x100 + (ushort)local_c[2];
      pbVar2 = local_c + 4;
      pbVar3 = pbVar2 + local_24;
      if (local_20 < pbVar3) {
        return;
      }
      if (local_16 == '\0') {
        switch(local_21) {
        case 1:
          local_3e = (ushort)local_c[5] * 0x100 + (ushort)*pbVar2;
          local_b0 = local_c + 6;
          if (local_3e == 1) {
            local_40 = (ushort)local_c[7] * 0x100 + (ushort)*local_b0;
            local_b0 = local_c + 8;
          }
          if (local_3e == 2) {
            local_e = (ushort)local_b0[1] * 0x100 + (ushort)*local_b0;
            local_1a = (ushort)local_b0[3] * 0x100 + (ushort)local_b0[2];
            local_c = pbVar3;
            local_14 = FUN_600bcc30(param_1,local_1a);
            if ((local_14 != 0) && (local_e == *(short *)(local_14 + 2))) {
              FUN_600b5e00(local_14,3,0);
            }
          }
          else {
            local_c = pbVar3;
            if ((local_3e == 0) && (*(char *)(param_1 + 0xa3) != '\0')) {
              FUN_600aa3cc(param_1 + 0x68);
              *(undefined1 *)(param_1 + 0xa3) = 0;
              local_a2 = 0;
              thunk_EXT_FUN_0000b572(auStack_a8,param_1 + 4,6);
              for (local_14 = *(int *)(param_1 + 0x5c); local_14 != 0;
                  local_14 = *(int *)(local_14 + 0x124)) {
                FUN_600b5e00(local_14,0x13,auStack_a8);
              }
            }
          }
          break;
        case 2:
          local_48 = (ushort)local_c[5] * 0x100 + (ushort)*pbVar2;
          local_e = (ushort)local_c[7] * 0x100 + (ushort)local_c[6];
          local_c = pbVar3;
          local_3c = FUN_600bc1a8(local_48);
          if (local_3c == 0) {
            FUN_600f8ed0(param_1,local_e,local_22,2);
          }
          else if (*(int *)(local_3c + 8) == 0) {
            FUN_600f8ed0(param_1,local_e,local_22,2);
          }
          else {
            local_14 = FUN_600bbd3c(param_1,0);
            if (local_14 == 0) {
              FUN_600f8ed0(param_1,local_e,local_22,4);
            }
            else {
              *(byte *)(local_14 + 8) = local_22;
              *(int *)(local_14 + 0x154) = local_3c;
              *(short *)(local_14 + 2) = local_e;
              FUN_600b5e00(local_14,10,auStack_50);
            }
          }
          break;
        case 3:
          local_42 = (ushort)local_c[5] * 0x100 + (ushort)*pbVar2;
          local_1a = (ushort)local_c[7] * 0x100 + (ushort)local_c[6];
          local_46 = (ushort)local_c[9] * 0x100 + (ushort)local_c[8];
          local_44 = (ushort)local_c[0xb] * 0x100 + (ushort)local_c[10];
          local_e = local_42;
          local_c = pbVar3;
          local_14 = FUN_600bcc30(param_1,local_1a);
          if ((local_14 != 0) && (local_22 == *(byte *)(local_14 + 7))) {
            if (local_46 == 0) {
              FUN_600b5e00(local_14,0xb,auStack_50);
            }
            else if (local_46 == 1) {
              FUN_600b5e00(local_14,0xc,auStack_50);
            }
            else {
              FUN_600b5e00(local_14,0xd,auStack_50);
            }
          }
          break;
        case 4:
          local_30 = pbVar2 + local_24;
          local_15 = '\0';
          local_18 = 0;
          local_1a = (ushort)local_c[5] * 0x100 + (ushort)*pbVar2;
          local_54 = (ushort)local_c[7] * 0x100 + (ushort)local_c[6];
          local_38 = local_c + 8;
          local_68 = 0;
          local_74 = 0;
          local_92 = 0;
          local_96 = 0;
          local_78 = 0;
          local_b0 = local_38;
          while (local_b0 < local_30) {
            local_31 = *local_b0;
            local_32 = local_b0[1];
            pbVar2 = local_b0 + 2;
            switch(local_31 & 0x7f) {
            case 1:
              local_96 = 1;
              local_94 = (ushort)local_b0[3] * 0x100 + (ushort)*pbVar2;
              local_b0 = local_b0 + 4;
              break;
            case 2:
              local_78 = 1;
              local_76 = (ushort)local_b0[3] * 0x100 + (ushort)*pbVar2;
              local_b0 = local_b0 + 4;
              break;
            case 3:
              local_92 = 1;
              local_90 = *pbVar2;
              local_8f = local_b0[3];
              local_8c = (uint)local_b0[7] * 0x1000000 +
                         (uint)local_b0[4] + (uint)local_b0[5] * 0x100 + (uint)local_b0[6] * 0x10000
              ;
              local_88 = (uint)local_b0[0xb] * 0x1000000 +
                         (uint)local_b0[8] + (uint)local_b0[9] * 0x100 +
                         (uint)local_b0[10] * 0x10000;
              local_84 = (uint)local_b0[0xf] * 0x1000000 +
                         (uint)local_b0[0xc] + (uint)local_b0[0xd] * 0x100 +
                         (uint)local_b0[0xe] * 0x10000;
              local_80 = (uint)local_b0[0x13] * 0x1000000 +
                         (uint)local_b0[0x10] + (uint)local_b0[0x11] * 0x100 +
                         (uint)local_b0[0x12] * 0x10000;
              local_7c = (uint)local_b0[0x17] * 0x1000000 +
                         (uint)local_b0[0x14] + (uint)local_b0[0x15] * 0x100 +
                         (uint)local_b0[0x16] * 0x10000;
              local_b0 = local_b0 + 0x18;
              break;
            case 4:
              local_74 = 1;
              local_72 = *pbVar2;
              local_71 = local_b0[3];
              local_70 = local_b0[4];
              local_6e = (ushort)local_b0[6] * 0x100 + (ushort)local_b0[5];
              local_6c = (ushort)local_b0[8] * 0x100 + (ushort)local_b0[7];
              local_6a = (ushort)local_b0[10] * 0x100 + (ushort)local_b0[9];
              local_b0 = local_b0 + 0xb;
              break;
            case 5:
              local_68 = 1;
              local_67 = *pbVar2;
              local_b0 = local_b0 + 3;
              break;
            case 6:
              local_66 = 1;
              local_64 = *pbVar2;
              local_63 = local_b0[3];
              local_62 = (ushort)local_b0[5] * 0x100 + (ushort)local_b0[4];
              local_60 = (uint)local_b0[9] * 0x1000000 +
                         (uint)local_b0[6] + (uint)local_b0[7] * 0x100 + (uint)local_b0[8] * 0x10000
              ;
              local_5c = (uint)local_b0[0xd] * 0x1000000 +
                         (uint)local_b0[10] + (uint)local_b0[0xb] * 0x100 +
                         (uint)local_b0[0xc] * 0x10000;
              local_58 = (uint)local_b0[0x11] * 0x1000000 +
                         (uint)local_b0[0xe] + (uint)local_b0[0xf] * 0x100 +
                         (uint)local_b0[0x10] * 0x10000;
              local_b0 = local_b0 + 0x12;
              break;
            default:
              if (local_24 < (ushort)(local_32 + 2)) {
                local_15 = '\x01';
                local_b0 = local_30;
              }
              else {
                local_b0 = pbVar2 + local_32;
                if (-1 < (char)local_31) {
                  local_18 = local_18 + (ushort)local_32 + 2;
                  local_15 = '\x01';
                }
              }
            }
          }
          local_c = pbVar3;
          local_14 = FUN_600bcc30(param_1,local_1a);
          if ((local_14 == 0) || (local_1a < 8)) {
            FUN_600f8c6a(param_1,2,local_22,local_1a,local_e);
          }
          else {
            *(byte *)(local_14 + 8) = local_22;
            if (local_15 == '\0') {
              FUN_600b5e00(local_14,0xe,&local_98);
            }
            else {
              FUN_600bb904(local_14,local_38,local_24 - 4,local_18);
            }
          }
          break;
        case 5:
          local_30 = pbVar2 + local_24;
          local_1a = (ushort)local_c[5] * 0x100 + (ushort)*pbVar2;
          local_54 = (ushort)local_c[7] * 0x100 + (ushort)local_c[6];
          local_98 = (ushort)local_c[9] * 0x100 + (ushort)local_c[8];
          local_68 = 0;
          local_74 = 0;
          local_92 = 0;
          local_96 = 0;
          local_78 = 0;
          pbVar2 = local_c + 10;
          while (local_b0 = pbVar2, local_b0 < local_30) {
            local_31 = *local_b0;
            local_32 = local_b0[1];
            pbVar2 = local_b0 + 2;
            switch(local_31 & 0x7f) {
            case 1:
              local_96 = 1;
              local_94 = (ushort)local_b0[3] * 0x100 + (ushort)*pbVar2;
              pbVar2 = local_b0 + 4;
              break;
            case 2:
              local_78 = 1;
              local_76 = (ushort)local_b0[3] * 0x100 + (ushort)*pbVar2;
              pbVar2 = local_b0 + 4;
              break;
            case 3:
              local_92 = 1;
              local_90 = *pbVar2;
              local_8f = local_b0[3];
              local_8c = (uint)local_b0[7] * 0x1000000 +
                         (uint)local_b0[4] + (uint)local_b0[5] * 0x100 + (uint)local_b0[6] * 0x10000
              ;
              local_88 = (uint)local_b0[0xb] * 0x1000000 +
                         (uint)local_b0[8] + (uint)local_b0[9] * 0x100 +
                         (uint)local_b0[10] * 0x10000;
              local_84 = (uint)local_b0[0xf] * 0x1000000 +
                         (uint)local_b0[0xc] + (uint)local_b0[0xd] * 0x100 +
                         (uint)local_b0[0xe] * 0x10000;
              local_80 = (uint)local_b0[0x13] * 0x1000000 +
                         (uint)local_b0[0x10] + (uint)local_b0[0x11] * 0x100 +
                         (uint)local_b0[0x12] * 0x10000;
              local_7c = (uint)local_b0[0x17] * 0x1000000 +
                         (uint)local_b0[0x14] + (uint)local_b0[0x15] * 0x100 +
                         (uint)local_b0[0x16] * 0x10000;
              pbVar2 = local_b0 + 0x18;
              break;
            case 4:
              local_74 = 1;
              local_72 = *pbVar2;
              local_71 = local_b0[3];
              local_70 = local_b0[4];
              local_6e = (ushort)local_b0[6] * 0x100 + (ushort)local_b0[5];
              local_6c = (ushort)local_b0[8] * 0x100 + (ushort)local_b0[7];
              local_6a = (ushort)local_b0[10] * 0x100 + (ushort)local_b0[9];
              pbVar2 = local_b0 + 0xb;
              break;
            case 5:
              local_68 = 1;
              local_67 = *pbVar2;
              pbVar2 = local_b0 + 3;
              break;
            case 6:
              local_66 = 1;
              local_64 = *pbVar2;
              local_63 = local_b0[3];
              local_62 = (ushort)local_b0[5] * 0x100 + (ushort)local_b0[4];
              local_60 = (uint)local_b0[9] * 0x1000000 +
                         (uint)local_b0[6] + (uint)local_b0[7] * 0x100 + (uint)local_b0[8] * 0x10000
              ;
              local_5c = (uint)local_b0[0xd] * 0x1000000 +
                         (uint)local_b0[10] + (uint)local_b0[0xb] * 0x100 +
                         (uint)local_b0[0xc] * 0x10000;
              local_58 = (uint)local_b0[0x11] * 0x1000000 +
                         (uint)local_b0[0xe] + (uint)local_b0[0xf] * 0x100 +
                         (uint)local_b0[0x10] * 0x10000;
              pbVar2 = local_b0 + 0x12;
            }
          }
          local_c = pbVar3;
          local_14 = FUN_600bcc30(param_1,local_1a);
          if ((local_14 != 0) && (local_22 == *(byte *)(local_14 + 7))) {
            if ((local_98 == 0) || (local_98 == 4)) {
              FUN_600b5e00(local_14,0xf,&local_98);
            }
            else {
              FUN_600b5e00(local_14,0x10,&local_98);
            }
          }
          break;
        case 6:
          local_1a = (ushort)local_c[5] * 0x100 + (ushort)*pbVar2;
          local_e = (ushort)local_c[7] * 0x100 + (ushort)local_c[6];
          local_c = pbVar3;
          local_14 = FUN_600bcc30(param_1,local_1a);
          if (local_14 == 0) {
            FUN_600f99ee(param_1,local_22,local_1a,local_e);
          }
          else if (local_e == *(short *)(local_14 + 2)) {
            *(byte *)(local_14 + 8) = local_22;
            FUN_600b5e00(local_14,0x11,auStack_50);
          }
          break;
        case 7:
          local_e = (ushort)local_c[5] * 0x100 + (ushort)*pbVar2;
          local_1a = (ushort)local_c[7] * 0x100 + (ushort)local_c[6];
          local_c = pbVar3;
          local_14 = FUN_600bcc30(param_1,local_1a);
          if (((local_14 != 0) && (local_e == *(short *)(local_14 + 2))) &&
             (local_22 == *(byte *)(local_14 + 7))) {
            FUN_600b5e00(local_14,0x12,auStack_50);
          }
          break;
        case 8:
          local_c = pbVar3;
          FUN_600bbb2c(param_1,local_22,0,0);
          break;
        case 9:
          local_c = pbVar3;
          if (*(int *)(param_1 + 0x10) != 0) {
            local_2c = *(code **)(param_1 + 0x10);
            *(undefined4 *)(param_1 + 0x10) = 0;
            (*local_2c)(0);
          }
          break;
        case 10:
          local_26 = (ushort)local_c[5] * 0x100 + (ushort)*pbVar2;
          local_c = pbVar3;
          FUN_600bbbf8(param_1,local_22,local_26);
          break;
        case 0xb:
          local_26 = (ushort)local_c[5] * 0x100 + (ushort)*pbVar2;
          local_28 = (ushort)local_c[7] * 0x100 + (ushort)local_c[6];
          local_b0 = local_c + 8;
          *(byte *)(param_1 + 0x1c) = (byte)(1 << (local_26 & 0xff)) | *(byte *)(param_1 + 0x1c);
          if ((local_26 == 2) && (local_28 == 0)) {
            *(uint *)(param_1 + 0x20) =
                 (uint)*local_b0 + (uint)local_c[9] * 0x100 + (uint)local_c[10] * 0x10000 +
                 (uint)local_c[0xb] * 0x1000000;
            local_b0 = local_c + 0xc;
            if ((*(uint *)(param_1 + 0x20) & 0x80) != 0) {
              local_c = pbVar3;
              FUN_600f9ae6(param_1,3);
              break;
            }
            local_c = pbVar3;
            FUN_600bc994(param_1);
            pbVar3 = local_c;
          }
          local_c = pbVar3;
          if (local_26 == 3) {
            if (local_28 == 0) {
              thunk_EXT_FUN_0000b572(param_1 + 0x24,local_b0,1);
            }
            FUN_600bc994(param_1);
          }
          if (*(char *)(param_1 + 0xa3) != '\0') {
            FUN_600aa3cc(param_1 + 0x68);
            *(undefined1 *)(param_1 + 0xa3) = 0;
            local_a2 = 0;
            thunk_EXT_FUN_0000b572(auStack_a8,param_1 + 4,6);
            for (local_14 = *(int *)(param_1 + 0x5c); local_14 != 0;
                local_14 = *(int *)(local_14 + 0x124)) {
              FUN_600b5e00(local_14,0x13,auStack_a8);
            }
          }
          break;
        default:
          local_c = pbVar3;
          FUN_600f8c6a(param_1,0,local_22,0,0);
          return;
        }
        goto LAB_600ba21c;
      }
      local_c = pbVar3;
      iVar1 = FUN_600bb760(local_21,local_22,param_1);
    } while (iVar1 == 0);
  }
  return;
}


