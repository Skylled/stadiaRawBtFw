// 60046ccc  FUN_60046ccc  size=174 bytes
// --- callers ---
// --- callees ---
//   60042300 FUN_60042300
//   60047b98 tasks__60047b98


uint FUN_60046ccc(char *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_b4 [4];
  undefined *puStack_b0;
  undefined4 uStack_ac;
  undefined1 *puStack_a8;
  undefined4 uStack_a4;
  int iStack_a0;
  undefined1 uStack_9c;
  undefined1 uStack_9b;
  undefined1 auStack_9a [134];
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 3;
  }
  else {
    if (*param_1 != '\0') {
      FUN_60042300(0xc,*param_2,4,0,PTR_s_audio_60046d80,0,PTR_s_ReceiverBuffer_60046d7c);
    }
    iVar3 = *(int *)(param_1 + 0xc);
    if (iVar3 == 0) {
      uVar1 = func_0x600428b8(*(undefined4 *)(param_1 + 4),*param_2,0x780);
      if ((uVar1 & 0xff) != 0) {
        puStack_b0 = PTR_s_receiver_cc_60046d84;
        uStack_9c = 0;
        uStack_ac = 0x92;
        puStack_a8 = auStack_9a;
        uStack_9b = 0;
        auStack_9a[0] = 0;
        uStack_a4 = 0x80;
        iStack_a0 = iVar3;
        func_0x6004c444(&puStack_a8,PTR_s_Pausing_microphone_receiving_due_60046d88);
        auStack_b4[0] = (undefined1)uVar1;
        uVar2 = func_0x6004c17c(auStack_b4);
        func_0x6004c104(&puStack_a8,uVar2);
        func_0x6004c364(&puStack_b0);
        tasks__60047b98(0xfa);
        return uVar1;
      }
    }
    else if (iVar3 == 1) {
      func_0x6004beb4(*(undefined4 *)(param_1 + 8),*param_2,0x780);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 1;
    }
    uVar1 = 0;
    param_1[0x10] = '\0';
  }
  return uVar1;
}


