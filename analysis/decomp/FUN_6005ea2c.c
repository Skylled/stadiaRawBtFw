// 6005ea2c  FUN_6005ea2c  size=166 bytes
// --- callers ---
//   6005f8c0 FUN_6005f8c0
// --- callees ---
//   60071870 FUN_60071870
//   6005e904 FUN_6005e904
//   6013cf40 thunk_EXT_FUN_00007d10
//   600cc8f8 FUN_600cc8f8
//   600cc984 FUN_600cc984
//   600d46fe FUN_600d46fe
//   6013cf88 thunk_EXT_FUN_0000b4cc
//   6010135a FUN_6010135a
//   600d45e8 FUN_600d45e8


undefined4 FUN_6005ea2c(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  
  iVar2 = FUN_60071870();
  if (iVar2 == 0) {
    uVar3 = 7;
  }
  else {
    iVar2 = thunk_EXT_FUN_0000b4cc(DAT_6005ead4,0);
    pbVar1 = DAT_6005ead8;
    if (iVar2 == 0) {
      uVar3 = 0xd;
    }
    else {
      DataMemoryBarrier(0x1b);
      if ((-1 < (int)((uint)*DAT_6005ead8 << 0x1f)) &&
         (iVar2 = FUN_600cc8f8(DAT_6005ead8), iVar2 != 0)) {
        FUN_600d46fe(DAT_6005eadc);
        FUN_600cc984(pbVar1);
      }
      pbVar1 = DAT_6005eae0;
      DataMemoryBarrier(0x1b);
      if ((-1 < (int)((uint)*DAT_6005eae0 << 0x1f)) &&
         (iVar2 = FUN_600cc8f8(DAT_6005eae0), iVar2 != 0)) {
        FUN_600d45e8(DAT_6005eae8,DAT_6005eae4,1);
        FUN_600cc984(pbVar1);
      }
      pbVar1 = DAT_6005eaec;
      DataMemoryBarrier(0x1b);
      bVar4 = *DAT_6005eaec & 1;
      if (((*DAT_6005eaec & 1) == 0) && (iVar2 = FUN_600cc8f8(DAT_6005eaec), iVar2 != 0)) {
        FUN_6010135a(DAT_6005eaf4,DAT_6005eaf0,bVar4,bVar4,DAT_6005eadc,DAT_6005eae8);
        FUN_600cc984(pbVar1);
      }
      uVar3 = FUN_6005e904(DAT_6005eaf4);
      thunk_EXT_FUN_00007d10(DAT_6005ead4);
    }
  }
  return uVar3;
}


