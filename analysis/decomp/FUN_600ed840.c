// 600ed840  FUN_600ed840  size=38 bytes
// --- callers ---
// --- callees ---
//   600ed656 FUN_600ed656
//   600ed22a FUN_600ed22a


undefined4 FUN_600ed840(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined6 uVar3;
  
  if (param_2 < 0x10000) {
    uVar3 = FUN_600ed656(param_2,param_2,param_1,param_4,param_4);
    uVar2 = 0;
    if (((int)uVar3 != 0) &&
       (iVar1 = FUN_600ed22a(extraout_r2,(short)((uint6)uVar3 >> 0x20)), uVar2 = 0, iVar1 != 0)) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


