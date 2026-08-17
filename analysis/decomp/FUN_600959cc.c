// 600959cc  FUN_600959cc  size=202 bytes
// --- callers ---
// --- callees ---
//   600ff1f6 FUN_600ff1f6
//   600fef54 FUN_600fef54
//   600c6ad0 FUN_600c6ad0
//   600efa82 FUN_600efa82
//   600ff09c FUN_600ff09c
//   600ff21c FUN_600ff21c
//   600ff482 FUN_600ff482
//   600ff3a2 FUN_600ff3a2
//   600fefac FUN_600fefac
//   600ff31a FUN_600ff31a
//   600ff404 FUN_600ff404
//   600fefd8 FUN_600fefd8


undefined4 FUN_600959cc(ushort *param_1)

{
  int iVar1;
  
  switch(*param_1) {
  case 0x1e00:
    FUN_600c6ad0(DAT_60095adc,param_1);
    break;
  case 0x1e01:
    FUN_600fefac(DAT_60095adc,param_1);
    break;
  case 0x1e02:
    FUN_600fefd8(DAT_60095adc,param_1);
    break;
  case 0x1e03:
    FUN_600ff09c(DAT_60095adc,param_1);
    break;
  case 0x1e04:
    FUN_600ff21c(DAT_60095adc,param_1);
    break;
  case 0x1e05:
  case 0x1e06:
  case 0x1e07:
  case 0x1e08:
  case 0x1e09:
  case 0x1e0a:
    iVar1 = FUN_600efa82(DAT_60095adc,param_1[3]);
    if (iVar1 != 0) {
      (**(code **)(DAT_60095ae4 + (DAT_60095ae0 + (uint)*param_1) * 4))(iVar1,param_1);
    }
    break;
  case 0x1e0b:
    FUN_600ff1f6(DAT_60095adc,param_1);
    break;
  case 0x1e0c:
    FUN_600ff31a(DAT_60095adc,param_1);
    break;
  case 0x1e0d:
    FUN_600ff3a2(DAT_60095adc,param_1);
    break;
  case 0x1e0e:
    FUN_600ff404(DAT_60095adc,param_1);
    break;
  case 0x1e0f:
    FUN_600ff482(DAT_60095adc,param_1);
    break;
  case 0x1e10:
    FUN_600fef54(DAT_60095adc);
  }
  return 1;
}


