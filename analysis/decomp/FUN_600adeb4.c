// 600adeb4  FUN_600adeb4  size=542 bytes
// --- callers ---
//   600f6516 FUN_600f6516
// --- callees ---
//   600f6158 FUN_600f6158
//   600f622a FUN_600f622a
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600adc88 FUN_600adc88
//   600f6be6 FUN_600f6be6
//   6006dbac FUN_6006dbac
//   600afb50 FUN_600afb50
//   600f6ee2 FUN_600f6ee2
//   6006ddd8 FUN_6006ddd8
//   600f6b4a FUN_600f6b4a
//   600f552e FUN_600f552e
//   600f5478 FUN_600f5478


void FUN_600adeb4(int param_1,undefined1 param_2,ushort param_3,byte *param_4)

{
  ushort uVar1;
  undefined1 local_2e;
  undefined1 local_2d;
  int local_2c;
  int local_28;
  byte local_22;
  char local_21;
  byte *local_20;
  ushort local_1c;
  short local_1a;
  
  local_1a = 0;
  local_21 = '\0';
  *(undefined2 *)(param_1 + 0x32) = 0;
  local_20 = param_4;
  local_1c = param_3;
  FUN_600f6b4a(param_1 + 0xd,*(undefined1 *)(param_1 + 0x13),&local_2d,&local_2e);
  while( true ) {
    if ((local_1c < 2) || (9 < *(ushort *)(param_1 + 0x32))) goto LAB_600adf84;
    local_1a = (ushort)local_20[1] * 0x100 + (ushort)*local_20;
    local_20 = local_20 + 2;
    local_22 = FUN_600afb50(local_1a);
    if (9 < local_22) break;
    uVar1 = *(ushort *)(param_1 + 0x32);
    *(ushort *)(param_1 + 0x32) = uVar1 + 1;
    *(short *)((uVar1 + 0x18) * 2 + param_1 + 4) = local_1a;
    local_21 = FUN_600f552e(*(undefined4 *)((uint)local_22 * 0x28 + DAT_600ae0d4 + 0xa84),0,local_1a
                            ,local_2d,local_2e);
    if (local_21 != '\0') goto LAB_600adf84;
    local_1c = local_1c - 2;
  }
  local_21 = '\x01';
LAB_600adf84:
  if (*(short *)(param_1 + 0x32) == 0) {
    local_21 = '\x01';
  }
  if (local_21 == '\0') {
    local_28 = FUN_600f6158(param_1,param_2,*(undefined2 *)(param_1 + 0x34));
    if (local_28 == 0) {
      local_21 = -0x80;
    }
    else {
      FUN_600f6ee2(param_1);
      for (local_1c = 0; local_1c < *(ushort *)(param_1 + 0x32); local_1c = local_1c + 1) {
        local_2c = FUN_6006dbac(0x262,DAT_600ae0d8,0x1c2);
        if (local_2c == 0) {
          local_21 = -0x80;
          FUN_600adc88(param_1);
          break;
        }
        thunk_EXT_FUN_0000b5ba(local_2c,0,0x262);
        local_1a = *(short *)((local_1c + 0x18) * 2 + param_1 + 4);
        local_22 = FUN_600afb50(local_1a);
        *(short *)(local_2c + 2) = local_1a;
        local_21 = FUN_600f5478(param_1,*(undefined4 *)
                                         ((uint)local_22 * 0x28 + DAT_600ae0d4 + 0xa84),param_2,
                                local_1a,0,local_2c + 9,local_2c + 6,600,local_2d,local_2e,local_28)
        ;
        if (local_21 == '\0') {
          FUN_600f622a(param_1,*(undefined1 *)((uint)local_22 * 0x28 + DAT_600ae0d4 + 0xaa8),
                       local_28,param_2,0,local_2c);
        }
        FUN_6006ddd8(local_2c,DAT_600ae0d8,0x1db);
      }
    }
  }
  if (((local_21 != '\0') && (local_21 != -0x78)) && (local_21 != -0x7c)) {
    FUN_600f6be6(param_1,local_21,param_2,local_1a,0);
  }
  return;
}


