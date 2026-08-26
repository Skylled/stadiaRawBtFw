// 600d86ba  FUN_600d86ba  size=104 bytes
// --- callers ---
//   600d8778 FUN_600d8778
// --- callees ---
//   600d8636 FUN_600d8636
//   600d84ce FUN_600d84ce
//   600d866a FUN_600d866a
//   6013cef8 thunk_EXT_FUN_0000737c


uint FUN_600d86ba(undefined4 param_1,ushort param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = (uint)param_2;
  uStack_10 = param_3;
  uVar1 = FUN_600d8636(param_1,0,(int)&uStack_14 + 2,param_4,param_1);
  if ((uVar1 & 0xff) != 0) {
    return uVar1;
  }
  if ((int)((uStack_14 >> 0x10) << 0x12) < 0) {
    uVar1 = FUN_600d84ce(param_1,0,0x8000,200);
    if ((uVar1 & 0xff) != 0) {
      return uVar1;
    }
    thunk_EXT_FUN_0000737c(5);
    uVar1 = FUN_600d84ce(param_1,0,0x8000,200);
    if ((uVar1 & 0xff) != 0) {
      return uVar1;
    }
    thunk_EXT_FUN_0000737c(5);
    uVar1 = FUN_600d866a(param_1,0x2000,0,4000);
    if ((uVar1 & 0xff) != 0) {
      return uVar1;
    }
  }
  return 0;
}


