// 600d32ee  FUN_600d32ee  size=60 bytes
// --- callers ---
//   60055a28 FUN_60055a28
//   60055e28 FUN_60055e28
//   60055f40 FUN_60055f40
// --- callees ---
//   600d1692 FUN_600d1692
//   600d16ae FUN_600d16ae


undefined4 FUN_600d32ee(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (((param_1 == (undefined4 *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    uVar1 = 3;
  }
  else {
    *(undefined4 *)(param_3 + 0xc) = 0;
    *(undefined1 *)(param_3 + 0x20) = 1;
    FUN_600d1692(param_1[2]);
    uVar1 = (**(code **)(param_1[0xb4] + 0x14))(*param_1,param_2,param_3);
    FUN_600d16ae(param_1[2]);
  }
  return uVar1;
}


