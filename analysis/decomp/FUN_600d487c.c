// 600d487c  FUN_600d487c  size=72 bytes
// --- callers ---
// --- callees ---
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf40 thunk_EXT_FUN_00007d10


undefined4 FUN_600d487c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar1 = 3;
  }
  else {
    thunk_EXT_FUN_0000b4c2(param_1 + 7);
    if (*(char *)((int)param_1 + 0x19) == '\0') {
      uVar1 = 9;
    }
    else {
      uVar1 = 0;
      uVar2 = (**(code **)(*param_1 + 0x20))(param_1,param_3);
      thunk_EXT_FUN_0000b572(param_2,uVar2,param_4);
    }
    thunk_EXT_FUN_00007d10(param_1 + 7);
  }
  return uVar1;
}


