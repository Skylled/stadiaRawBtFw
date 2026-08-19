// 600db642  FUN_600db642  size=58 bytes
// --- callers ---
// --- callees ---
//   6005bdac FUN_6005bdac
//   6013d398 thunk_EXT_FUN_00001834


undefined4 FUN_600db642(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 8) == 3) && (*(char *)(param_1 + 0x10) == '\b')) {
    iVar1 = FUN_6005bdac();
    *(undefined1 *)(iVar1 + 0x55c) = 0;
    uVar2 = FUN_6005bdac();
    thunk_EXT_FUN_00001834(uVar2,0,8,0,0);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


