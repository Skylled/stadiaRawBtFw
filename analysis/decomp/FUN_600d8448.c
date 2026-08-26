// 600d8448  FUN_600d8448  size=52 bytes
// --- callers ---
//   600d8518 FUN_600d8518
// --- callees ---
//   600d4330 FUN_600d4330
//   6013cef8 thunk_EXT_FUN_0000737c


uint FUN_600d8448(undefined4 param_1,int param_2,ushort *param_3)

{
  uint uVar1;
  undefined4 uStack_14;
  ushort *puStack_10;
  
  uStack_14 = param_2;
  puStack_10 = param_3;
  uVar1 = FUN_600d4330(param_1,param_2 + 0x40U & 0xff,(int)&uStack_14 + 2,200,param_1);
  if ((uVar1 & 0xff) == 0) {
    thunk_EXT_FUN_0000737c(5);
    *param_3 = uStack_14._2_2_ << 8 | uStack_14._2_2_ >> 8;
  }
  return uVar1;
}


