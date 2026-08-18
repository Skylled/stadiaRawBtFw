// 600d32a2  FUN_600d32a2  size=76 bytes
// --- callers ---
//   60055d78 FUN_60055d78
//   600558b8 FUN_600558b8
//   6005592c FUN_6005592c
//   60055cfc FUN_60055cfc
//   60055bd8 FUN_60055bd8
//   60055ed0 FUN_60055ed0
//   600d3196 FUN_600d3196
// --- callees ---
//   600d1692 FUN_600d1692
//   600d16ae FUN_600d16ae


undefined4 FUN_600d32a2(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (((param_1 == (undefined4 *)0x0) || (param_2 == 0)) || (param_3 == (undefined4 *)0x0)) {
    uVar1 = 3;
  }
  else {
    *param_3 = 0;
    *(undefined1 *)((int)param_3 + 0x21) = 0;
    param_3[3] = 0;
    *(bool *)(param_3 + 8) = *(char *)param_3[7] < '\0';
    FUN_600d1692(param_1[2]);
    uVar1 = (**(code **)(param_1[0xb4] + 0x10))(*param_1,param_2,param_3);
    FUN_600d16ae(param_1[2]);
  }
  return uVar1;
}


