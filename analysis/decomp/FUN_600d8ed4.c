// 600d8ed4  FUN_600d8ed4  size=80 bytes
// --- callers ---
//   6006b290 usb_port_controller_tusb320__6006b290
// --- callees ---
//   600d8e6c FUN_600d8e6c
//   600d8e2c FUN_600d8e2c


void FUN_600d8ed4(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uVar4 = *(undefined1 *)(param_1 + 0x1c);
  uStack_14 = param_2;
  uStack_10 = param_3;
  cVar3 = FUN_600d8e6c(param_1,9,(int)&uStack_14 + 3,3,param_1);
  if (cVar3 != '\0') goto LAB_600d8efc;
  uVar2 = uStack_14 >> 0x18;
  uVar1 = uStack_14 & 0xc0000000;
  uStack_14 = uStack_14 & 0xc0ffffff;
  if (uVar1 != 0) {
    if (-1 < (int)(uVar2 << 0x19)) {
      uVar4 = 1;
      goto LAB_600d8efc;
    }
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    if (*(char *)(param_1 + 0x181) == '\0') {
      uVar4 = 2;
      goto LAB_600d8efc;
    }
  }
  uVar4 = 0;
LAB_600d8efc:
  FUN_600d8e2c(param_1,uVar4);
  return;
}


