// 600a943c  FUN_600a943c  size=312 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600aa3cc FUN_600aa3cc
//   600a9234 FUN_600a9234
//   600d9290 FUN_600d9290
//   600d92fc FUN_600d92fc
//   600d92f8 FUN_600d92f8
//   600d9306 FUN_600d9306
//   6006ddd8 FUN_6006ddd8
//   600aa340 FUN_600aa340


void FUN_600a943c(byte param_1,byte *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int local_c;
  
  iVar3 = (uint)param_1 * 0x34 + 0xa0 + DAT_600a9574;
  *(ushort *)(iVar3 + 0x18) = (ushort)*param_2;
  sVar1 = (ushort)param_2[2] * 0x100 + (ushort)param_2[1];
  if ((sVar1 != 0xc35) && (sVar1 != 0)) {
    for (local_c = FUN_600d92f8(iVar3 + 0xc); local_c != 0; local_c = FUN_600d92fc(local_c)) {
      pbVar4 = (byte *)(local_c + 8 + (uint)*(ushort *)(local_c + 4));
      if ((ushort)((ushort)pbVar4[1] * 0x100 + (ushort)*pbVar4) == sVar1) {
        FUN_600d9290(iVar3 + 0xc,local_c);
        FUN_6006ddd8(local_c,DAT_600a9578,0x722);
        break;
      }
    }
    iVar2 = FUN_600d9306(iVar3 + 0xc);
    if (iVar2 == 0) {
      FUN_600aa340(iVar3 + 0x1c,param_1 + 0x2c,8);
    }
    else {
      FUN_600aa3cc(iVar3 + 0x1c);
    }
  }
  FUN_600a9234(param_1,0);
  return;
}


