// 60096a50  FUN_60096a50  size=944 bytes
// --- callers ---
//   60097174 FUN_60097174
// --- callees ---
//   600b9afc FUN_600b9afc
//   6006ed2c FUN_6006ed2c
//   6006dbac FUN_6006dbac
//   6006de78 FUN_6006de78
//   6006dd90 FUN_6006dd90
//   600b9d18 FUN_600b9d18
//   6006dcdc FUN_6006dcdc
//   6006ddd8 FUN_6006ddd8


short FUN_60096a50(int *param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bStack_19;
  short sStack_18;
  char local_15;
  ushort uStack_14;
  short local_12;
  
  local_12 = 0;
  if ((char)param_1[3] == '\x02') {
    while (iVar4 = FUN_6006ed2c(*(undefined1 *)(DAT_60096cec + 0xb),&bStack_19,1), iVar4 != 0) {
      local_12 = local_12 + 1;
      local_15 = '\0';
      switch(*(undefined1 *)((int)param_1 + 10)) {
      case 0:
        if (bStack_19 == 4) {
          iVar4 = FUN_6006dcdc(1,PTR_s_hcisu_h4_receive_msg_60096cf0,0x174);
          *param_1 = iVar4;
        }
        else if (bStack_19 == 2) {
          iVar4 = FUN_6006dcdc(2,PTR_s_hcisu_h4_receive_msg_60096cf0,0x17a);
          *param_1 = iVar4;
        }
        else {
          if (bStack_19 != 3) {
            if (bStack_19 == 7) {
              iVar4 = FUN_6006dbac(0x47,PTR_s_hcisu_h4_receive_msg_60096cf0,0x180);
              *param_1 = iVar4;
              if (*param_1 == 0) {
                *(undefined1 *)((int)param_1 + 10) = 6;
              }
              else {
                *(undefined2 *)(*param_1 + 2) = 0;
                *(undefined2 *)*param_1 = 0;
                *(undefined2 *)(*param_1 + 4) = 0;
                *(byte *)(param_1 + 2) = bStack_19;
                *(undefined1 *)((int)param_1 + 10) = 3;
              }
              *(undefined2 *)(param_1 + 1) = 0x3f;
            }
            break;
          }
          iVar4 = FUN_6006dcdc(2,PTR_s_hcisu_h4_receive_msg_60096cf0,0x17d);
          *param_1 = iVar4;
        }
        *(byte *)(param_1 + 2) = bStack_19;
        if (*param_1 == 0) {
          *(undefined1 *)((int)param_1 + 10) = 2;
        }
        else {
          *(undefined2 *)(*param_1 + 2) = 0;
          *(undefined2 *)*param_1 = *(undefined2 *)(PTR_DAT_60096cf4 + (bStack_19 - 1) * 2);
          *(undefined2 *)(*param_1 + 4) = 0;
          *(undefined1 *)((int)param_1 + 10) = 1;
        }
        *(ushort *)(param_1 + 1) = (ushort)(byte)PTR_DAT_60096cf8[bStack_19 - 1];
        break;
      case 1:
        iVar4 = *param_1;
        uVar2 = *(ushort *)(*param_1 + 4);
        uVar3 = *(ushort *)(*param_1 + 2);
        *(ushort *)(*param_1 + 2) = uVar3 + 1;
        *(byte *)((uint)uVar3 + (uint)uVar2 + iVar4 + 8) = bStack_19;
        *(short *)(param_1 + 1) = (short)param_1[1] + -1;
        if ((short)param_1[1] == 0) {
          uStack_14 = (ushort)bStack_19;
          if ((char)param_1[2] == '\x02') {
            uStack_14 = (ushort)*(byte *)((int)param_1 + 9) + uStack_14 * 0x100;
            iVar4 = FUN_600b9afc(*param_1);
            *param_1 = iVar4;
            if (*param_1 == 0) {
              *(ushort *)(param_1 + 1) = uStack_14;
              if (uStack_14 == 0) {
                *(undefined1 *)((int)param_1 + 10) = 0;
              }
              else {
                *(undefined1 *)((int)param_1 + 10) = 6;
              }
              break;
            }
          }
          *(ushort *)(param_1 + 1) = uStack_14;
          bVar1 = PTR_DAT_60096cf8[*(byte *)(param_1 + 2) - 1];
          uVar6 = (uint)uStack_14;
          uVar2 = *(ushort *)(*param_1 + 4);
          uVar5 = FUN_6006dd90(*param_1);
          if (uVar5 < uVar6 + bVar1 + (uint)uVar2 + 8) {
            FUN_6006ddd8(*param_1,PTR_s_hcisu_h4_receive_msg_60096cf0,0x264);
            *param_1 = 0;
            *(undefined1 *)((int)param_1 + 10) = 6;
          }
          else if (uStack_14 == 0) {
            local_15 = '\x01';
            *(undefined1 *)((int)param_1 + 10) = 0;
          }
          else {
            *(undefined1 *)((int)param_1 + 10) = 3;
          }
        }
        else {
          *(byte *)((int)param_1 + 9) = bStack_19;
        }
        break;
      case 2:
        *(short *)(param_1 + 1) = (short)param_1[1] + -1;
        if ((short)param_1[1] == 0) {
          uStack_14 = (ushort)bStack_19;
          if ((char)param_1[2] == '\x02') {
            uStack_14 = (ushort)*(byte *)((int)param_1 + 9) + uStack_14 * 0x100;
          }
          *(ushort *)(param_1 + 1) = uStack_14;
          *(undefined1 *)((int)param_1 + 10) = 6;
        }
        else {
          *(byte *)((int)param_1 + 9) = bStack_19;
        }
        break;
      case 3:
        iVar4 = *param_1;
        uVar2 = *(ushort *)(*param_1 + 4);
        uVar3 = *(ushort *)(*param_1 + 2);
        *(ushort *)(*param_1 + 2) = uVar3 + 1;
        *(byte *)((uint)uVar3 + (uint)uVar2 + iVar4 + 8) = bStack_19;
        *(short *)(param_1 + 1) = (short)param_1[1] + -1;
        if ((short)param_1[1] != 0) {
          sStack_18 = FUN_6006ed2c(*(undefined1 *)(DAT_60096e30 + 0xb),
                                   *param_1 + 8 +
                                   (uint)*(ushort *)(*param_1 + 2) + (uint)*(ushort *)(*param_1 + 4)
                                   ,(short)param_1[1]);
          *(short *)(*param_1 + 2) = sStack_18 + *(short *)(*param_1 + 2);
          *(short *)(param_1 + 1) = (short)param_1[1] - sStack_18;
          local_12 = sStack_18 + local_12;
        }
        if ((short)param_1[1] == 0) {
          if ((char)param_1[2] == '\a') {
            FUN_6006ddd8(*param_1,DAT_60096e34,0x2b7);
            *(undefined1 *)((int)param_1 + 10) = 0;
          }
          else if (((char)param_1[2] == '\x02') && (iVar4 = FUN_600b9d18(), iVar4 == 0)) {
            *(undefined1 *)((int)param_1 + 10) = 0;
          }
          else {
            local_15 = '\x01';
            *(undefined1 *)((int)param_1 + 10) = 0;
          }
        }
        break;
      case 6:
        *(short *)(param_1 + 1) = (short)param_1[1] + -1;
        if ((short)param_1[1] == 0) {
          *(undefined1 *)((int)param_1 + 10) = 0;
        }
      }
      if (local_15 != '\0') {
        FUN_6006de78(*(undefined1 *)(DAT_60096e30 + 0xd),0,*param_1,DAT_60096e34,0x309);
        *param_1 = 0;
      }
    }
  }
  else {
    local_12 = 0;
  }
  return local_12;
}


