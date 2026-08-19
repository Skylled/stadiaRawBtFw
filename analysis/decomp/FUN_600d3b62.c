// 600d3b62  FUN_600d3b62  size=30 bytes
// --- callers ---
//   6005a4cc device_info__6005a4cc
// --- callees ---


void FUN_600d3b62(byte *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = param_1;
  while( true ) {
    pbVar3 = pbVar2;
    if (pbVar3 == param_1 + param_2) {
      return;
    }
    bVar1 = *pbVar3;
    if (bVar1 == 0) break;
    pbVar2 = pbVar3 + 1;
    if (bVar1 - 0x41 < 0x1a) {
      *pbVar3 = bVar1 + 0x20;
    }
  }
  return;
}


