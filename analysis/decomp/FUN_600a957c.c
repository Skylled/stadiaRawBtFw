// 600a957c  FUN_600a957c  size=338 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600aa3cc FUN_600aa3cc
//   600a9234 FUN_600a9234
//   600d9290 FUN_600d9290
//   600d92fc FUN_600d92fc
//   600f2532 FUN_600f2532
//   600d92f8 FUN_600d92f8
//   600d9306 FUN_600d9306
//   6006ddd8 FUN_6006ddd8
//   600aa340 FUN_600aa340


void FUN_600a957c(byte param_1,byte *param_2,short param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 local_10;
  int local_c;
  
  iVar3 = (uint)param_1 * 0x34 + 0xa0 + DAT_600a96d0;
  local_10 = 0;
  *(ushort *)(iVar3 + 0x18) = (ushort)*param_2;
  uVar1 = (ushort)param_2[2] * 0x100 + (ushort)param_2[1];
  if (((uVar1 != 0xc03) && (uVar1 != 0xc35)) && (uVar1 != 0)) {
    for (local_c = FUN_600d92f8(iVar3 + 0xc); local_c != 0; local_c = FUN_600d92fc(local_c)) {
      pbVar4 = (byte *)(local_c + 8 + (uint)*(ushort *)(local_c + 4));
      if ((ushort)((ushort)pbVar4[1] * 0x100 + (ushort)*pbVar4) == uVar1) {
        FUN_600d9290(iVar3 + 0xc,local_c);
        if ((((uVar1 & 0xfc00) == 0xfc00) || (uVar1 == 0x2018)) || (uVar1 == 0x2017)) {
          local_10 = *(undefined4 *)(local_c + 8);
        }
        FUN_6006ddd8(local_c,DAT_600a96d4,0x781);
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
  FUN_600f2532(uVar1,param_2 + 3,param_3 + -3,local_10,param_1);
  FUN_600a9234(param_1,0);
  return;
}


