// 600d512e  FUN_600d512e  size=34 bytes
// --- callers ---
//   60061cc8 persistent_crash_register__60061cc8
//   600d5150 FUN_600d5150
//   600d51c2 FUN_600d51c2
//   60061d38 FUN_60061d38
// --- callees ---
//   60059f00 snvs__60059f00


uint FUN_600d512e(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = snvs__60059f00(param_1,iVar2,param_2 + iVar2 * 4);
    if ((uVar1 & 0xff) != 0) {
      return uVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 4);
  return 0;
}


