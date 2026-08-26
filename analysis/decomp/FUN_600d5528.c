// 600d5528  FUN_600d5528  size=32 bytes
// --- callers ---
// --- callees ---
//   6006385c FUN_6006385c
//   600d5512 FUN_600d5512


undefined4 FUN_600d5528(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600d5512();
  if (iVar1 == 0) {
    uVar2 = 9;
  }
  else {
    FUN_6006385c(param_2,param_3);
    uVar2 = 0;
  }
  return uVar2;
}


