// 60099bb8  FUN_60099bb8  size=78 bytes
// --- callers ---
//   600a96d8 FUN_600a96d8
//   600f2378 FUN_600f2378
// --- callees ---
//   60098f34 FUN_60098f34
//   60099c0c FUN_60099c0c
//   600f033a FUN_600f033a


void FUN_60099bb8(undefined4 param_1,undefined2 param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = FUN_60098f34(param_2);
  if (bVar1 < 4) {
    iVar2 = (uint)bVar1 * 0x14c + 0x110 + DAT_60099c08;
    FUN_600f033a(iVar2,1);
    FUN_60099c0c(iVar2);
  }
  return;
}


