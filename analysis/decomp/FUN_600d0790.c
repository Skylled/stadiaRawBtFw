// 600d0790  FUN_600d0790  size=68 bytes
// --- callers ---
// --- callees ---
//   600d15e8 FUN_600d15e8
//   600d109c FUN_600d109c
//   6013d3e0 thunk_EXT_FUN_00008802


int FUN_600d0790(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 3;
  }
  else if (*(char *)((int)param_1 + 0x1d) == '\x01') {
    iVar1 = 2;
  }
  else {
    puVar2 = param_1;
    uStack_1c = param_2;
    uStack_18 = param_3;
    thunk_EXT_FUN_00008802((int)&uStack_1c + 3);
    iVar1 = FUN_600d109c(*param_1,param_2,param_3,param_4,puVar2);
    if (iVar1 == 0) {
      *(undefined1 *)((int)param_1 + 0x1d) = 1;
    }
    FUN_600d15e8(uStack_1c._3_1_);
  }
  return iVar1;
}


