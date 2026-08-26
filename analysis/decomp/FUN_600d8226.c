// 600d8226  FUN_600d8226  size=50 bytes
// --- callers ---
//   6006816c accessory_detect_ts3a227e__6006816c
//   600d8258 FUN_600d8258
// --- callees ---
//   600d81f8 FUN_600d81f8


void FUN_600d8226(int param_1,uint3 param_2)

{
  char cVar1;
  byte bVar2;
  undefined4 uStack_c;
  
  uStack_c = (uint)param_2;
  cVar1 = FUN_600d81f8(param_1,0xb,(int)&uStack_c + 3,200,param_1);
  if (cVar1 == '\0') {
    bVar2 = (byte)(((uStack_c >> 0x18) << 0x1c) >> 0x1f);
    *(byte *)(param_1 + 8) = bVar2;
    if ((uStack_c & 0x6000000) == 0) {
      bVar2 = 0;
    }
    *(byte *)(param_1 + 9) = bVar2;
  }
  return;
}


