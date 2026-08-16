// 600bbd3c  FUN_600bbd3c  size=716 bytes
// --- callers ---
//   600ba1c4 FUN_600ba1c4
//   600bc880 FUN_600bc880
//   600f76ac FUN_600f76ac
// --- callees ---
//   600aa4c4 FUN_600aa4c4
//   600d9246 FUN_600d9246
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f9b5c FUN_600f9b5c
//   600f82c4 FUN_600f82c4
//   6006e0a4 FUN_6006e0a4
//   600b90d8 FUN_600b90d8


short * FUN_600bbd3c(int param_1,ushort param_2)

{
  short sVar1;
  int iVar2;
  int local_10;
  short *local_c;
  
  if (*(int *)(DAT_600bc008 + 0xe94) == 0) {
    local_c = (short *)0x0;
  }
  else {
    if (param_2 == 0) {
      local_c = *(short **)(DAT_600bc008 + 0xe94);
      *(undefined4 *)(DAT_600bc008 + 0xe94) = *(undefined4 *)(local_c + 0x92);
    }
    else {
      iVar2 = (param_2 - 0x40) * 0x158 + DAT_600bc008;
      local_c = (short *)(iVar2 + 0x29c);
      if (local_c == *(short **)(DAT_600bc008 + 0xe94)) {
        *(undefined4 *)(DAT_600bc008 + 0xe94) = *(undefined4 *)(iVar2 + 0x3c0);
      }
      else {
        for (local_10 = *(int *)(DAT_600bc008 + 0xe94); local_10 != 0;
            local_10 = *(int *)(local_10 + 0x124)) {
          if (local_c == *(short **)(local_10 + 0x124)) {
            *(undefined4 *)(local_10 + 0x124) = *(undefined4 *)(iVar2 + 0x3c0);
            if (local_c == *(short **)(DAT_600bc008 + 0xe98)) {
              *(int *)(DAT_600bc008 + 0xe98) = local_10;
            }
            break;
          }
        }
        if (local_10 == 0) {
          return (short *)0x0;
        }
      }
    }
    local_c[0x94] = 0;
    local_c[0x95] = 0;
    *(undefined4 *)(local_c + 0x92) = *(undefined4 *)(local_c + 0x94);
    *(undefined1 *)((int)local_c + 5) = 1;
    sVar1 = *(short *)(DAT_600bc008 + 0xf58);
    *(short *)(DAT_600bc008 + 0xf58) = sVar1 + 1;
    *local_c = sVar1;
    if (7 < (int)(*(ushort *)(DAT_600bc008 + 0xf58) - 0x40)) {
      *(undefined2 *)(DAT_600bc008 + 0xf58) = 0x40;
    }
    *(int *)(local_c + 0x96) = param_1;
    local_c[0xaa] = 0;
    local_c[0xab] = 0;
    *(undefined1 *)(local_c + 0x52) = 2;
    if (param_1 != 0) {
      FUN_600f9b5c(local_c);
    }
    local_c[0x2a] = 0;
    thunk_EXT_FUN_0000b5ba(local_c + 6,0,0x48);
    thunk_EXT_FUN_0000b5ba(local_c + 0x2c,0,0x48);
    local_c[0x3d] = -1;
    local_c[0x17] = local_c[0x3d];
    local_c[0x2e] = 0x2a0;
    local_c[8] = local_c[0x2e];
    *(undefined1 *)((int)local_c + 0x61) = 1;
    *(undefined1 *)((int)local_c + 0x15) = *(undefined1 *)((int)local_c + 0x61);
    local_c[0x32] = 0;
    local_c[0x33] = 0;
    *(undefined4 *)(local_c + 0xc) = *(undefined4 *)(local_c + 0x32);
    local_c[0x34] = 0;
    local_c[0x35] = 0;
    *(undefined4 *)(local_c + 0xe) = *(undefined4 *)(local_c + 0x34);
    local_c[0x36] = 0;
    local_c[0x37] = 0;
    *(undefined4 *)(local_c + 0x10) = *(undefined4 *)(local_c + 0x36);
    local_c[0x38] = -1;
    local_c[0x39] = -1;
    *(undefined4 *)(local_c + 0x12) = *(undefined4 *)(local_c + 0x38);
    local_c[0x3a] = -1;
    local_c[0x3b] = -1;
    *(undefined4 *)(local_c + 0x14) = *(undefined4 *)(local_c + 0x3a);
    *(undefined1 *)((int)local_c + 0x11f) = 0;
    thunk_EXT_FUN_0000b5ba((int)local_c + 0xa7,0,6);
    *(undefined1 *)((int)local_c + 0x11d) = 0;
    *(undefined1 *)(local_c + 0x8e) = 2;
    *(short **)(local_c + 0x7c) = local_c;
    if ((char)local_c[0x7f] != '\0') {
      FUN_600aa4c4(local_c + 0x74);
    }
    *(short **)(local_c + 0x88) = local_c;
    FUN_600f82c4(local_c);
    *(undefined1 *)((int)local_c + 0xa7) = 0;
    *(undefined1 *)(local_c + 0x54) = 1;
    *(undefined1 *)((int)local_c + 0xab) = 2;
    *(undefined1 *)(local_c + 0x56) = 2;
    *(undefined1 *)((int)local_c + 0xa9) = 2;
    *(undefined1 *)(local_c + 0x55) = 2;
    local_c[0x8d] = 0x248;
    sVar1 = FUN_6006e0a4(2);
    local_c[0x8c] = sVar1 + -0x20;
    FUN_600d9246(local_c + 0x98);
    *(undefined1 *)(local_c + 0x50) = 0;
    local_c[0x51] = 2;
    if (param_2 == 0) {
      *(undefined1 *)(local_c + 3) = 0;
    }
    *(undefined1 *)(local_c + 2) = 0;
    *(undefined1 *)((int)local_c + 9) = 0;
    *(undefined1 *)((int)local_c + 0xa5) = 1;
    *(undefined1 *)(local_c + 0x53) = 1;
    *(short **)(local_c + 0xa6) = local_c;
    *(undefined1 *)(local_c + 0xa9) = 0;
    FUN_600b90d8();
  }
  return local_c;
}


