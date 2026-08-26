// 600d5252  FUN_600d5252  size=50 bytes
// --- callers ---
//   6007b600 synapse_audio_processor__6007b600
//   60061ed4 usb_device_audio__60061ed4
//   60061fc0 usb_device_audio__60061fc0
// --- callees ---
//   6013cf80 thunk_EXT_FUN_0000714c


bool FUN_600d5252(uint *param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = thunk_EXT_FUN_0000714c();
  uVar2 = ((uVar2 % 1000) * 1000 + 500) / 1000 + (uVar2 / 1000) * 1000;
  bVar1 = param_2 + *param_1 <= uVar2;
  if (bVar1) {
    *param_1 = uVar2;
  }
  return bVar1;
}


