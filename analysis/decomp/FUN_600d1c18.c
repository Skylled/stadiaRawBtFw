// 600d1c18  FUN_600d1c18  size=58 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   600558b8 FUN_600558b8


undefined4
FUN_600d1c18(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,short param_6,
            undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  if ((((param_5 == 0) || (param_6 == 0)) || (param_1 == 0)) || (*(int *)(param_1 + 0xc) == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_600558b8(param_1,0x21,param_3,param_4 << 8,
                         (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30) + 2) |
                         param_2 << 8,param_6,param_5,param_7,param_8);
  }
  return uVar1;
}


