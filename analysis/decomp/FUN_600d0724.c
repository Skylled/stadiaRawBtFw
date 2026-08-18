// 600d0724  FUN_600d0724  size=108 bytes
// --- callers ---
// --- callees ---
//   600d15e8 FUN_600d15e8
//   6013d3e0 thunk_EXT_FUN_00008802
//   600d1090 FUN_600d1090


int FUN_600d0724(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uStack_1c;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 3;
  }
  else {
    if (*(byte *)(param_1 + 5) == param_2) {
      puVar2 = param_1 + 4;
    }
    else {
      if (*(byte *)(param_1 + 9) != param_2) {
        return 1;
      }
      puVar2 = param_1 + 8;
    }
    puVar3 = param_1;
    uStack_1c = param_2;
    thunk_EXT_FUN_00008802((int)&uStack_1c + 3);
    if (*(char *)((int)puVar2 + 5) == '\x01') {
      iVar1 = 2;
      FUN_600d15e8(uStack_1c._3_1_);
    }
    else {
      iVar1 = FUN_600d1090(*param_1,param_2,param_3,param_4,puVar3);
      if (iVar1 == 0) {
        *(undefined1 *)((int)puVar2 + 5) = 1;
      }
      FUN_600d15e8(uStack_1c._3_1_);
    }
  }
  return iVar1;
}


