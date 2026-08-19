// 600d4084  FUN_600d4084  size=40 bytes
// --- callers ---
//   6005c8a0 FUN_6005c8a0
// --- callees ---
//   6013cf80 thunk_EXT_FUN_0000714c
//   6013d2a0 thunk_EXT_FUN_00007a2c


undefined4 FUN_600d4084(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = thunk_EXT_FUN_0000714c();
  iVar2 = thunk_EXT_FUN_00007a2c(param_1,1,uVar1,0,10,param_2);
  if (iVar2 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


