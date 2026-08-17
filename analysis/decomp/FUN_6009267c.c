// 6009267c  FUN_6009267c  size=28 bytes
// --- callers ---
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
//   60060f28 usb_device__60060f28
//   6006581c haptics_cluster__6006581c
// --- callees ---
//   6010177a FUN_6010177a


uint FUN_6009267c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  if ((*(int *)(DAT_60092698 + 0x58) != 0) ||
     (uVar1 = FUN_6010177a(DAT_60092698,DAT_6009269c,param_1,param_4,param_4), (uVar1 & 0xff) == 0))
  {
    uVar1 = 0;
  }
  return uVar1;
}


