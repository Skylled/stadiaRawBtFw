// 600d1ea2  FUN_600d1ea2  size=62 bytes
// --- callers ---
//   600648b0 usb_host_hid__600648b0
// --- callees ---
//   600d33b2 FUN_600d33b2
//   600d15c8 FUN_600d15c8


undefined4 FUN_600d1ea2(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *local_1c;
  undefined4 uStack_18;
  
  uVar2 = param_1;
  local_1c = param_2;
  uStack_18 = param_3;
  puVar1 = (undefined4 *)FUN_600d15c8(0x38);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xc;
  }
  else {
    puVar1[1] = param_1;
    puVar1[2] = 0;
    FUN_600d33b2(param_1,8,&local_1c);
    *puVar1 = local_1c;
    FUN_600d33b2(param_1,9,&local_1c,local_1c,uVar2);
    uVar2 = 0;
    puVar1[3] = local_1c;
    *param_2 = (int)puVar1;
  }
  return uVar2;
}


