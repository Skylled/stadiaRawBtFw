// 600926a0  FUN_600926a0  size=20 bytes
// --- callers ---
//   600d8df2 FUN_600d8df2
//   6006b290 usb_port_controller_tusb320__6006b290
//   600d9a56 FUN_600d9a56
// --- callees ---


undefined4 FUN_600926a0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  
  iVar1 = DAT_600926b4;
  if (*(int *)(DAT_600926b4 + 0x58) != 0) {
    if (param_1 == 0) {
      uVar2 = 3;
    }
    else {
      uVar2 = 0;
      DataMemoryBarrier(0x1b);
      *(undefined1 *)(param_1 + 8) = 1;
      DataMemoryBarrier(0x1b);
      uStack_14 = param_1 & 0xffffff00;
      uStack_10 = param_1;
      uStack_c = param_4;
      thunk_EXT_FUN_00006a74(*(undefined4 *)(iVar1 + 0xb0),&uStack_14,0xffffffff,0,iVar1);
    }
    return uVar2;
  }
  return 9;
}


