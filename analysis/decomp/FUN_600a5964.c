// 600a5964  FUN_600a5964  size=102 bytes
// --- callers ---
//   600a42d0 FUN_600a42d0
//   600a6cf8 FUN_600a6cf8
//   600a44bc FUN_600a44bc
//   600a59d0 FUN_600a59d0
// --- callees ---
//   600bc480 FUN_600bc480
//   600a8108 FUN_600a8108
//   600bb44c FUN_600bb44c
//   600bb534 FUN_600bb534


undefined4 FUN_600a5964(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_600bb44c(param_1 + 0x10,1,1);
  if (iVar1 == 0) {
    uVar3 = 3;
  }
  else {
    *(byte *)(DAT_600a59cc + 0x118d) = *(byte *)(DAT_600a59cc + 0x118d) | 4;
    iVar2 = FUN_600bc480(iVar1,1);
    if (iVar2 == 0) {
      FUN_600bb534(iVar1);
      uVar3 = 3;
    }
    else {
      FUN_600a8108(2);
      uVar3 = 1;
    }
  }
  return uVar3;
}


