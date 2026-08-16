// 600644dc  usb_host_audio_topology__600644dc  size=956 bytes
// src: usb_host_audio_topology.cc
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   600d5bb6 FUN_600d5bb6
//   600d5d02 FUN_600d5d02
//   600d5fc2 FUN_600d5fc2
//   600d5c6a FUN_600d5c6a
//   600d6028 FUN_600d6028
//   60063dec FUN_60063dec
//   600d61c8 FUN_600d61c8
//   600d5bc6 FUN_600d5bc6
//   600d1a62 FUN_600d1a62
//   600d1a9c FUN_600d1a9c
//   600d6658 FUN_600d6658
//   600d5ee6 FUN_600d5ee6
//   600d5f7e FUN_600d5f7e
//   600d6866 FUN_600d6866
//   6010165c FUN_6010165c
//   600d614a FUN_600d614a
//   60101fde FUN_60101fde


/* src: usb_host_audio_topology.cc */

undefined4
usb_host_audio_topology__600644dc
          (int param_1,int param_2,uint param_3,uint param_4,char param_5,char param_6,uint param_7,
          int *param_8,byte *param_9,undefined4 *param_10,undefined1 *param_11,undefined1 *param_12,
          undefined1 *param_13,undefined4 param_14)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  int extraout_r2;
  char cVar11;
  int iVar12;
  byte *pbVar13;
  int iVar14;
  int extraout_r3;
  int iVar15;
  undefined1 *puVar16;
  byte bVar17;
  undefined1 *puVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  undefined8 uVar23;
  byte *local_80;
  undefined1 local_4a;
  undefined1 local_49;
  int local_48;
  int local_44;
  int local_40;
  undefined1 auStack_3c [4];
  int local_38;
  undefined1 *local_34;
  int iStack_30;
  
  if (*(char *)(param_1 + 0x78) == '\0') {
    FUN_6010165c(0x28,DAT_6006475c,0x443,DAT_60064758);
    uVar2 = 9;
  }
  else {
    iVar12 = *(int *)(param_1 + 0x5c);
    pbVar13 = *(byte **)(param_1 + 0x70);
    local_80 = *(byte **)(param_1 + 0x6c);
    while (pbVar13 != local_80) {
      pbVar9 = local_80 + 1;
      iVar14 = iVar12 + (uint)*local_80 * 0x40;
      uVar3 = FUN_600d1a62(iVar14);
      for (bVar17 = 0; local_80 = pbVar9, bVar17 < uVar3; bVar17 = bVar17 + 1) {
        local_38 = 0;
        iVar4 = FUN_600d1a9c(iVar14,(uint)bVar17,&local_48,&local_44,&local_40,auStack_3c,&local_38,
                             0);
        if ((iVar4 == 0) &&
           ((*(char *)(param_1 + 0x79) == '\0' || (*(char *)(param_1 + 0x79) == ' ')))) {
          uVar1 = *(undefined1 *)(local_48 + 3);
          local_4a = 0xff;
          if (param_2 == 0) {
            iVar4 = FUN_600d614a();
          }
          else {
            iVar4 = FUN_600d61c8(param_1,uVar1,&local_4a);
          }
          iVar5 = local_44;
          if (iVar4 != 0) {
            if (*(char *)(param_1 + 0x79) == '\0') {
              iVar7 = local_44 + 8;
              iVar15 = (short)(ushort)*(byte *)(local_44 + 7) * 3 + iVar7;
              do {
                if (iVar15 == iVar7) {
                  iVar4 = 0;
                  goto LAB_600645ec;
                }
                uVar23 = FUN_600d5bb6(iVar7);
                iVar7 = (int)((ulonglong)uVar23 >> 0x20) + 3;
              } while ((uint)uVar23 != param_7);
              *param_10 = 0;
              *(bool *)(param_10 + 1) = 1 < *(byte *)(iVar5 + 7);
LAB_600645ec:
              if ((param_4 & 0xffff0000) == 0) {
                bVar20 = *(byte *)(iVar5 + 3) == param_3;
                bVar19 = (param_4 & ~(uint)*(ushort *)(local_48 + 5)) == 0;
                bVar21 = *(char *)(iVar5 + 6) == param_5;
                bVar22 = *(char *)(iVar5 + 4) == param_6;
LAB_60064630:
                *(bool *)param_14 = local_38 != 0;
                if (((((iVar4 != 0) && (bVar20)) && (bVar19)) && ((bVar21 && (bVar22)))) &&
                   ((local_38 == 0 &&
                    ((-1 < (int)((uint)*(byte *)(local_40 + 3) << 0x1b) &&
                     ((*(byte *)(local_40 + 3) & 3) == 1)))))) {
                  *param_8 = iVar14;
                  *param_9 = bVar17;
                  if (param_2 == 0) {
                    *param_11 = uVar1;
                    *param_12 = local_4a;
                  }
                  else {
                    *param_11 = local_4a;
                    *param_12 = uVar1;
                  }
                  local_49 = *param_11;
                  *param_13 = 0xff;
                  while( true ) {
                    iVar12 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54),&local_49);
                    if (*(int *)(param_1 + 0x54) + 4 == iVar12) {
                      return 0;
                    }
                    iVar12 = FUN_60063dec(*(int *)(param_1 + 0x54),&local_49);
                    iVar14 = FUN_600d5d02();
                    if (iVar14 != 0) {
                      *param_13 = local_49;
                      return 0;
                    }
                    iVar14 = FUN_600d5c6a(iVar12);
                    if (iVar14 != 0) {
                      return 0;
                    }
                    FUN_600d5f7e(&local_34,iVar12 + 8);
                    if (iStack_30 - (int)local_34 != 1) break;
                    local_49 = *local_34;
                    FUN_600d5fc2(&local_34);
                  }
                  FUN_6010165c(0x28,DAT_600648ac,0x4e2,DAT_600648a8);
                  FUN_600d5fc2(&local_34);
                  return 0;
                }
              }
            }
            else if (*(char *)(param_1 + 0x79) == ' ') {
              iVar5 = FUN_60063dec(*(undefined4 *)(param_1 + 0x54),local_48 + 3);
              FUN_600d6866(&local_34,param_1,*(undefined1 *)(iVar5 + 7));
              puVar8 = local_34 + 4;
              puVar10 = *(undefined1 **)(local_34 + 8);
              puVar18 = puVar8;
              while (puVar10 != (undefined1 *)0x0) {
                if (*(uint *)(puVar10 + 0x10) < param_7) {
                  puVar10 = *(undefined1 **)(puVar10 + 0xc);
                }
                else {
                  puVar10 = *(undefined1 **)(puVar10 + 8);
                  puVar18 = puVar10;
                }
              }
              if ((puVar8 == puVar18) ||
                 (puVar10 = *(undefined1 **)(local_34 + 8), puVar16 = puVar8,
                 param_7 < *(uint *)(puVar18 + 0x10))) {
                iVar4 = 0;
              }
              else {
                while (puVar10 != (undefined1 *)0x0) {
                  if (*(uint *)(puVar10 + 0x10) < param_7) {
                    puVar10 = *(undefined1 **)(puVar10 + 0xc);
                  }
                  else {
                    puVar10 = *(undefined1 **)(puVar10 + 8);
                    puVar16 = puVar10;
                  }
                }
                if ((puVar8 == puVar16) || (param_7 < *(uint *)(puVar16 + 0x10))) {
                    /* WARNING: Subroutine does not return */
                  FUN_60101fde(DAT_60064760);
                }
                *param_10 = *(undefined4 *)(puVar16 + 0x14);
                *(undefined1 *)(param_10 + 1) = puVar16[0x18];
                cVar11 = puVar16[0x24];
                if (*(char *)(param_10 + 4) == '\0') {
                  if (cVar11 == '\0') goto LAB_6006482a;
                  uVar2 = *(undefined4 *)(puVar16 + 0x20);
                  param_10[2] = *(undefined4 *)(puVar16 + 0x1c);
                  param_10[3] = uVar2;
                  cVar11 = '\x01';
LAB_60064826:
                  *(char *)(param_10 + 4) = cVar11;
                }
                else if (cVar11 == '\0') {
LAB_6006482a:
                  if (*(char *)(param_10 + 4) != '\0') goto LAB_60064826;
                }
                else {
                  uVar2 = *(undefined4 *)(puVar16 + 0x20);
                  param_10[2] = *(undefined4 *)(puVar16 + 0x1c);
                  param_10[3] = uVar2;
                }
                FUN_600d5ee6(param_10 + 5,puVar16 + 0x28);
                cVar11 = puVar16[0x37];
                if (*(char *)((int)param_10 + 0x23) == '\0') {
                  if (cVar11 == '\0') goto LAB_60064846;
                  *(undefined2 *)(param_10 + 8) = *(undefined2 *)(puVar16 + 0x34);
                  *(undefined1 *)((int)param_10 + 0x22) = puVar16[0x36];
                  cVar11 = '\x01';
LAB_60064840:
                  *(char *)((int)param_10 + 0x23) = cVar11;
                }
                else if (cVar11 == '\0') {
LAB_60064846:
                  if (*(char *)((int)param_10 + 0x23) != '\0') goto LAB_60064840;
                }
                else {
                  *(undefined2 *)(param_10 + 8) = *(undefined2 *)(puVar16 + 0x34);
                  *(undefined1 *)((int)param_10 + 0x22) = puVar16[0x36];
                }
                *(bool *)(param_10 + 1) = 1 < *(uint *)(local_34 + 0x14);
              }
              bVar20 = *(byte *)(local_44 + 3) == param_3;
              uVar6 = FUN_600d5bc6(local_48 + 6);
              bVar19 = (param_4 & ~uVar6) == 0;
              bVar21 = *(char *)(extraout_r2 + 5) == param_5;
              bVar22 = *(char *)(extraout_r3 + 10) == param_6;
              if (local_34 != (undefined1 *)0x0) {
                FUN_600d6658();
              }
              goto LAB_60064630;
            }
          }
        }
      }
    }
    uVar2 = 5;
  }
  return uVar2;
}


