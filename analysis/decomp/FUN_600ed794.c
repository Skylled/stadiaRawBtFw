// 600ed794  FUN_600ed794  size=148 bytes
// --- callers ---
// --- callees ---
//   600ed656 FUN_600ed656
//   600ed12a FUN_600ed12a


uint FUN_600ed794(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_r2;
  ulonglong uVar3;
  
  uVar3 = FUN_600ed656(param_2);
  uVar1 = (uint)(uVar3 >> 0x20);
  if ((int)uVar3 != 0) {
    if (uVar3 < 0x8000000000) {
      uVar1 = FUN_600ed12a(param_1,uVar1 & 0xff,extraout_r2,param_4);
      return uVar1;
    }
    if (uVar3 < 0x80000000000) {
      uVar1 = (uVar1 & 0xfff) >> 6 | 0xc0;
    }
    else {
      if (uVar3 < 0x1000000000000) {
        uVar1 = (uVar1 & 0x1ffff) >> 0xc | 0xe0;
      }
      else {
        if (0x10ffffffffffff < uVar3) {
          return 0;
        }
        iVar2 = FUN_600ed12a(param_1,(uVar1 & 0x3fffff) >> 0x12 | 0xf0);
        if (iVar2 == 0) {
          return 0;
        }
        uVar1 = (param_2 & 0x3ffff) >> 0xc | 0x80;
      }
      iVar2 = FUN_600ed12a(param_1,uVar1);
      if (iVar2 == 0) {
        return 0;
      }
      uVar1 = (param_2 & 0xfff) >> 6 | 0x80;
    }
    iVar2 = FUN_600ed12a(param_1,uVar1);
    if (iVar2 != 0) {
      iVar2 = FUN_600ed12a(param_1,param_2 & 0x3f | 0x80);
      return (uint)(iVar2 != 0);
    }
  }
  return 0;
}


