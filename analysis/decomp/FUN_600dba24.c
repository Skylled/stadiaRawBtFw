// 600dba24  FUN_600dba24  size=70 bytes
// --- callers ---
//   6007a504 usb_audio_receive__6007a504
//   6007a62c usb_audio_receive__6007a62c
// --- callees ---
//   600db9fa FUN_600db9fa


int FUN_600dba24(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  iVar4 = 0;
  local_18 = 0;
  uStack_14 = param_2;
  uStack_10 = param_3;
  while( true ) {
    uVar2 = param_1[1];
    if (uVar2 == 0) {
      return iVar4;
    }
    uVar3 = param_1[3] - *param_1;
    if (uVar3 <= uVar2) {
      uVar2 = uVar3;
    }
    iVar1 = FUN_600db9fa(&local_18,*param_1 + param_1[2],uVar2);
    if (iVar1 == 0) break;
    iVar4 = iVar4 + iVar1;
    *param_1 = (*param_1 + iVar1) - param_1[3] * ((uint)(*param_1 + iVar1) / (uint)param_1[3]);
    param_1[1] = param_1[1] - iVar1;
  }
  return iVar4;
}


