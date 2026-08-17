// 6009bf1c  FUN_6009bf1c  size=138 bytes
// --- callers ---
//   60098f88 FUN_60098f88
//   6009b368 FUN_6009b368
// --- callees ---
//   600a1218 FUN_600a1218
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d168 thunk_EXT_FUN_0000b554
//   60098ec8 FUN_60098ec8


void FUN_6009bf1c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_14;
  undefined2 local_10;
  int local_c;
  
  local_c = FUN_60098ec8(param_1,2);
  local_14 = 0;
  local_10 = 0;
  if (local_c != 0) {
    if (*(char *)(DAT_6009bfa8 + 0xa6a) == '\0') {
      *(undefined1 *)(local_c + 0x135) = 0;
      FUN_600a1218(local_c + 0x12f);
    }
    else {
      *(undefined1 *)(local_c + 0x135) = 1;
      iVar1 = thunk_EXT_FUN_0000b554(param_2,&local_14,6);
      if (iVar1 == 0) {
        thunk_EXT_FUN_0000b572(local_c + 0x12f,DAT_6009bfac,6);
      }
      else {
        thunk_EXT_FUN_0000b572(local_c + 0x12f,param_2,6);
      }
    }
  }
  return;
}


