// 600d54f2  FUN_600d54f2  size=32 bytes
// --- callers ---
// --- callees ---
//   6006384c FUN_6006384c
//   600d54dc FUN_600d54dc


undefined4 FUN_600d54f2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600d54dc();
  if (iVar1 == 0) {
    uVar2 = 9;
  }
  else {
    FUN_6006384c(param_2,param_3);
    uVar2 = 0;
  }
  return uVar2;
}


