// 600ebc36  FUN_600ebc36  size=56 bytes
// --- callers ---
// --- callees ---
//   600ebae8 FUN_600ebae8
//   600eba2c FUN_600eba2c


undefined4 FUN_600ebc36(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(code **)(iVar1 + 0xfc) == (code *)0x0) {
    if (*(int *)(param_1 + 0x10) == 0) {
      FUN_600ebae8(param_3,param_2,param_4,iVar1,param_1 + 0x28,*(undefined4 *)(iVar1 + 0xf8));
    }
    else {
      FUN_600eba2c();
    }
  }
  else {
    (**(code **)(iVar1 + 0xfc))();
  }
  return 1;
}


