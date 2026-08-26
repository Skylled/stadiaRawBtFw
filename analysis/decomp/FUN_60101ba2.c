// 60101ba2  FUN_60101ba2  size=42 bytes
// --- callers ---
//   60075d78 headphone_state_machine__60075d78
//   600d8ac6 FUN_600d8ac6
//   60078b4c get_device_data__60078b4c
//   60051b50 stats__60051b50
//   6005a1b0 device_info__6005a1b0
//   60058f58 FUN_60058f58
//   60051240 main__60051240
//   600764fc input_task__600764fc
//   600d521e FUN_600d521e
//   600dfc7e FUN_600dfc7e
//   600834a4 parser__600834a4
//   600d6d96 FUN_600d6d96
//   600d4d2e FUN_600d4d2e
//   600df478 FUN_600df478
//   600db30a FUN_600db30a
//   600d8892 FUN_600d8892
//   600db32c FUN_600db32c
//   6007a504 usb_audio_receive__6007a504
//   600daddc FUN_600daddc
//   60100b48 FUN_60100b48
//   600da67e FUN_600da67e
//   60078340 firmware_image_upload__60078340
//   6005ac18 FUN_6005ac18
//   600d415c FUN_600d415c
//   600dff54 FUN_600dff54
//   600d4036 FUN_600d4036
//   600dff76 FUN_600dff76
//   600df286 FUN_600df286
//   600620b4 usb_device_audio__600620b4
//   600dac68 FUN_600dac68
//   60058aa8 hid_input_target__60058aa8
//   600d8bea FUN_600d8bea
//   600db11a FUN_600db11a
//   6005a13c device_info__6005a13c
//   6005da44 types__6005da44
//   60101bfc FUN_60101bfc
//   600db6f2 FUN_600db6f2
//   60068f88 activation_sequence__60068f88
//   60067ddc logging__60067ddc
//   600d8dd0 FUN_600d8dd0
//   60101bcc FUN_60101bcc
//   600d88b4 FUN_600d88b4
//   600d6db8 FUN_600d6db8
//   60078efc FUN_60078efc
//   600db896 FUN_600db896
//   60069b20 adapter__60069b20
//   600d801c FUN_600d801c
//   600666f0 keys__600666f0
//   600d3ac4 FUN_600d3ac4
//   60065c68 FUN_60065c68
//   6005a4cc device_info__6005a4cc
//   6007fcbc FUN_6007fcbc
//   600df2a6 FUN_600df2a6
//   60058b68 FUN_60058b68
//   600cb6fc key_value_store__600cb6fc
// --- callees ---


void FUN_60101ba2(int param_1,uint param_2)

{
  undefined1 uVar1;
  
  if ((int)param_2 < 0) {
    uVar1 = 3;
  }
  else {
    if (param_2 < (uint)(*(int *)(param_1 + 4) - *(int *)(param_1 + 8))) {
      *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_2;
      *(undefined1 *)(param_1 + 0xd) = 0;
      return;
    }
    uVar1 = 8;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 4) + -1;
  }
  *(undefined1 *)(param_1 + 0xd) = uVar1;
  *(undefined1 *)(param_1 + 0xc) = uVar1;
  return;
}


