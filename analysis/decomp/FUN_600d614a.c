// 600d614a  FUN_600d614a  size=126 bytes
// --- callers ---
//   600644dc usb_host_audio_topology__600644dc
// --- callees ---
//   6006408c usb_host_audio_topology__6006408c
//   60063dec FUN_60063dec
//   600d6028 FUN_600d6028
//   600d5c90 FUN_600d5c90
//   600d5c1c FUN_600d5c1c
//   600d5fc2 FUN_600d5fc2


int FUN_600d614a(int param_1,undefined1 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 local_21 [5];
  undefined1 *local_1c;
  int iStack_18;
  
  local_21[0] = param_2;
  iVar1 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54),local_21);
  if (*(int *)(param_1 + 0x54) + 4 == iVar1) {
    return 0;
  }
  FUN_60063dec(*(int *)(param_1 + 0x54),local_21);
  iVar1 = FUN_600d5c1c();
  if (iVar1 == 0) {
    return 0;
  }
  usb_host_audio_topology__6006408c(&local_1c,param_1,local_21[0]);
  if (iStack_18 - (int)local_1c == 1) {
    iVar1 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54));
    if (*(int *)(param_1 + 0x54) + 4 != iVar1) {
      FUN_60063dec(*(int *)(param_1 + 0x54),local_1c);
      iVar1 = FUN_600d5c90();
      if (iVar1 != 0) {
        *param_3 = *local_1c;
        goto LAB_600d6190;
      }
    }
  }
  iVar1 = 0;
LAB_600d6190:
  FUN_600d5fc2(&local_1c);
  return iVar1;
}


