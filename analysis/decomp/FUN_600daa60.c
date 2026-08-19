// 600daa60  FUN_600daa60  size=40 bytes
// --- callers ---
// --- callees ---
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   6013cf80 thunk_EXT_FUN_0000714c


undefined4 FUN_600daa60(undefined4 param_1,undefined4 param_2)

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


