// 600b81ec  FUN_600b81ec  size=568 bytes
// --- callers ---
//   600b7db8 FUN_600b7db8
//   600b8094 FUN_600b8094
// --- callees ---
//   6006ddd8 FUN_6006ddd8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b5e00 FUN_600b5e00
//   6006dcdc FUN_6006dcdc


bool FUN_600b81ec(ushort *param_1,int param_2,ushort param_3)

{
  undefined4 uVar1;
  int local_20;
  byte *local_10;
  bool local_9;
  
  param_3 = param_3 & 0xc000;
  local_9 = true;
  if ((param_3 == 0) || (param_3 == 0x4000)) {
    local_9 = *(int *)(param_1 + 0x60) == 0;
    if ((param_3 == 0x4000) && (*(ushort *)(param_2 + 2) < 2)) {
      local_9 = false;
    }
  }
  else if (*(int *)(param_1 + 0x60) == 0) {
    local_9 = false;
  }
  local_20 = param_2;
  if ((local_9 != false) && (param_3 != 0)) {
    local_10 = (byte *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
    if (param_3 == 0x4000) {
      param_1[0x5f] = (ushort)local_10[1] * 0x100 + (ushort)*local_10;
      local_10 = local_10 + 2;
      *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + 2;
      *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + -2;
      if (param_1[0x8d] < param_1[0x5f]) {
        local_9 = false;
      }
      else {
        uVar1 = FUN_6006dcdc(*(undefined1 *)((int)param_1 + 0xa9),DAT_600b8424,0x593);
        *(undefined4 *)(param_1 + 0x60) = uVar1;
        if (*(int *)(param_1 + 0x60) == 0) {
          local_9 = false;
        }
        else {
          *(undefined2 *)(*(int *)(param_1 + 0x60) + 4) = 4;
          *(undefined2 *)(*(int *)(param_1 + 0x60) + 2) = 0;
        }
      }
    }
    if (local_9 != false) {
      if ((uint)param_1[0x5f] <
          (uint)*(ushort *)(param_2 + 2) + (uint)*(ushort *)(*(int *)(param_1 + 0x60) + 2)) {
        local_9 = false;
      }
      else if ((param_3 == 0x8000) &&
              ((uint)*(ushort *)(param_2 + 2) + (uint)*(ushort *)(*(int *)(param_1 + 0x60) + 2) !=
               (uint)param_1[0x5f])) {
        local_9 = false;
      }
      else {
        thunk_EXT_FUN_0000b572
                  (*(int *)(param_1 + 0x60) + 8 +
                   (uint)*(ushort *)(*(int *)(param_1 + 0x60) + 2) +
                   (uint)*(ushort *)(*(int *)(param_1 + 0x60) + 4),local_10,
                   *(undefined2 *)(param_2 + 2));
        *(short *)(*(int *)(param_1 + 0x60) + 2) =
             *(short *)(param_2 + 2) + *(short *)(*(int *)(param_1 + 0x60) + 2);
        FUN_6006ddd8(param_2,DAT_600b8424,0x5b3);
        local_20 = 0;
        if (param_3 == 0x8000) {
          local_20 = *(int *)(param_1 + 0x60);
          param_1[0x60] = 0;
          param_1[0x61] = 0;
        }
      }
    }
  }
  if (local_9 == false) {
    FUN_6006ddd8(local_20,DAT_600b8424,0x5c1);
  }
  else if (local_20 != 0) {
    if (((*param_1 < 0x40) && (3 < *param_1)) && (*param_1 < 8)) {
      if (*(int *)((*param_1 - 4) * 0x1c + DAT_600b8428 + 0xed4) != 0) {
        (**(code **)((*param_1 - 4) * 0x1c + DAT_600b8428 + 0xed4))
                  (*(int *)(param_1 + 0x96) + 4,local_20);
      }
    }
    else {
      FUN_600b5e00(param_1,0x14,local_20);
    }
  }
  return local_9;
}


