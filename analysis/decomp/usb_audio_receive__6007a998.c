// 6007a998  usb_audio_receive__6007a998  size=202 bytes
// src: usb_audio_receive.cc
// --- callers ---
//   60075088 audio_states__60075088
// --- callees ---
//   6007a958 FUN_6007a958
//   6010165c FUN_6010165c
//   6013d378 thunk_EXT_FUN_0000b532
//   6010177a FUN_6010177a
//   6013d3c8 thunk_EXT_FUN_00001680
//   60079e28 FUN_60079e28
//   6010209a FUN_6010209a


/* src: usb_audio_receive.cc */

int * usb_audio_receive__6007a998(int *param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_14;
  
  piVar5 = DAT_6007aa64;
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  local_14 = param_2;
  if (*DAT_6007aa64 == 0) {
    piVar5 = (int *)thunk_EXT_FUN_0000b532(0x1a0c);
    FUN_60079e28();
    cVar2 = FUN_6010177a(piVar5 + 1,PTR_s_Usb_Audio_Receiver_6007aa70,0x1b);
    if (cVar2 == '\0') {
      *param_1 = (int)piVar5;
      param_1[1] = 0;
      puVar4 = (undefined4 *)thunk_EXT_FUN_0000b532(0x10);
      puVar4[3] = piVar5;
      param_1[1] = (int)puVar4;
      puVar4[1] = 1;
      puVar4[2] = 1;
      *puVar4 = PTR_PTR_6007aa74;
      if ((piVar5[0x1b] == 0) || (*(int *)(piVar5[0x1b] + 4) == 0)) {
        piVar5[0x1a] = (int)piVar5;
        FUN_6007a958(piVar5 + 0x1b,param_1 + 1);
      }
    }
    else {
      (**(code **)(*piVar5 + 4))(piVar5);
      *param_1 = 0;
      param_1[1] = 0;
    }
  }
  else {
    FUN_6010165c(0x1e,PTR_s_usb_audio_receive_cc_6007aa6c,0x3d,
                 PTR_s_USB_audio_receiver_was_already_c_6007aa68,param_1);
    DataMemoryBarrier(0x1b);
    iVar6 = *piVar5;
    DataMemoryBarrier(0x1b);
    local_14 = *(int *)(iVar6 + 0x6c);
    if (local_14 == 0) {
LAB_6007a9cc:
                    /* WARNING: Subroutine does not return */
      FUN_6010209a();
    }
    piVar5 = (int *)(local_14 + 4);
    iVar7 = *(int *)(local_14 + 4);
    do {
      if (iVar7 == 0) goto LAB_6007a9cc;
      DataMemoryBarrier(0x1b);
      ExclusiveAccess(piVar5);
      iVar3 = *piVar5;
      bVar1 = false;
      if (iVar3 == iVar7) {
        bVar1 = (bool)hasExclusiveAccess(piVar5);
        if (bVar1) {
          *piVar5 = iVar7 + 1;
        }
        DataMemoryBarrier(0x1b);
      }
      iVar7 = iVar3;
    } while (!bVar1);
    *param_1 = *(int *)(iVar6 + 0x68);
    param_1[1] = local_14;
    local_14 = 0;
    thunk_EXT_FUN_00001680(&local_14);
  }
  return param_1;
}


