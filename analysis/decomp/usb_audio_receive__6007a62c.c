// 6007a62c  usb_audio_receive__6007a62c  size=772 bytes
// src: usb_audio_receive.cc
// --- callers ---
// --- callees ---
//   60079f1c usb_audio_receive__60079f1c
//   6007a118 usb_audio_receive__6007a118
//   600db8f0 FUN_600db8f0
//   600d37b8 FUN_600d37b8
//   600d3618 FUN_600d3618
//   6013d3c8 thunk_EXT_FUN_00001680
//   6007a040 usb_audio_receive__6007a040
//   600d5240 FUN_600d5240
//   600d52b8 FUN_600d52b8
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   601016f0 FUN_601016f0
//   6007a504 usb_audio_receive__6007a504
//   600dbbd0 FUN_600dbbd0
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d228 thunk_EXT_FUN_000078b0
//   600dba24 FUN_600dba24
//   600d5284 FUN_600d5284
//   60051120 FUN_60051120
//   600d5386 FUN_600d5386
//   600d37ac FUN_600d37ac
//   600d5358 FUN_600d5358
//   6007a0b0 usb_audio_receive__6007a0b0


/* src: usb_audio_receive.cc */

void usb_audio_receive__6007a62c(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char cVar11;
  int iVar12;
  int local_c0;
  undefined *local_bc;
  undefined *local_b8;
  undefined1 *local_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6 [134];
  
  puVar4 = PTR_LAB_600d407e_1_6007a93c;
  local_bc = DAT_6007a930;
  local_b8 = PTR_LAB_60079fa0_1_6007a938;
  FUN_600d5284(DAT_6007a934,&local_bc);
  pcVar10 = (char *)(param_1 + 0x19d0);
  local_bc = puVar4;
  local_b8 = PTR_LAB_60079fd8_1_6007a940;
  FUN_600d5386(DAT_6007a934,&local_bc);
  local_bc = puVar4;
  local_b8 = PTR_LAB_60079fc0_1_6007a944;
  FUN_600d52b8(DAT_6007a934,&local_bc);
  uVar3 = DAT_6007a934;
  local_bc = PTR_s_usb_audio_receive_cc_6007a948;
  local_b8 = (undefined *)0x19f;
  local_b4 = local_a6;
  local_a8 = 0;
  local_a7 = 0;
  local_a6[0] = 0;
  local_b0 = 0x80;
  uStack_ac = 0;
  FUN_600d37ac(&local_b4,PTR_s_Usb_audio_receiving_thread_is_pr_6007a94c);
  FUN_601016f0(0x14,local_bc,local_b8,&local_b4);
  do {
    iVar5 = FUN_600d5240(param_1 + 100,5);
    if (iVar5 == 0) {
      DataMemoryBarrier(0x1b);
      *DAT_6007a954 = 0;
      DataMemoryBarrier(0x1b);
      return;
    }
    iVar5 = FUN_600d5358(uVar3);
    if (iVar5 == 0) {
      thunk_EXT_FUN_000078b0(1,0xffffffff);
    }
    else {
      DataMemoryBarrier(0x1b);
      iVar12 = *(int *)(param_1 + 0x964);
      DataMemoryBarrier(0x1b);
      iVar5 = FUN_600d3618();
      uVar9 = iVar5 - iVar12;
      iVar5 = FUN_600d5240(param_1 + 0x70,5);
      if (iVar5 == 0) {
        iVar5 = 1;
      }
      else {
        iVar5 = 200;
      }
      if (uVar9 < iVar5 + 1U) {
        iVar5 = iVar5 + (1 - uVar9);
      }
      else {
        iVar5 = 0;
      }
      iVar5 = thunk_EXT_FUN_000078b0(1,iVar5);
      if ((iVar5 == 0) && (iVar5 = FUN_600d5358(uVar3), iVar5 != 0)) {
        DataMemoryBarrier(0x1b);
        DataMemoryBarrier(0x1b);
        if (*(int *)(param_1 + 0x964) == iVar12) {
          usb_audio_receive__6007a118(param_1);
        }
      }
    }
    local_c0 = *(int *)(param_1 + 0x960);
    if (local_c0 != 0) {
      piVar6 = (int *)(local_c0 + 4);
      iVar5 = *(int *)(local_c0 + 4);
      do {
        if (iVar5 == 0) {
          local_c0 = 0;
          break;
        }
        DataMemoryBarrier(0x1b);
        ExclusiveAccess(piVar6);
        iVar12 = *piVar6;
        bVar2 = false;
        if (iVar12 == iVar5) {
          bVar2 = (bool)hasExclusiveAccess(piVar6);
          if (bVar2) {
            *piVar6 = iVar5 + 1;
          }
          DataMemoryBarrier(0x1b);
        }
        iVar5 = iVar12;
      } while (!bVar2);
      if (((local_c0 != 0) && (*(int *)(local_c0 + 4) != 0)) &&
         (piVar6 = *(int **)(param_1 + 0x95c), piVar6 != (int *)0x0)) {
        thunk_EXT_FUN_0000b4c2(param_1 + 0x968);
        pcVar7 = (char *)(param_1 + 0x948);
        DataMemoryBarrier(0x1b);
        do {
          ExclusiveAccess(pcVar7);
          cVar11 = *pcVar7;
          bVar2 = (bool)hasExclusiveAccess(pcVar7);
        } while (!bVar2);
        *pcVar7 = '\0';
        DataMemoryBarrier(0x1b);
        if (cVar11 != '\0') {
          FUN_600dba24(param_1 + 0x9bc,*(undefined4 *)(param_1 + 0x9c0));
          DataMemoryBarrier(0x1b);
          *(undefined1 *)(param_1 + 0x70) = 1;
          DataMemoryBarrier(0x1b);
          *pcVar10 = '\x01';
          *(undefined1 *)(param_1 + 0x19d7) = 0;
        }
        pcVar7 = (char *)(param_1 + 0x949);
        DataMemoryBarrier(0x1b);
        do {
          ExclusiveAccess(pcVar7);
          cVar11 = *pcVar7;
          bVar2 = (bool)hasExclusiveAccess(pcVar7);
        } while (!bVar2);
        *pcVar7 = '\0';
        DataMemoryBarrier(0x1b);
        if ((cVar11 != '\0') && (uVar9 = *(uint *)(param_1 + 0x950), uVar9 != 0)) {
          uVar8 = *(uint *)(param_1 + 0x954);
          pcVar7 = (char *)(param_1 + 0x19d6);
          if (4 < uVar8) {
            uVar8 = 5;
          }
          iVar5 = param_1 + uVar8 * 4;
          *(int *)(iVar5 + 0x19dc) = *(int *)(iVar5 + 0x19dc) + 1;
          if ((uVar9 & 3) == 0) {
            if (*pcVar7 != '\0') {
              usb_audio_receive__6007a504(param_1);
              *pcVar7 = '\0';
            }
          }
          else {
            *(int *)(param_1 + 0x19f8) = *(int *)(param_1 + 0x19f8) + 1;
            *pcVar7 = '\0';
          }
          uVar9 = FUN_600dbbd0(param_1 + 0x9bc,param_1 + 0x94c,param_1 + 0x950);
          if ((uVar9 & 0xff) != 0) {
            FUN_60051120(&local_bc,PTR_s_usb_audio_receive_cc_6007a948,0x21a,uVar9);
            FUN_600d37b8(&local_bc);
          }
          uVar9 = *(uint *)(param_1 + 0x950);
          if (((uVar9 & 3) == 0) && (3 < uVar9)) {
            *(undefined4 *)(param_1 + 0x19d2) =
                 *(undefined4 *)(*(int *)(param_1 + 0x94c) + uVar9 + -4);
          }
        }
        cVar11 = *pcVar10;
        if ((cVar11 == '\0') || (iVar5 = usb_audio_receive__60079f1c(param_1), iVar5 == 0)) {
          cVar11 = '\0';
        }
        else {
          *pcVar10 = '\0';
        }
        iVar5 = FUN_600d5358(uVar3);
        if ((iVar5 == 0) && (iVar5 = FUN_600db8f0(param_1), iVar5 != 0)) {
          usb_audio_receive__6007a0b0(param_1,iVar5);
        }
        pcVar7 = (char *)(param_1 + 0x94a);
        DataMemoryBarrier(0x1b);
        do {
          ExclusiveAccess(pcVar7);
          cVar1 = *pcVar7;
          bVar2 = (bool)hasExclusiveAccess(pcVar7);
        } while (!bVar2);
        *pcVar7 = '\0';
        DataMemoryBarrier(0x1b);
        if ((cVar1 != '\0') && (uVar9 = usb_audio_receive__6007a040(param_1), (uVar9 & 0xff) != 0))
        {
          FUN_60051120(&local_bc,PTR_s_usb_audio_receive_cc_6007a948,0x23a,uVar9);
          FUN_600d37ac(&local_b4,PTR_s_Sending_USB_Audio_feedback_faile_6007a950);
          FUN_600d37b8(&local_bc);
        }
        thunk_EXT_FUN_00007d10(param_1 + 0x968);
        if (cVar11 != '\0') {
          (**(code **)(*piVar6 + 8))();
        }
      }
    }
    thunk_EXT_FUN_00001680(&local_c0);
  } while( true );
}


