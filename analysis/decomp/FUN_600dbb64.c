// 600dbb64  FUN_600dbb64  size=50 bytes
// --- callers ---
//   6007a504 usb_audio_receive__6007a504
// --- callees ---
//   600dba6a FUN_600dba6a


undefined4 FUN_600dbb64(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 local_c;
  
  if (*(uint *)(param_1 + 0x950) < 4) {
    uVar1 = 9;
  }
  else {
    local_c = **(undefined4 **)(param_1 + 0x94c);
    local_14 = param_2;
    uStack_10 = param_3;
    uVar1 = FUN_600dba6a(param_1 + 0x9bc,param_1 + 0x19d2,&local_c,&local_14,param_1);
  }
  return uVar1;
}


