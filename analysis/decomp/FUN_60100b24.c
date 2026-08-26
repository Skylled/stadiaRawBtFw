// 60100b24  FUN_60100b24  size=20 bytes
// --- callers ---
//   60100b6a FUN_60100b6a
//   60100b96 FUN_60100b96
//   600cb460 key_value_store__600cb460
//   60100d98 FUN_60100d98
//   600cb598 key_value_store__600cb598
//   600cb6fc key_value_store__600cb6fc
//   60100c48 FUN_60100c48
// --- callees ---


uint FUN_60100b24(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = param_2 - param_1 * ((int)param_2 / param_1);
  if (iVar1 != 0) {
    param_2 = (param_2 + param_1) - iVar1 & 0xffff;
  }
  return param_2;
}


