// 600d90b6  FUN_600d90b6  size=38 bytes
// --- callers ---
//   600d9230 FUN_600d9230
//   600d9198 FUN_600d9198
// --- callees ---
//   6006d770 FUN_6006d770
//   6006ce90 FUN_6006ce90
//   6006d734 FUN_6006d734


undefined4 FUN_600d90b6(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006d770();
  if (iVar1 == 0xff) {
    iVar1 = FUN_6006d734(param_1);
    if (iVar1 == 0) {
      return 1;
    }
    FUN_6006d770(param_1);
  }
  if (param_2 != 0) {
    FUN_6006ce90();
  }
  return 1;
}


