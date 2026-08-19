// 600db2be  FUN_600db2be  size=52 bytes
// --- callers ---
// --- callees ---
//   6013d398 thunk_EXT_FUN_00001834
//   6005bdac FUN_6005bdac


undefined4 FUN_600db2be(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 8) == 3) && (*(char *)(param_1 + 0x10) == '\x03')) {
    uVar1 = FUN_6005bdac();
    thunk_EXT_FUN_00001834(uVar1,1,7,1,0,param_2);
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


