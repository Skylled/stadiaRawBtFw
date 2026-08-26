// 600d600a  FUN_600d600a  size=30 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   600d5dc4 FUN_600d5dc4
//   600d5fc2 FUN_600d5fc2


int FUN_600d600a(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_14;
  int iStack_10;
  undefined4 uStack_c;
  
  local_14 = param_2;
  iStack_10 = param_3;
  uStack_c = param_4;
  FUN_600d5dc4(&local_14,param_1,1,param_4,param_1);
  iVar1 = iStack_10 - local_14;
  FUN_600d5fc2(&local_14);
  return iVar1;
}


