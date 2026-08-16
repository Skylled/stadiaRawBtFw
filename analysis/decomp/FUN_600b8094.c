// 600b8094  FUN_600b8094  size=340 bytes
// --- callers ---
//   600b7800 FUN_600b7800
// --- callees ---
//   600f8290 FUN_600f8290
//   600b81ec FUN_600b81ec
//   6006ddd8 FUN_6006ddd8


void FUN_600b8094(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  
  if (*(char *)(param_1 + 0x11f) != '\x03') {
    pbVar6 = (byte *)((uint)*(ushort *)(param_2 + 2) + (uint)*(ushort *)(param_2 + 4) + param_2 + 6)
    ;
    bVar1 = *pbVar6;
    bVar2 = pbVar6[1];
    *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + -2;
    uVar4 = FUN_600f8290(param_2);
    if ((ushort)((ushort)bVar2 * 0x100 + (ushort)bVar1) != uVar4) {
      FUN_6006ddd8(param_2,DAT_600b81e8,0x51b);
      return;
    }
  }
  pbVar6 = (byte *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
  uVar3 = (ushort)pbVar6[1] * 0x100 + (ushort)*pbVar6;
  *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + -2;
  *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + 2;
  if ((uVar3 & 1) == 0) {
    bVar1 = (byte)((int)(uint)uVar3 >> 1) & 0x3f;
    if ((bVar1 != *(byte *)(param_1 + 0xb2)) && (*(int *)(param_1 + 0xc0) != 0)) {
      FUN_6006ddd8(*(undefined4 *)(param_1 + 0xc0),DAT_600b81e8,0x545);
      *(undefined4 *)(param_1 + 0xc0) = 0;
    }
    *(byte *)(param_1 + 0xb2) = bVar1 + 1 & 0x3f;
    iVar5 = FUN_600b81ec(param_1,param_2,uVar3);
    if ((iVar5 == 0) && (*(int *)(param_1 + 0xc0) != 0)) {
      FUN_6006ddd8(*(undefined4 *)(param_1 + 0xc0),DAT_600b81e8,0x551);
      *(undefined4 *)(param_1 + 0xc0) = 0;
    }
  }
  else {
    FUN_6006ddd8(param_2,DAT_600b81e8,0x52c);
  }
  return;
}


