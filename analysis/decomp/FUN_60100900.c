// 60100900  FUN_60100900  size=90 bytes
// --- callers ---
//   6006e484 gki_ft__6006e484
// --- callees ---
//   600ca0fc FUN_600ca0fc
//   600c9fd8 FUN_600c9fd8
//   6013d128 thunk_EXT_FUN_00007f58
//   6013d180 thunk_EXT_FUN_000080d8


undefined4
FUN_60100900(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar1 = thunk_EXT_FUN_00007f58(param_3 << 2);
  if (iVar1 != 0) {
    iVar2 = thunk_EXT_FUN_00007f58(0xcc);
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x30) = iVar1;
      *(undefined1 *)(iVar2 + 0xc9) = 0;
      FUN_600ca0fc(param_1,param_2,param_3,param_4,param_5,param_6,iVar2);
      FUN_600c9fd8(iVar2);
      return 1;
    }
    thunk_EXT_FUN_000080d8(iVar1);
  }
  return 0xffffffff;
}


