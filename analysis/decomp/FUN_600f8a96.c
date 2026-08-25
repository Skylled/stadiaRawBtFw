// 600f8a96  FUN_600f8a96  size=84 bytes
// --- callers ---
//   600f2d70 FUN_600f2d70
// --- callees ---
//   600bcbe0 FUN_600bcbe0
//   600b5e00 FUN_600b5e00


undefined4 FUN_600f8a96(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  iVar1 = FUN_600bcbe0(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    for (local_c = *(int *)(iVar1 + 0x5c); local_c != 0; local_c = *(int *)(local_c + 0x124)) {
      if (*(int *)(*(int *)(local_c + 0x154) + 0x24) != 0) {
        FUN_600b5e00(local_c,6,0);
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


