// 600d7dfc  FUN_600d7dfc  size=44 bytes
// --- callers ---
// --- callees ---
//   6013d298 thunk_EXT_FUN_0000b08e


undefined4 FUN_600d7dfc(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar1 = 0xe;
  }
  else {
    iVar2 = thunk_EXT_FUN_0000b08e(*(int *)(param_1 + 0xc),param_2,param_3);
    if (iVar2 == 0) {
      uVar1 = 0xd;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


