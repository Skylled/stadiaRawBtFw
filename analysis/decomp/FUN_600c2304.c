// 600c2304  FUN_600c2304  size=86 bytes
// --- callers ---
//   600fb160 FUN_600fb160
//   600faec4 FUN_600faec4
//   600fb0ac FUN_600fb0ac
//   600fb24a FUN_600fb24a
//   600fb1e6 FUN_600fb1e6
//   600fb2ae FUN_600fb2ae
//   600fb110 FUN_600fb110
// --- callees ---


undefined4 FUN_600c2304(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  bVar1 = *(byte *)(param_1 + 0x1fc);
  if ((bVar1 < 0x10) && (bVar1 != 0)) {
    iVar2 = (**(code **)(DAT_600c235c + (uint)bVar1 * 4))(param_1);
    if (iVar2 == 0) {
      uVar3 = 1;
    }
    else {
      iVar2 = (**(code **)(DAT_600c2360 + (uint)bVar1 * 4))(param_1);
      if (iVar2 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


