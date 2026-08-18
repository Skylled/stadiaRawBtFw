// 600d3202  FUN_600d3202  size=66 bytes
// --- callers ---
//   600d5456 FUN_600d5456
// --- callees ---
//   600d265a FUN_600d265a
//   600d31e6 FUN_600d31e6
//   600d168e thunk_FUN_600d1662


undefined4 FUN_600d3202(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 3;
  }
  else {
    iVar2 = param_1[0xb5];
    while (iVar2 != 0) {
      iVar2 = param_1[0xb5];
      FUN_600d265a(param_1,iVar2);
    }
    uVar1 = (**(code **)(param_1[0xb4] + 4))(*param_1);
    *param_1 = 0;
    if (param_1[2] != 0) {
      thunk_FUN_600d1662();
      param_1[2] = 0;
    }
    FUN_600d31e6(param_1 + 0xba);
  }
  return uVar1;
}


