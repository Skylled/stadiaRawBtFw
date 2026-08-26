// 601017b4  FUN_601017b4  size=52 bytes
// --- callers ---
//   6007a254 usb_audio_receive__6007a254
//   6007f454 receiver__6007f454
//   6007e728 audio_player__6007e728
// --- callees ---
//   6010179a FUN_6010179a
//   60101822 FUN_60101822
//   600ca9dc FUN_600ca9dc


undefined4 FUN_601017b4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x58);
  if ((iVar3 == 0) || (iVar1 = FUN_600ca9dc(), iVar3 == iVar1)) {
    uVar2 = 9;
  }
  else {
    iVar3 = FUN_60101822(param_1 + 4,param_2);
    if (iVar3 == 0) {
      uVar2 = 4;
    }
    else {
      FUN_6010179a(param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}


