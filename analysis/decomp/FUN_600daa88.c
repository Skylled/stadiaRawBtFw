// 600daa88  FUN_600daa88  size=30 bytes
// --- callers ---
//   600daaa6 FUN_600daaa6
// --- callees ---
//   6013d2a0 thunk_EXT_FUN_00007a2c


undefined4 FUN_600daa88(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = thunk_EXT_FUN_00007a2c(param_1,3,0,0,10,param_2,param_3);
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}


