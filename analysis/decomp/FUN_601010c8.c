// 601010c8  FUN_601010c8  size=100 bytes
// --- callers ---
//   600d39ba FUN_600d39ba
//   600d6f7e FUN_600d6f7e
//   600d7032 FUN_600d7032
//   600ce2c6 FUN_600ce2c6
//   60065eb8 keys__60065eb8
//   600d708c FUN_600d708c
//   600662e0 dynamic_buffer__600662e0
//   600d6e14 FUN_600d6e14
//   600d6eca FUN_600d6eca
//   6005dcc0 FUN_6005dcc0
//   60065df0 keys__60065df0
//   600d7282 FUN_600d7282
//   6005dbec FUN_6005dbec
//   600d6fd8 FUN_600d6fd8
//   600764fc input_task__600764fc
//   600d382e FUN_600d382e
//   600d6f24 FUN_600d6f24
//   600d5066 FUN_600d5066
//   600d70e6 FUN_600d70e6
// --- callees ---
//   6013cef0 thunk_EXT_FUN_0000887a
//   60100e78 FUN_60100e78
//   600db002 FUN_600db002
//   6013d3d8 thunk_EXT_FUN_0000b4c2


undefined1 FUN_601010c8(int param_1,int param_2,undefined2 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 uVar2;
  int local_14;
  
  if (((param_2 != 0) && (param_3 != (undefined2 *)0x0)) &&
     (local_14 = param_2, iVar1 = FUN_600db002(param_2,0x10,param_3,param_4,param_1),
     iVar1 - 1U < 0xf)) {
    local_14 = param_1 + 4;
    thunk_EXT_FUN_0000b4c2();
    if (*(char *)(param_1 + 0x58) == '\0') {
      uVar2 = 9;
    }
    else {
      iVar1 = FUN_60100e78(param_1,param_2);
      if ((iVar1 == 100) || (param_1 = iVar1 * 0x18 + param_1, *(char *)(param_1 + 0x16e) != '\0'))
      {
        uVar2 = 5;
      }
      else {
        *param_3 = *(undefined2 *)(param_1 + 0x16c);
        uVar2 = 0;
      }
    }
    thunk_EXT_FUN_0000887a(&local_14);
    return uVar2;
  }
  return 3;
}


