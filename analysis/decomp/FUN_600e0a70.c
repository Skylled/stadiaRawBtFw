// 600e0a70  FUN_600e0a70  size=60 bytes
// --- callers ---
//   600e0aac FUN_600e0aac
//   600e0bfe FUN_600e0bfe
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e092c FUN_600e092c
//   6013cf90 thunk_EXT_FUN_0000b5ba


int FUN_600e0a70(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600e092c(0x14);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b5ba(iVar1,0,0x14);
    iVar2 = FUN_600e092c(0x10);
    *(int *)(iVar1 + 4) = iVar2;
    if (iVar2 != 0) {
      thunk_EXT_FUN_0000b5ba(iVar2,0,0x10);
      *(undefined4 *)(iVar1 + 0x10) = param_1;
      *(undefined4 *)(iVar1 + 0xc) = 4;
      return iVar1;
    }
  }
  thunk_EXT_FUN_0000ac5e(iVar1);
  return 0;
}


