// 600d3268  FUN_600d3268  size=58 bytes
// --- callers ---
//   60055e7c FUN_60055e7c
//   60055a7c FUN_60055a7c
// --- callees ---
//   600d1692 FUN_600d1692
//   600d16ae FUN_600d16ae


undefined4 FUN_600d3268(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (((param_1 == (undefined4 *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    uVar1 = 3;
  }
  else {
    *(undefined1 *)(param_3 + 0x20) = 0;
    *(undefined4 *)(param_3 + 0xc) = 0;
    FUN_600d1692(param_1[2]);
    uVar1 = (**(code **)(param_1[0xb4] + 0x10))(*param_1,param_2,param_3);
    FUN_600d16ae(param_1[2]);
  }
  return uVar1;
}


