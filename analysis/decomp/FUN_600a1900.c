// 600a1900  FUN_600a1900  size=602 bytes
// --- callers ---
//   600c2810 FUN_600c2810
//   600a14e4 FUN_600a14e4
//   600c290c FUN_600c290c
// --- callees ---
//   600b3b2c FUN_600b3b2c
//   600a12e0 FUN_600a12e0
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a1340 FUN_600a1340
//   600b35cc FUN_600b35cc
//   600b36e8 FUN_600b36e8
//   6009daac FUN_6009daac


undefined4 FUN_600a1900(ushort param_1,ushort param_2,ushort param_3)

{
  int iVar1;
  ushort uVar2;
  undefined4 uVar3;
  ushort local_26;
  ushort local_24;
  undefined1 auStack_20 [3];
  undefined1 auStack_1d [5];
  undefined1 local_18;
  char local_17;
  byte local_16;
  byte local_14;
  byte local_13;
  byte local_12;
  byte local_11;
  byte *local_10;
  ushort local_c;
  byte local_9;
  
  local_9 = 0;
  if (((*(byte *)(DAT_600a1b5c + 0x81b) & 2) != 0) && (iVar1 = FUN_6009daac(param_1), iVar1 == 0)) {
    *(ushort *)(DAT_600a1b5c + 0xb10) = *(ushort *)(DAT_600a1b5c + 0xb10) & 0xfcff;
    *(ushort *)(DAT_600a1b5c + 0xb10) = param_1 & 0x300 | *(ushort *)(DAT_600a1b5c + 0xb10);
  }
  uVar2 = param_1 & 0xfcff;
  if (uVar2 < 3) {
    if (*(byte *)(DAT_600a1b5c + 0x881) < 2) {
      uVar3 = 0xc;
    }
    else {
      local_24 = param_2;
      if (param_2 == 0) {
        local_24 = 0x12;
      }
      local_26 = param_3;
      if (param_3 == 0) {
        local_26 = 0x800;
      }
      if ((uVar2 == 0) ||
         ((((0x10 < local_24 && (local_24 < 0x1001)) && (0x11 < local_26)) &&
          ((local_26 < 0x1001 && (local_24 <= local_26)))))) {
        if (uVar2 != 0) {
          if ((param_1 & 1) == 0) {
            iVar1 = FUN_600b3b2c(1,DAT_600a1b64);
            if (iVar1 == 0) {
              return 3;
            }
          }
          else {
            thunk_EXT_FUN_0000b572(auStack_20,DAT_600a1b60,3);
            thunk_EXT_FUN_0000b572(auStack_1d,DAT_600a1b64,3);
            iVar1 = FUN_600b3b2c(2,auStack_20);
            if (iVar1 == 0) {
              return 3;
            }
          }
          local_9 = local_9 | 1;
        }
        if ((local_24 != *(ushort *)(DAT_600a1b5c + 0xb18)) ||
           (local_26 != *(ushort *)(DAT_600a1b5c + 0xb1a))) {
          iVar1 = FUN_600b36e8(local_26,local_24);
          if (iVar1 == 0) {
            return 3;
          }
          *(ushort *)(DAT_600a1b5c + 0xb18) = local_24;
          *(ushort *)(DAT_600a1b5c + 0xb1a) = local_26;
        }
        if ((*(ushort *)(DAT_600a1b5c + 0xb12) & 1) != 0) {
          local_9 = local_9 | 2;
        }
        iVar1 = FUN_600b35cc(local_9);
        if (iVar1 == 0) {
          uVar3 = 3;
        }
        else {
          *(ushort *)(DAT_600a1b5c + 0xb10) = *(ushort *)(DAT_600a1b5c + 0xb10) & 0xfffc;
          *(ushort *)(DAT_600a1b5c + 0xb10) = uVar2 | *(ushort *)(DAT_600a1b5c + 0xb10);
          local_10 = (byte *)FUN_600a1340();
          local_c = (ushort)*local_10 * 0x100 + (local_10[1] & 0xe0);
          local_11 = (byte)uVar2 & 1;
          local_12 = (byte)((int)(uint)local_c >> 5) & 1;
          if (local_11 != local_12) {
            local_16 = local_10[2] & 0xfc;
            local_14 = local_10[1] & 0x1f;
            if ((param_1 & 1) == 0) {
              local_c = local_c & 0xffdf;
            }
            else {
              local_c = local_c | 0x20;
            }
            local_17 = local_14 + (char)local_c;
            local_18 = (undefined1)(local_c >> 8);
            local_13 = local_16;
            FUN_600a12e0(&local_18);
          }
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 5;
      }
    }
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}


