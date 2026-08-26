// 600d84f2  FUN_600d84f2  size=38 bytes
// --- callers ---
//   600d8518 FUN_600d8518
// --- callees ---
//   600d84ce FUN_600d84ce
//   6013cef8 thunk_EXT_FUN_0000737c


uint FUN_600d84f2(undefined4 param_1,char param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = FUN_600d84ce(param_1,param_2 + '@',param_3 >> 8 | (param_3 & 0xff) << 8,200);
  if ((uVar1 & 0xff) == 0) {
    thunk_EXT_FUN_0000737c(5);
  }
  return uVar1;
}


