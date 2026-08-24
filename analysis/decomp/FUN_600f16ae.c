// 600f16ae  FUN_600f16ae  size=82 bytes
// --- callers ---
//   600ee298 FUN_600ee298
//   600c4da8 FUN_600c4da8
//   600c2b3c FUN_600c2b3c
// --- callees ---
//   600f172a FUN_600f172a
//   600a1560 FUN_600a1560
//   600f045e FUN_600f045e
//   6009ff18 FUN_6009ff18


undefined4 FUN_600f16ae(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600f045e(param_1,2);
  if ((iVar1 == 0) && (iVar1 = FUN_600f045e(param_1,1), iVar1 == 0)) {
    iVar1 = FUN_6009ff18(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      FUN_600f172a(iVar1);
      FUN_600a1560(param_1,0);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


