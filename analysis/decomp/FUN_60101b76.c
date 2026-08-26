// 60101b76  FUN_60101b76  size=30 bytes
// --- callers ---
//   60075d78 headphone_state_machine__60075d78
//   6005b150 application_state__6005b150
//   6007edf4 recording_pipeline__6007edf4
//   600925bc FUN_600925bc
//   60058600 FUN_60058600
//   600d4902 flash_lut__600d4902
//   60078b4c get_device_data__60078b4c
//   60051b50 stats__60051b50
//   60051240 main__60051240
//   60058754 buffer__60058754
//   60058574 system_tasks__60058574
//   6007ea94 audio_player__6007ea94
//   600834a4 parser__600834a4
//   60068024 mimxrt10xx_flash_memory__60068024
//   6007e82c FUN_6007e82c
//   6005ff5c platform__6005ff5c
//   6005e7e0 bug_report__6005e7e0
//   60067a68 gotham__60067a68
//   60074e6c audio_states__60074e6c
//   6005e200 bug_report__6005e200
//   60079270 FUN_60079270
//   60079778 http_flash_writer__60079778
//   60074c08 FUN_60074c08
//   60069c58 adapter__60069c58
//   60061c48 FUN_60061c48
//   60080cdc gatt_manager_task__60080cdc
//   60060f28 usb_device__60060f28
//   60061684 partition_table__60061684
//   60059d54 sleep_lock__60059d54
//   60067f5c mimxrt10xx_flash_memory__60067f5c
//   600ce2a0 FUN_600ce2a0
//   60074910 FUN_60074910
//   60076ba0 FUN_60076ba0
//   60065eb8 keys__60065eb8
//   6005f450 dcp_encryption_engine__6005f450
//   6005990c sleep_driver__6005990c
//   60074f70 audio_states__60074f70
//   6005d844 trigger_bug_report__6005d844
//   60078be0 FUN_60078be0
//   600d37ac FUN_600d37ac
//   60051120 FUN_60051120
//   600800c0 FUN_600800c0
//   6007ed74 recording_pipeline__6007ed74
//   60060bf4 usb_device__60060bf4
//   60058aa8 hid_input_target__60058aa8
//   6005fe04 io_pin__6005fe04
//   6005b1c0 application_state__6005b1c0
//   6006f660 gotham_16mb_mimxrt10xx_mpu__6006f660
//   600656a0 haptics__600656a0
//   6006044c reset__6006044c
//   600790b4 FUN_600790b4
//   60067c3c gotham__60067c3c
//   600cb2fc key_value_store__600cb2fc
//   6006573c haptics__6006573c
//   6006287c usb_host__6006287c
//   6006b630 sound_codec_wm8904__6006b630
//   60067d14 gotham__60067d14
//   6007edb0 recording_pipeline__6007edb0
//   60068f88 activation_sequence__60068f88
//   60067ddc logging__60067ddc
//   6005ce58 FUN_6005ce58
//   6005f418 dcp_encryption_engine__6005f418
//   60077750 FUN_60077750
//   60065e68 keys__60065e68
//   60078efc FUN_60078efc
//   600db61c FUN_600db61c
//   60081550 FUN_60081550
//   60059f00 snvs__60059f00
//   60075088 audio_states__60075088
//   600666f0 keys__600666f0
//   60060ccc usb_device__60060ccc
//   6007952c http_flash_writer__6007952c
//   600cb460 key_value_store__600cb460
//   6007fcec battery_service__6007fcec
//   600d3ae6 FUN_600d3ae6
//   600cbdf4 buffer__600cbdf4
//   60068f04 activation_sequence__60068f04
//   6006c340 remote_device_db__6006c340
//   6005e2a0 FUN_6005e2a0
//   60067b50 gotham__60067b50
//   60058b68 FUN_60058b68
//   60067e8c flash_memory__60067e8c
// --- callees ---
//   6013d258 thunk_EXT_FUN_0000b50a


void FUN_60101b76(int param_1,int param_2)

{
  int iVar1;
  
  for (iVar1 = 0;
      (*(int *)(param_1 + 4) - *(int *)(param_1 + 8) != iVar1 &&
      (*(char *)(param_2 + iVar1) != '\0')); iVar1 = iVar1 + 1) {
  }
  thunk_EXT_FUN_0000b50a();
  return;
}


