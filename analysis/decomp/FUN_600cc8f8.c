// 600cc8f8  FUN_600cc8f8  size=122 bytes
// --- callers ---
//   60061ed4 usb_device_audio__60061ed4
//   6005eaf8 FUN_6005eaf8
//   6007014c FUN_6007014c
//   600800c0 FUN_600800c0
//   600d4902 flash_lut__600d4902
//   6005d3b4 thermal__6005d3b4
//   60067c3c gotham__60067c3c
//   60069dd4 FUN_60069dd4
//   6006a21c adapter__6006a21c
//   6007b600 synapse_audio_processor__6007b600
//   6005dcc0 FUN_6005dcc0
//   60061fc0 usb_device_audio__60061fc0
//   6005e904 FUN_6005e904
//   60080fb8 FUN_60080fb8
//   6005ea2c FUN_6005ea2c
//   60065d80 FUN_60065d80
//   60067b50 gotham__60067b50
//   60074658 timer__60074658
//   60077948 FUN_60077948
//   60069b20 adapter__60069b20
//   6007fcec battery_service__6007fcec
//   600d89ec adapter__600d89ec
//   60077a48 FUN_60077a48
//   600626e4 usb_host__600626e4
//   60069a38 adapter__60069a38
//   60078340 firmware_image_upload__60078340
//   6005842c FUN_6005842c
//   6007a2c0 frames__6007a2c0
//   6007a118 usb_audio_receive__6007a118
//   60081550 FUN_60081550
//   6007a504 usb_audio_receive__6007a504
//   6005c270 FUN_6005c270
// --- callees ---
//   600cc8a8 FUN_600cc8a8
//   600edffe FUN_600edffe
//   6013d330 thunk_EXT_FUN_0000b18c
//   600cc824 FUN_600cc824
//   600cc884 FUN_600cc884
//   6010209a FUN_6010209a


undefined4 FUN_600cc8f8(byte *param_1,uint param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint local_1c;
  
  DataMemoryBarrier(0x1b);
  if ((int)((uint)*param_1 << 0x1f) < 0) {
    uVar6 = 0;
  }
  else {
    local_1c = param_2;
    if (DAT_600cc974 == 0) {
      uVar6 = 0;
      if (-1 < *(int *)param_1 << 0x1f) {
        if (param_1[1] != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0x600cc966);
          (*pcVar1)();
        }
        uVar6 = 1;
        param_1[1] = 1;
      }
    }
    else {
      FUN_600cc8a8(&local_1c);
      uVar3 = DAT_600cc980;
      puVar2 = DAT_600cc97c;
      uVar6 = DAT_600cc978;
      while (-1 < *(int *)param_1 << 0x1f) {
        if (param_1[1] == 0) {
          uVar6 = 1;
          param_1[1] = 1;
          goto LAB_600cc946;
        }
        uVar4 = FUN_600cc884();
        thunk_EXT_FUN_0000b18c(uVar6,uVar3);
        iVar5 = FUN_600edffe(uVar4,*puVar2);
        if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_6010209a();
        }
      }
      uVar6 = 0;
LAB_600cc946:
      if ((local_1c & 0xff) != 0) {
        FUN_600cc824();
      }
    }
  }
  return uVar6;
}


