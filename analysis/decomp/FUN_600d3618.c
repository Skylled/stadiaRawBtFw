// 600d3618  FUN_600d3618  size=32 bytes
// --- callers ---
//   6005d714 trigger_bug_report__6005d714
//   600cbebc logger__600cbebc
//   60078fec FUN_60078fec
//   60069b20 adapter__60069b20
//   600cc090 FUN_600cc090
//   6007a2c0 frames__6007a2c0
//   60069a38 adapter__60069a38
//   600df0f0 FUN_600df0f0
//   6007a0b0 usb_audio_receive__6007a0b0
//   600d847c FUN_600d847c
//   600d866a FUN_600d866a
//   6005d160 thermal__6005d160
//   6007a62c usb_audio_receive__6007a62c
//   6005fcc0 FUN_6005fcc0
//   600def9c FUN_600def9c
//   6005990c sleep_driver__6005990c
//   60058754 buffer__60058754
//   6006a21c adapter__6006a21c
//   6007a118 usb_audio_receive__6007a118
//   6007a504 usb_audio_receive__6007a504
//   6005d844 trigger_bug_report__6005d844
// --- callees ---
//   6013cf80 thunk_EXT_FUN_0000714c


int FUN_600d3618(void)

{
  uint uVar1;
  
  uVar1 = thunk_EXT_FUN_0000714c();
  return ((uVar1 % 1000) * 1000 + 500) / 1000 + (uVar1 / 1000) * 1000;
}


