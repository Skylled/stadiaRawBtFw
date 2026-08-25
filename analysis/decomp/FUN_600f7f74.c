// 600f7f74  FUN_600f7f74  size=150 bytes
// --- callers ---
//   600f309a FUN_600f309a
// --- callees ---
//   600bcbe0 FUN_600bcbe0
//   600b1804 FUN_600b1804
//   600b16c4 FUN_600b16c4


void FUN_600f7f74(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  int iVar1;
  
  iVar1 = FUN_600bcbe0(param_1);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x3a) = param_2;
    *(undefined2 *)(iVar1 + 0x3c) = param_3;
    *(undefined2 *)(iVar1 + 0x3e) = param_4;
    *(undefined2 *)(iVar1 + 0x40) = param_5;
    if ((*(byte *)(iVar1 + 0x38) & 1) == 0) {
      FUN_600b16c4(param_1,param_2,param_3,param_4,param_5,0,0);
    }
    else {
      *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) | 2;
      FUN_600b1804(param_1,0x3b);
    }
  }
  return;
}


