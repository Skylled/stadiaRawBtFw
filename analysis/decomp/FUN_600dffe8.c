// 600dffe8  FUN_600dffe8  size=70 bytes
// --- callers ---
//   60062e00 FUN_60062e00
//   600d54dc FUN_600d54dc
//   6005b8dc application_state__6005b8dc
//   6006384c FUN_6006384c
//   600619bc usb_configuration_handler__600619bc
//   600d5512 FUN_600d5512
//   6005ad50 FUN_6005ad50
//   60062f9c usb_host_audio__60062f9c
//   600d3d9a FUN_600d3d9a
// --- callees ---
//   6013d358 thunk_EXT_FUN_0000ab36
//   6013d320 thunk_EXT_FUN_0000ab42
//   600dff98 FUN_600dff98
//   6013cfe8 thunk_EXT_FUN_0000ab28


char FUN_600dffe8(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  undefined1 auStack_28 [4];
  char local_24;
  undefined1 auStack_20 [8];
  undefined1 auStack_18 [8];
  
  thunk_EXT_FUN_0000ab28(auStack_28,param_1 + 0x1c);
  while( true ) {
    cVar1 = local_24;
    if (local_24 == '\0') {
      return '\0';
    }
    piVar2 = (int *)thunk_EXT_FUN_0000ab36(auStack_28);
    if (*piVar2 == param_2) break;
    thunk_EXT_FUN_0000ab28(auStack_20,auStack_28);
    FUN_600dff98(auStack_18,param_1,auStack_20);
    thunk_EXT_FUN_0000ab42(auStack_28,auStack_18);
  }
  return cVar1;
}


