// 600ad9d8  FUN_600ad9d8  size=142 bytes
// --- callers ---
//   600ad868 FUN_600ad868
// --- callees ---
//   600f41d0 FUN_600f41d0
//   600f6516 FUN_600f6516
//   600acf50 FUN_600acf50
//   6006ddd8 FUN_6006ddd8


void FUN_600ad9d8(undefined4 param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
  if (*(short *)(param_2 + 2) != 0) {
    sVar2 = *(short *)(param_2 + 2) + -1;
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
    if ((bVar1 & 0x3f) < 0x1f) {
      if (bVar1 == 0xd2) {
        FUN_600f41d0(param_1,param_2);
      }
      else if ((bVar1 & 1) == 0) {
        FUN_600f6516(param_1,bVar1,sVar2,pbVar3);
      }
      else {
        FUN_600acf50(param_1,bVar1,sVar2,pbVar3);
      }
    }
  }
  FUN_6006ddd8(param_2,DAT_600ada68,0x445);
  return;
}


