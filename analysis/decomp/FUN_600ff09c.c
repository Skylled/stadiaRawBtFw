// 600ff09c  FUN_600ff09c  size=346 bytes
// --- callers ---
//   600959cc FUN_600959cc
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ab110 FUN_600ab110
//   600efa30 FUN_600efa30
//   600ef9bc FUN_600ef9bc
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600ff09c(int param_1,int param_2)

{
  undefined1 local_28 [2];
  short local_26;
  int local_24;
  undefined1 local_20;
  byte local_14;
  byte local_13;
  short local_12;
  
  local_12 = 0;
  local_20 = 0x85;
  local_13 = FUN_600efa30(param_1,*(undefined1 *)(param_2 + 8));
  if (local_13 != 0xff) {
    local_14 = FUN_600ef9bc(param_1,local_13);
    if (local_14 != 0xff) {
      local_12 = FUN_600ab110(*(undefined1 *)((uint)local_13 * 0x20 + param_1 + 0x20),param_2 + 0xc,
                              *(undefined1 *)(param_2 + 0x22),*(undefined2 *)(param_2 + 0x20),
                              *(undefined1 *)(param_2 + 0x23));
      if (local_12 == 0) {
        local_28[0] = 0x85;
        thunk_EXT_FUN_0000b5ba((uint)local_14 * 0x1c + param_1 + 0x144,0,0x1c);
      }
      else {
        thunk_EXT_FUN_0000b572((uint)local_14 * 0x1c + param_1 + 0x144,param_2 + 0xc,0x14);
        *(short *)((uint)local_14 * 0x1c + param_1 + 0x158) = local_12;
        *(undefined1 *)((uint)local_14 * 0x1c + param_1 + 0x15a) = *(undefined1 *)(param_2 + 0x22);
        *(byte *)((uint)local_14 * 0x1c + param_1 + 0x15c) = local_14;
        local_20 = 0;
        local_26 = local_12;
        local_24 = (uint)local_14 * 0x1c + param_1 + 0x144;
        local_28[0] = *(undefined1 *)((uint)local_13 * 0x20 + param_1 + 0x20);
      }
    }
    if (*(int *)((uint)local_13 * 0x20 + param_1 + 0x1c) != 0) {
      (**(code **)((uint)local_13 * 0x20 + param_1 + 0x1c))(7,local_28);
    }
  }
  return;
}


