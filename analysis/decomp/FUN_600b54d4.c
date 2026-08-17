// 600b54d4  FUN_600b54d4  size=102 bytes
// --- callers ---
//   600f592e FUN_600f592e
//   600b8d7c FUN_600b8d7c
//   600b5720 FUN_600b5720
// --- callees ---
//   6009c778 FUN_6009c778
//   600b0fc8 FUN_600b0fc8
//   600bb6dc FUN_600bb6dc
//   6009c790 FUN_6009c790
//   600bb534 FUN_600bb534
//   6013d168 thunk_EXT_FUN_0000b554


undefined4 FUN_600b54d4(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6009c778();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = thunk_EXT_FUN_0000b554(param_1,DAT_600b553c,6);
    if (iVar1 == 0) {
      iVar1 = FUN_600b0fc8();
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        iVar1 = FUN_600bb6dc(param_1,2);
        if (iVar1 != 0) {
          *(undefined2 *)(iVar1 + 0x30) = 0x100;
          FUN_600bb534(iVar1);
        }
        FUN_6009c790(3);
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


