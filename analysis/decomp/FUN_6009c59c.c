// 6009c59c  FUN_6009c59c  size=308 bytes
// --- callers ---
//   6009c6d8 FUN_6009c6d8
//   6009c71c FUN_6009c71c
//   600f1334 FUN_600f1334
//   6009c9d4 FUN_6009c9d4
// --- callees ---
//   6009f990 FUN_6009f990
//   6009c01c FUN_6009c01c
//   6009e6c0 FUN_6009e6c0
//   6009eb9c FUN_6009eb9c
//   600b0cd4 FUN_600b0cd4
//   600f1592 FUN_600f1592
//   6009c240 FUN_6009c240
//   6009bfb0 FUN_6009bfb0


undefined4 FUN_6009c59c(char param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  pbVar1 = DAT_6009c6d0;
  if (*(short *)(DAT_6009c6d0 + 0xea) == -1) {
    uVar3 = 0x60;
  }
  else {
    uVar3 = *(undefined2 *)(DAT_6009c6d0 + 0xea);
  }
  if (*(short *)(DAT_6009c6d0 + 0xec) == -1) {
    uVar4 = 0x30;
  }
  else {
    uVar4 = *(undefined2 *)(DAT_6009c6d0 + 0xec);
  }
  if (param_1 == '\0') {
    *DAT_6009c6d0 = *DAT_6009c6d0 & 0xbf;
    pbVar1[0xf0] = 0;
    pbVar1[0xf1] = 0;
    pbVar1[0xf2] = 0;
    pbVar1[0xf3] = 0;
    pbVar1[0xf6] = pbVar1[0xf6] & 0xfd;
    if ((*pbVar1 & 0xf0) == 0) {
      FUN_600f1592();
    }
  }
  else {
    if ((*DAT_6009c6d0 & 0x40) != 0) {
      return 1;
    }
    if (param_2 != 0) {
      *(int *)(DAT_6009c6d4 + 0x9c0) = param_2;
    }
    if (((pbVar1[0xf7] != 0) && (iVar2 = FUN_6009c240(), iVar2 != 0)) && ((*pbVar1 & 0xf0) == 0)) {
      iVar2 = FUN_6009eb9c(8);
      if (iVar2 == 0) {
        return 0;
      }
      FUN_6009c01c();
      *pbVar1 = *pbVar1 | 0x40;
      pbVar1[0xf6] = pbVar1[0xf6] | 2;
      FUN_6009bfb0(1);
      *(undefined1 *)(DAT_6009c6d4 + 0x8dc) = 0;
      FUN_6009f990(2);
      FUN_600b0cd4(0,uVar3,uVar4,pbVar1[0x164],1);
      pbVar1[0xd] = 1;
      FUN_6009e6c0();
    }
  }
  return 1;
}


