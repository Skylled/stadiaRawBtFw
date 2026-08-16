// 600aa8f0  FUN_600aa8f0  size=472 bytes
// --- callers ---
//   600f31e6 FUN_600f31e6
// --- callees ---
//   600a1154 FUN_600a1154
//   6004cb28 FUN_6004cb28


undefined4 FUN_600aa8f0(short param_1,int param_2,char param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int local_20;
  ushort local_1c;
  byte local_19;
  undefined1 *local_18;
  short *local_14;
  
  local_14 = DAT_600aaac8;
  local_18 = (undefined1 *)(param_2 + 9);
  local_1c = *(ushort *)(param_2 + 4);
  local_20 = 0;
  local_19 = 0;
  while( true ) {
    if (3 < local_19) {
      return 10;
    }
    if (param_1 == *local_14) break;
    local_19 = local_19 + 1;
    local_14 = local_14 + 6;
  }
  if ((local_14[1] != 0x2a00) && (param_3 == '\x01')) {
    return 0xb;
  }
  uVar1 = local_14[1];
  if (uVar1 == 0x2a01) {
    *local_18 = (char)local_14[2];
    *(char *)(param_2 + 10) = (char)((ushort)local_14[2] >> 8);
    *(undefined2 *)(param_2 + 6) = 2;
  }
  else if (uVar1 < 0x2a02) {
    if (uVar1 == 0x2a00) {
      FUN_600a1154(&local_20);
      uVar3 = FUN_6004cb28(local_20);
      if (uVar3 < 0x259) {
        uVar2 = FUN_6004cb28(local_20);
        *(undefined2 *)(param_2 + 6) = uVar2;
      }
      else {
        *(undefined2 *)(param_2 + 6) = 600;
      }
      if (*(ushort *)(param_2 + 6) < local_1c) {
        return 7;
      }
      *(ushort *)(param_2 + 6) = *(short *)(param_2 + 6) - local_1c;
      for (iVar4 = 0; iVar4 < (int)(uint)*(ushort *)(param_2 + 6); iVar4 = iVar4 + 1) {
        *local_18 = *(undefined1 *)(iVar4 + (uint)local_1c + local_20);
        local_18 = local_18 + 1;
      }
    }
  }
  else if (uVar1 == 0x2a04) {
    *local_18 = (char)local_14[2];
    *(char *)(param_2 + 10) = (char)((ushort)local_14[2] >> 8);
    *(char *)(param_2 + 0xb) = (char)local_14[3];
    *(char *)(param_2 + 0xc) = (char)((ushort)local_14[3] >> 8);
    *(char *)(param_2 + 0xd) = (char)local_14[4];
    *(char *)(param_2 + 0xe) = (char)((ushort)local_14[4] >> 8);
    *(char *)(param_2 + 0xf) = (char)local_14[5];
    *(char *)(param_2 + 0x10) = (char)((ushort)local_14[5] >> 8);
    *(undefined2 *)(param_2 + 6) = 8;
  }
  else if (uVar1 == 0x2aa6) {
    *local_18 = (char)local_14[2];
    *(undefined2 *)(param_2 + 6) = 1;
  }
  return 0;
}


