// 600d4df0  FUN_600d4df0  size=92 bytes
// --- callers ---
//   600d9a00 FUN_600d9a00
// --- callees ---
//   60101822 FUN_60101822
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013cf40 thunk_EXT_FUN_00007d10


undefined4 FUN_600d4df0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    uVar2 = 0;
  }
  else {
    thunk_EXT_FUN_0000b4c2(param_1 + 0x74);
    iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x14))(param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_60101822(param_1 + 0x20,param_4);
      uVar2 = 0;
      if (iVar1 == 0) {
        uVar2 = 4;
        (**(code **)(*(int *)(param_1 + 8) + 0x28))(0x18,0);
      }
    }
    else {
      uVar2 = 0xe;
    }
    thunk_EXT_FUN_00007d10(param_1 + 0x74);
  }
  return uVar2;
}


