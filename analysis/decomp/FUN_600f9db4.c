// 600f9db4  FUN_600f9db4  size=60 bytes
// --- callers ---
//   600b6d30 FUN_600b6d30
//   600b7db8 FUN_600b7db8
//   600f832a FUN_600f832a
//   600f8450 FUN_600f8450
//   600f8664 FUN_600f8664
//   600b6900 FUN_600b6900
//   600b842c FUN_600b842c
//   600b7b48 FUN_600b7b48
// --- callees ---
//   600bc00c FUN_600bc00c
//   600f9906 FUN_600f9906


void FUN_600f9db4(ushort *param_1)

{
  ushort uVar1;
  code *pcVar2;
  
  uVar1 = *param_1;
  if (0x3f < uVar1) {
    pcVar2 = *(code **)(*(int *)(param_1 + 0xaa) + 0x1c);
    FUN_600f9906(param_1);
    FUN_600bc00c(param_1);
    (*pcVar2)(uVar1,0);
  }
  return;
}


