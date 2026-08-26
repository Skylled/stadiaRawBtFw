// 601017fc  FUN_601017fc  size=28 bytes
// --- callers ---
//   60077668 FUN_60077668
//   600d5874 FUN_600d5874
//   60080b24 gatt_manager_task__60080b24
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
//   6005bc74 FUN_6005bc74
//   60077140 FUN_60077140
//   600765a4 FUN_600765a4
//   60079e28 FUN_60079e28
//   600776f8 FUN_600776f8
//   60060b64 uart__60060b64
//   600723b4 FUN_600723b4
//   60061e98 FUN_60061e98
//   60060f84 usb_device__60060f84
//   600648b0 usb_host_hid__600648b0
//   6007ad34 usb_audio_send__6007ad34
//   600587fc FUN_600587fc
//   6005fcc0 FUN_6005fcc0
//   600ee142 FUN_600ee142
//   600715fc FUN_600715fc
//   600d89ec adapter__600d89ec
//   6007f540 receiver__6007f540
//   60062e28 FUN_60062e28
//   600650dc FUN_600650dc
//   6007eb8c FUN_6007eb8c
//   60063a24 FUN_60063a24
//   600d4ec8 FUN_600d4ec8
//   600df30c FUN_600df30c
//   6007b1b8 synapse_audio_processor__6007b1b8
//   6005cd20 FUN_6005cd20
// --- callees ---
//   600c9de4 queue__600c9de4


void FUN_601017fc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x50) == 0) {
    uVar1 = queue__600c9de4(1,0,0,param_1,3,param_2);
    *(undefined4 *)(param_1 + 0x50) = uVar1;
  }
  return;
}


