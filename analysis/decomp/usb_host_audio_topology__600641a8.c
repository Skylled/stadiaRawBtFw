// 600641a8  usb_host_audio_topology__600641a8  size=622 bytes
// src: usb_host_audio_topology.cc
// --- callers ---
//   600d6866 FUN_600d6866
// --- callees ---
//   600d5be6 FUN_600d5be6
//   600d5bb6 FUN_600d5bb6
//   600d5cbe FUN_600d5cbe
//   60101d4e FUN_60101d4e
//   600d6028 FUN_600d6028
//   60063dec FUN_60063dec
//   600d5e6c FUN_600d5e6c
//   6013d378 thunk_EXT_FUN_0000b532
//   600d5cc4 FUN_600d5cc4
//   600d6698 FUN_600d6698
//   60101d4a thunk_FUN_60101ccc
//   6010165c FUN_6010165c
//   60101fde FUN_60101fde
//   600d5cca FUN_600d5cca
//   600d5bca FUN_600d5bca


/* src: usb_host_audio_topology.cc */

void usb_host_audio_topology__600641a8(int param_1,int *param_2,int param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  ushort *puVar13;
  int iVar14;
  undefined8 uVar15;
  int local_90;
  undefined1 local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined4 local_74;
  undefined1 local_70;
  undefined1 local_6c;
  uint local_68;
  char local_64;
  undefined4 local_60;
  undefined2 *local_5c;
  undefined2 *local_58;
  undefined1 local_51;
  undefined4 local_50;
  undefined1 auStack_4c [20];
  undefined4 local_38;
  
  uVar11 = 0;
  local_70 = 1;
  local_74 = 1;
  iVar8 = param_3 + 4;
  local_64 = '\0';
  local_58 = (undefined2 *)0x0;
  local_51 = 0;
  local_60 = 0;
  local_5c = (undefined2 *)0x0;
LAB_600641d0:
  if ((uint)(param_2[1] - *param_2) <= uVar11) {
LAB_600643c8:
    FUN_600d5bca(local_60);
    return;
  }
  local_79 = *(undefined1 *)(*param_2 + uVar11);
  iVar3 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54),&local_79);
  if (*(int *)(param_1 + 0x54) + 4 == iVar3) {
    uVar7 = 0x3a9;
    uVar9 = DAT_60064418;
  }
  else {
    uVar7 = FUN_60063dec(*(int *)(param_1 + 0x54),&local_79);
    iVar3 = FUN_600d5cbe();
    uVar1 = local_79;
    if (iVar3 != 0) {
      iVar14 = *(int *)(*(int *)(param_1 + 0x58) + 8);
      iVar12 = *(int *)(param_1 + 0x58) + 4;
      local_77 = 1;
      local_78 = local_79;
      iVar6 = iVar12;
      iVar10 = iVar14;
      while (iVar10 != 0) {
        iVar4 = FUN_600d5be6(iVar10 + 0x10,&local_78);
        if (iVar4 == 0) {
          iVar6 = iVar10;
          iVar10 = *(int *)(iVar10 + 8);
        }
        else {
          iVar10 = *(int *)(iVar10 + 0xc);
        }
      }
      if ((iVar12 == iVar6) ||
         (iVar10 = FUN_600d5be6(&local_78,iVar6 + 0x10), iVar6 = iVar12, iVar10 != 0)) {
        FUN_6010165c(0x28,DAT_6006441c,0x3af,DAT_60064434,uVar1);
        goto LAB_600643c8;
      }
      while (iVar10 = iVar14, iVar10 != 0) {
        iVar14 = FUN_600d5be6(iVar10 + 0x10,&local_78);
        if (iVar14 == 0) {
          iVar14 = *(int *)(iVar10 + 8);
          iVar6 = iVar10;
        }
        else {
          iVar14 = *(int *)(iVar10 + 0xc);
        }
      }
      if ((iVar12 == iVar6) || (iVar10 = FUN_600d5be6(&local_78,iVar6 + 0x10), iVar10 != 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_60101fde(DAT_60064420);
      }
      puVar13 = *(ushort **)(iVar6 + 0x14) + 1;
      uVar2 = **(ushort **)(iVar6 + 0x14);
      for (local_90 = 0; local_90 < (int)(uint)uVar2; local_90 = local_90 + 1) {
        uVar7 = FUN_600d5bb6(puVar13);
        uVar15 = FUN_600d5bb6(puVar13 + 2,uVar7);
        uVar5 = (uint)((ulonglong)uVar15 >> 0x20);
        if ((uint)uVar15 != uVar5) {
          FUN_6010165c(0x28,DAT_6006441c,0x3bd,DAT_60064424);
          break;
        }
        local_6c = local_79;
        if (local_64 == '\0') {
          local_64 = '\x01';
        }
        local_68 = uVar5;
        local_50 = uVar5;
        FUN_600d5e6c(auStack_4c,&local_74);
        uVar5 = local_50;
        iVar6 = iVar3;
        iVar10 = iVar8;
        iVar14 = *(int *)(param_3 + 8);
        while (iVar14 != 0) {
          iVar10 = iVar14;
          if (local_50 < *(uint *)(iVar14 + 0x10)) {
            iVar6 = iVar3;
            iVar14 = *(int *)(iVar14 + 8);
          }
          else {
            iVar6 = 0;
            iVar14 = *(int *)(iVar14 + 0xc);
          }
        }
        iVar14 = iVar10;
        if (iVar6 == 0) {
LAB_60064330:
          if (*(uint *)(iVar14 + 0x10) < uVar5) goto LAB_60064336;
        }
        else {
          if (*(int *)(param_3 + 0xc) != iVar10) {
            iVar14 = thunk_FUN_60101ccc(iVar10);
            goto LAB_60064330;
          }
LAB_60064336:
          iVar6 = iVar3;
          if (iVar8 != iVar10) {
            if (uVar5 < *(uint *)(iVar10 + 0x10)) {
              iVar6 = 1;
            }
            else {
              iVar6 = 0;
            }
          }
          iVar14 = thunk_EXT_FUN_0000b532(0x38);
          *(uint *)(iVar14 + 0x10) = local_50;
          FUN_600d5e6c(iVar14 + 0x14,auStack_4c);
          FUN_60101d4e(iVar6,iVar14,iVar10,iVar8);
          *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + 1;
        }
        puVar13 = puVar13 + 6;
        FUN_600d5bca(local_38);
      }
LAB_600642d8:
      uVar11 = uVar11 + 1;
      goto LAB_600641d0;
    }
    iVar3 = FUN_600d5cc4(uVar7);
    if (iVar3 != 0) {
      if (uVar11 == (param_2[1] - *param_2) - 1U) {
        uVar7 = 0x3c9;
        uVar9 = DAT_60064428;
        goto LAB_600641fe;
      }
      uVar1 = *(undefined1 *)(*param_2 + uVar11 + 1);
      iVar3 = FUN_600d5cca(uVar7,uVar1);
      if (iVar3 != 0xff) {
        local_50._0_2_ = CONCAT11((char)iVar3,local_79);
        if (local_5c == local_58) {
          FUN_600d6698(&local_60,local_5c,&local_50);
        }
        else {
          *local_5c = (undefined2)local_50;
          local_5c = local_5c + 1;
        }
        goto LAB_600642d8;
      }
      FUN_6010165c(0x28,DAT_6006441c,0x3cf,DAT_6006442c,uVar1,local_79);
      goto LAB_600643c8;
    }
    uVar7 = 0x3d4;
    uVar9 = DAT_60064430;
  }
LAB_600641fe:
  FUN_6010165c(0x28,DAT_6006441c,uVar7,uVar9);
  goto LAB_600643c8;
}


