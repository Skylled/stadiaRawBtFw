// 600d1ba0  FUN_600d1ba0  size=60 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   600558b8 FUN_600558b8


undefined4
FUN_600d1ba0(int param_1,uint param_2,undefined4 param_3,int param_4,int param_5,short param_6,
            undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x4c) == 0)) {
    uVar1 = 3;
  }
  else if ((param_5 == 0) || (param_6 == 0)) {
    uVar1 = 4;
  }
  else {
    uVar1 = FUN_600558b8(param_1,0xa1,param_3,param_2 | param_4 << 8,
                         (uint)*(byte *)(*(int *)(param_1 + 0x4c) + 3) << 8,param_6,param_5,param_7,
                         param_8);
  }
  return uVar1;
}


