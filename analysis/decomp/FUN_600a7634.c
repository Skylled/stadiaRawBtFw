// 600a7634  FUN_600a7634  size=144 bytes
// --- callers ---
//   600f2be8 FUN_600f2be8
// --- callees ---
//   600b23d0 FUN_600b23d0
//   6013d168 thunk_EXT_FUN_0000b554
//   600f8bd4 FUN_600f8bd4
//   600b2474 FUN_600b2474
//   600f1746 FUN_600f1746


void FUN_600a7634(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600f1746(param_1);
  if ((*(ushort *)(iVar1 + 0x2a) & 0x10) == 0) {
    FUN_600f8bd4(param_1);
    if ((((*(char *)(DAT_600a76c4 + 0x118c) == '\0') ||
         (iVar2 = thunk_EXT_FUN_0000b554(param_1,DAT_600a76c8,6), iVar2 != 0)) &&
        (*(int *)(DAT_600a76c4 + 0x1124) != 0)) &&
       (iVar2 = (**(code **)(DAT_600a76c4 + 0x1124))(param_1,iVar1 + 0x19), iVar2 == 0)) {
      FUN_600b23d0(param_1,iVar1 + 0x19);
    }
    else {
      FUN_600b2474(param_1);
    }
  }
  else {
    FUN_600b23d0(param_1,iVar1 + 0x19);
  }
  return;
}


