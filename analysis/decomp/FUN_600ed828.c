// 600ed828  FUN_600ed828  size=24 bytes
// --- callers ---
//   60091ddc FUN_60091ddc
// --- callees ---
//   600ed12a FUN_600ed12a


undefined4 FUN_600ed828(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 0x100) {
    iVar1 = FUN_600ed12a(param_1,param_2 & 0xff,param_3,param_4,param_4);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


