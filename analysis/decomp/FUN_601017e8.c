// 601017e8  FUN_601017e8  size=20 bytes
// --- callers ---
//   60077668 FUN_60077668
//   60074ef4 FUN_60074ef4
//   600d4a7e FUN_600d4a7e
//   6005bc74 FUN_6005bc74
//   600d4724 FUN_600d4724
//   600765a4 FUN_600765a4
//   60078340 firmware_image_upload__60078340
//   60075b18 headphone_state_machine__60075b18
//   60079e28 FUN_60079e28
//   6005f9a8 FUN_6005f9a8
//   60060b64 uart__60060b64
//   6005ee1c FUN_6005ee1c
//   600d9b5c FUN_600d9b5c
//   6007fbe4 FUN_6007fbe4
//   60080278 FUN_60080278
//   6007ad34 usb_audio_send__6007ad34
//   600804c0 FUN_600804c0
//   600d45e8 FUN_600d45e8
//   600587fc FUN_600587fc
//   600769ec FUN_600769ec
//   6005fcc0 FUN_6005fcc0
//   600761d4 FUN_600761d4
//   60063a24 FUN_60063a24
//   6005f3e0 FUN_6005f3e0
//   6007b1b8 synapse_audio_processor__6007b1b8
// --- callees ---
//   601007bc FUN_601007bc


void FUN_601017e8(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x50) == 0) {
    uVar1 = FUN_601007bc(1,param_1);
    *(undefined4 *)(param_1 + 0x50) = uVar1;
  }
  return;
}


