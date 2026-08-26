// 600d6866  FUN_600d6866  size=80 bytes
// --- callers ---
//   600644dc usb_host_audio_topology__600644dc
// --- callees ---
//   600d67e8 FUN_600d67e8
//   6013d068 thunk_EXT_FUN_0000b52e
//   60101d22 FUN_60101d22
//   600641a8 usb_host_audio_topology__600641a8
//   600d5e4a FUN_600d5e4a
//   600d6672 FUN_600d6672


undefined4 * FUN_600d6866(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 extraout_r3;
  int iVar3;
  int iVar4;
  int local_1c;
  undefined4 uStack_18;
  
  puVar2 = param_1;
  local_1c = param_2;
  uStack_18 = param_3;
  FUN_600d5e4a();
  FUN_600d67e8(&local_1c,param_2,param_3,extraout_r3,puVar2);
  iVar4 = local_1c + 4;
  for (iVar3 = *(int *)(local_1c + 0xc); iVar1 = local_1c, iVar4 != iVar3;
      iVar3 = FUN_60101d22(iVar3)) {
    usb_host_audio_topology__600641a8(param_2,iVar3 + 0x10,*param_1);
  }
  if (local_1c != 0) {
    FUN_600d6672(local_1c,*(undefined4 *)(local_1c + 8));
    puVar2 = (undefined4 *)thunk_EXT_FUN_0000b52e(iVar1,0x18);
    return puVar2;
  }
  return param_1;
}


