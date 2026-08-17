// 6009a82c  FUN_6009a82c  size=174 bytes
// --- callers ---
//   600b27e8 FUN_600b27e8
//   600b20a0 FUN_600b20a0
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a9234 FUN_600a9234
//   6006dfa4 FUN_6006dfa4
//   60098ec8 FUN_60098ec8
//   600f1746 FUN_600f1746


void FUN_6009a82c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(char *)(DAT_6009a8dc + 0x1acd) == '\0') {
    iVar1 = FUN_60098ec8(param_2,1);
    if (iVar1 == 0) {
      if ((*(char *)(DAT_6009a8dc + 0x1acc) == '\0') ||
         (iVar1 = thunk_EXT_FUN_0000b554(param_2,DAT_6009a8e4,6), iVar1 == 0)) {
        iVar1 = FUN_600f1746(param_2);
        thunk_EXT_FUN_0000b572(DAT_6009a8e4,iVar1 + 0x10,6);
        thunk_EXT_FUN_0000b572(DAT_6009a8e8,iVar1 + 0x16,3);
        FUN_600a9234(0,param_1);
      }
      else {
        FUN_6006dfa4(DAT_6009a8e0,param_1);
      }
      *(undefined1 *)(DAT_6009a8dc + 0x1acc) = 1;
    }
    else {
      FUN_600a9234(0,param_1);
    }
  }
  else {
    *(undefined1 *)(DAT_6009a8dc + 0x1acc) = 1;
    FUN_6006dfa4(DAT_6009a8e0,param_1);
  }
  return;
}


