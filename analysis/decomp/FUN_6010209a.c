// 6010209a  FUN_6010209a  size=14 bytes
// --- callers ---
//   600e93ca FUN_600e93ca
//   600d8a18 FUN_600d8a18
//   600e96c6 FUN_600e96c6
//   60101fde FUN_60101fde
//   600d8a26 FUN_600d8a26
//   600cc8a8 FUN_600cc8a8
//   600e0c5a FUN_600e0c5a
//   60101fc6 FUN_60101fc6
//   600cc824 FUN_600cc824
//   60101c22 FUN_60101c22
//   6007a998 usb_audio_receive__6007a998
//   600e0c4a FUN_600e0c4a
//   600e0c82 FUN_600e0c82
//   60066070 keys__60066070
//   600d3e60 FUN_600d3e60
//   600e9680 FUN_600e9680
//   60065d1c keys__60065d1c
//   600da77c FUN_600da77c
//   600e0c6c FUN_600e0c6c
//   600e0c94 FUN_600e0c94
//   600e9542 FUN_600e9542
//   600cc8f8 FUN_600cc8f8
//   60101fe4 FUN_60101fe4
//   60101fd8 FUN_60101fd8
//   600e9d76 FUN_600e9d76
//   600cc8e0 FUN_600cc8e0
//   60101fcc FUN_60101fcc
//   600867c8 FUN_600867c8
//   60101fd2 FUN_60101fd2
//   6007ea94 audio_player__6007ea94
//   60091d50 FUN_60091d50
//   600e9d5c FUN_600e9d5c
// --- callees ---
//   60051824 exit__60051824
//   600cdc90 FUN_600cdc90


int FUN_6010209a(void)

{
  int iVar1;
  uint extraout_r2;
  code *in_r3;
  int extraout_r3;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  FUN_600cdc90();
  uVar6 = exit__60051824(1);
  if ((extraout_r2 != 0) && (extraout_r3 != 0)) {
    uVar5 = 0;
    uVar2 = extraout_r2;
    while (uVar3 = uVar2, uVar5 < uVar3) {
      uVar2 = uVar5 + uVar3 >> 1;
      iVar4 = uVar2 * extraout_r3 + (int)((ulonglong)uVar6 >> 0x20);
      iVar1 = (*in_r3)((int)uVar6,iVar4);
      if (-1 < iVar1) {
        if (iVar1 == 0) {
          return iVar4;
        }
        uVar5 = uVar2 + 1;
        uVar2 = uVar3;
      }
    }
  }
  return 0;
}


