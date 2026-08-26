// 600d5a70  FUN_600d5a70  size=64 bytes
// --- callers ---
// --- callees ---
//   60062f9c usb_host_audio__60062f9c
//   600d598e FUN_600d598e


undefined4 FUN_600d5a70(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  if (param_4 == 4) {
    if (param_3 != 0xe) goto LAB_600d5a8c;
    iVar1 = param_2 + 0x110;
  }
  else {
    if ((param_4 != 5) || (param_3 != 0xe)) goto LAB_600d5a8c;
    iVar1 = param_2 + 0x540;
  }
  usb_host_audio__60062f9c(param_2,iVar1,param_3,param_4,param_1,param_2,param_3);
LAB_600d5a8c:
  FUN_600d598e(param_1,param_2,param_3,param_4,param_5);
  return param_1;
}


