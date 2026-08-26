// 600d6100  FUN_600d6100  size=74 bytes
// --- callers ---
//   6006408c usb_host_audio_topology__6006408c
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   600d6074 FUN_600d6074
//   600d5e14 FUN_600d5e14
//   6013d3d8 thunk_EXT_FUN_0000b4c2


void FUN_600d6100(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int local_24;
  
  iVar2 = param_1;
  local_24 = param_2;
  thunk_EXT_FUN_0000b4c2();
  iVar1 = *(int *)(param_1 + 0x54);
  local_24 = *(int *)(iVar1 + 0xc);
  while (iVar1 + 4 != local_24) {
    *(undefined1 *)(local_24 + 0x1a) = 0;
    FUN_600d5e14(&local_24);
  }
  FUN_600d6074(param_1,param_2,param_3,param_4,iVar2);
  thunk_EXT_FUN_00007d10(param_1);
  return;
}


