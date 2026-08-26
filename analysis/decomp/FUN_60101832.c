// 60101832  FUN_60101832  size=22 bytes
// --- callers ---
//   600649d4 usb_host_hid__600649d4
//   600ee142 FUN_600ee142
//   600691f4 adapter__600691f4
//   6006988c adapter__6006988c
//   600d69de FUN_600d69de
//   600648b0 usb_host_hid__600648b0
//   60080bcc gatt_manager_task__60080bcc
//   60101760 FUN_60101760
//   600629cc usb_host_audio__600629cc
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74


bool FUN_60101832(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_00006a74(*(undefined4 *)(param_1 + 0x50),0,0,0,param_4);
  return iVar1 == 1;
}


