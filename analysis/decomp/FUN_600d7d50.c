// 600d7d50  FUN_600d7d50  size=28 bytes
// --- callers ---
// --- callees ---
//   600e02f4 FUN_600e02f4
//   600e02f8 FUN_600e02f8


undefined4 FUN_600d7d50(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_600e02f8();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
    FUN_600e02f4(param_1,0);
  }
  return 1;
}


