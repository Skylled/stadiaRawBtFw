// 600a42d0  FUN_600a42d0  size=480 bytes
// --- callers ---
//   600a44bc FUN_600a44bc
//   600a59d0 FUN_600a59d0
//   600fcfbc FUN_600fcfbc
// --- callees ---
//   600a5964 FUN_600a5964
//   600b25c8 FUN_600b25c8
//   600b3790 FUN_600b3790
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b24f8 FUN_600b24f8
//   6009ff18 FUN_6009ff18
//   600a8108 FUN_600a8108
//   6013d168 thunk_EXT_FUN_0000b554


void FUN_600a42d0(undefined4 param_1,char param_2,byte param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  char local_1d;
  uint local_14;
  
  if (((*(char *)(DAT_600a44b0 + 0x118c) == '\x03') &&
      (iVar1 = thunk_EXT_FUN_0000b554(param_1,DAT_600a44b4,6), iVar1 == 0)) &&
     (iVar1 = FUN_6009ff18(param_1), iVar1 != 0)) {
    if (((0x10 < param_3) || (param_3 == 0)) || (local_1d = param_2, param_4 == 0)) {
      local_1d = '\x05';
    }
    if (local_1d == '\0') {
      if (param_5 != 0) {
        for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
          *(undefined4 *)(local_14 * 4 + iVar1 + 4) = *(undefined4 *)(param_5 + local_14 * 4);
        }
      }
      *(ushort *)(iVar1 + 0x2a) = *(ushort *)(iVar1 + 0x2a) | 0x20;
      if (((*(byte *)(DAT_600a44b0 + 0x118d) & 1) == 0) || (*(short *)(iVar1 + 0xc) != -1)) {
        FUN_600a8108(9);
        *(undefined1 *)(DAT_600a44b0 + 0x1abb) = 0;
        FUN_600b24f8(param_1,param_3,param_4);
      }
      else {
        *(byte *)(DAT_600a44b0 + 0x117b) = param_3;
        thunk_EXT_FUN_0000b572(DAT_600a44b8,param_4,param_3);
        *(undefined1 *)(DAT_600a44b0 + 0x1178) = 1;
        FUN_600b3790(1);
        *(undefined1 *)(DAT_600a44b0 + 0x1abb) = 0xff;
        if ((*(byte *)(DAT_600a44b0 + 0x118d) & 0x20) == 0) {
          if ((*(byte *)(iVar1 + 0x59) & 0x40) == 0) {
            iVar2 = FUN_600a5964(iVar1);
            if (iVar2 != 1) {
              FUN_600a8108(0);
              *(ushort *)(iVar1 + 0x2a) = *(ushort *)(iVar1 + 0x2a) & 0xffdf;
              if (*(int *)(DAT_600a44b0 + 0x1128) != 0) {
                (**(code **)(DAT_600a44b0 + 0x1128))(iVar1 + 0x10,iVar1 + 0x16,iVar1 + 0x2c,5);
              }
            }
          }
          else {
            FUN_600a8108(2);
          }
        }
        else {
          FUN_600a8108(2);
        }
      }
    }
    else if ((*(byte *)(DAT_600a44b0 + 0x118d) & 2) == 0) {
      *(undefined2 *)(iVar1 + 0x54) = 0;
      FUN_600a8108(0);
    }
    else {
      FUN_600a8108(9);
      *(undefined1 *)(DAT_600a44b0 + 0x1abb) = 0xe;
      FUN_600b25c8(param_1);
    }
  }
  return;
}


