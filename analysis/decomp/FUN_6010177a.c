// 6010177a  FUN_6010177a  size=32 bytes
// --- callers ---
//   6009267c FUN_6009267c
//   6007b1b8 synapse_audio_processor__6007b1b8
//   6007e784 FUN_6007e784
//   60051240 main__60051240
//   60058574 system_tasks__60058574
//   6007f540 receiver__6007f540
//   6006525c usb_host_worker__6006525c
//   60080cdc gatt_manager_task__60080cdc
//   6007a998 usb_audio_receive__6007a998
//   6007ad34 usb_audio_send__6007ad34
// --- callees ---
//   600cc178 FUN_600cc178
//   6013d2d0 thunk_EXT_FUN_0000713c
//   6013d0e0 thunk_EXT_FUN_0000728c


undefined4 FUN_6010177a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  thunk_EXT_FUN_0000713c();
  uVar1 = FUN_600cc178(param_1,param_2,param_3);
  thunk_EXT_FUN_0000728c();
  return uVar1;
}


