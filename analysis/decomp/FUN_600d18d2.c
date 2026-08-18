// 600d18d2  FUN_600d18d2  size=56 bytes
// --- callers ---
//   600d19ea FUN_600d19ea
//   600d1a62 FUN_600d1a62
// --- callees ---


undefined4 FUN_600d18d2(undefined4 *param_1,ushort *param_2,byte *param_3)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  
  while( true ) {
    uVar2 = *param_2;
    if (uVar2 < 9) {
      return 1;
    }
    pbVar3 = (byte *)*param_1;
    if ((pbVar3[1] == 4) && (*param_3 != pbVar3[3])) {
      *param_3 = pbVar3[3];
      return 0;
    }
    bVar1 = *pbVar3;
    if (uVar2 < bVar1) {
      return 1;
    }
    if (bVar1 == 0) break;
    *param_2 = uVar2 - bVar1;
    *param_1 = pbVar3 + bVar1;
  }
  return 1;
}


