// 600d8f64  FUN_600d8f64  size=58 bytes
// --- callers ---
//   6006b290 usb_port_controller_tusb320__6006b290
// --- callees ---
//   600d8f24 FUN_600d8f24
//   600d8e6c FUN_600d8e6c


undefined1 FUN_600d8f64(undefined4 param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_2;
  uStack_10 = param_3;
  cVar1 = FUN_600d8e6c(param_1,9,(int)&uStack_14 + 3,0,param_1);
  if (cVar1 == '\x04') {
    uVar2 = 2;
  }
  else if (cVar1 == '\0') {
    if ((int)((uStack_14 >> 0x18) << 0x1b) < 0) {
      FUN_600d8f24(param_1,9);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}


