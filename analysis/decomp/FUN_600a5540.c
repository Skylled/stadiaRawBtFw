// 600a5540  FUN_600a5540  size=288 bytes
// --- callers ---
//   600a93b0 FUN_600a93b0
// --- callees ---
//   600b8888 FUN_600b8888
//   600b233c FUN_600b233c
//   6013d168 thunk_EXT_FUN_0000b554
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009fcf4 FUN_6009fcf4
//   6009ff18 FUN_6009ff18


void FUN_600a5540(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = FUN_6009ff18(param_1);
  if (*(char *)(DAT_600a5660 + 0x881) == '\x02') {
    if ((*(char *)(DAT_600a5660 + 0x1177) == '\0') ||
       ((local_c != 0 && ((*(ushort *)(local_c + 0x2a) & 0x10) != 0)))) {
      if ((*(int *)(DAT_600a5660 + 0x1148) == 0) ||
         (iVar1 = (**(code **)(DAT_600a5660 + 0x1148))(param_1,param_2), iVar1 != 0)) {
        if (((*(char *)(DAT_600a5660 + 0x118c) == '\0') ||
            ((*(byte *)(DAT_600a5660 + 0x118d) & 1) == 0)) ||
           (iVar1 = thunk_EXT_FUN_0000b554(DAT_600a5664,param_1,6), iVar1 != 0)) {
          thunk_EXT_FUN_0000b572(DAT_600a5668,param_1,6);
          thunk_EXT_FUN_0000b572(DAT_600a566c,param_2,3);
          iVar1 = FUN_600b8888(param_1);
          if (iVar1 != 0) {
            if (local_c == 0) {
              local_c = FUN_6009fcf4(param_1);
            }
            if (local_c != 0) {
              *(byte *)(local_c + 0x59) = *(byte *)(local_c + 0x59) | 0x40;
            }
          }
        }
        else {
          *(byte *)(DAT_600a5660 + 0x118d) = *(byte *)(DAT_600a5660 + 0x118d) | 0x20;
          FUN_600b233c(param_1,0xf);
        }
      }
      else {
        FUN_600b233c(param_1,0xf);
      }
    }
    else {
      FUN_600b233c(param_1,0xf);
    }
  }
  else {
    FUN_600b233c(param_1,0xf);
  }
  return;
}


