// 600f5446  FUN_600f5446  size=50 bytes
// --- callers ---
//   600f3620 FUN_600f3620
// --- callees ---
//   600f55a4 FUN_600f55a4


undefined2 FUN_600f5446(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = FUN_600f55a4(param_1,param_3,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined2 *)(iVar1 + 0xc);
  }
  return uVar2;
}


