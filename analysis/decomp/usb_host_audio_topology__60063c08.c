// 60063c08  usb_host_audio_topology__60063c08  size=72 bytes
// src: usb_host_audio_topology.cc
// --- callers ---
//   600d5e24 FUN_600d5e24
// --- callees ---
//   600d5cbe FUN_600d5cbe
//   600d5c6a FUN_600d5c6a
//   6010165c FUN_6010165c
//   600d5c16 FUN_600d5c16
//   600d5cc4 FUN_600d5cc4


/* src: usb_host_audio_topology.cc */

void usb_host_audio_topology__60063c08(undefined4 *param_1)

{
  int iVar1;
  
  if ((((*(char *)((int)param_1 + 5) != '\0') && (iVar1 = FUN_600d5c16(), iVar1 == 0)) &&
      (iVar1 = FUN_600d5c6a(param_1), iVar1 == 0)) &&
     (((iVar1 = FUN_600d5cbe(param_1), iVar1 == 0 && (iVar1 = FUN_600d5cc4(param_1), iVar1 != 0)) &&
      (*(byte *)*param_1 < (byte)(((byte *)*param_1)[4] + 5))))) {
    FUN_6010165c(0x28,DAT_60063c54,0x1ab,DAT_60063c50);
    return;
  }
  return;
}


