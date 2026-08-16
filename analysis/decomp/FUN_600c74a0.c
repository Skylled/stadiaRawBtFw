// 600c74a0  FUN_600c74a0  size=980 bytes
// --- callers ---
//   600f2532 FUN_600f2532
//   600ff888 FUN_600ff888
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c74a0(char *param_1,undefined1 param_2)

{
  byte *local_67c;
  byte abStack_678 [36];
  int aiStack_654 [200];
  int aiStack_334 [200];
  byte local_13;
  ushort local_12;
  ushort local_10;
  byte local_d;
  ushort local_c;
  byte local_a;
  byte local_9;
  
  local_10 = 0;
  local_12 = 0;
  thunk_EXT_FUN_0000b5ba(abStack_678 + 0xc,0,0x658);
  thunk_EXT_FUN_0000b5ba(abStack_678,0,10);
  abStack_678[0xc] = *param_1;
  if (*param_1 == '\0') {
    abStack_678[0xd] = param_1[1];
    local_67c = (byte *)(param_1 + 2);
    if (abStack_678[0xd] < 0xb) {
      local_d = abStack_678[0xd];
    }
    else {
      local_d = 10;
    }
    for (local_9 = 0; local_9 < local_d; local_9 = local_9 + 1) {
      abStack_678[local_9 + 0xe] = *local_67c;
      local_67c = local_67c + 1;
    }
    for (local_9 = local_d; local_9 < abStack_678[0xd]; local_9 = local_9 + 1) {
      local_13 = *local_67c;
      local_67c = local_67c + 1;
    }
    for (local_9 = 0; local_9 < local_d; local_9 = local_9 + 1) {
      abStack_678[local_9 + 0x18] = *local_67c;
      local_67c = local_67c + 1;
      local_10 = local_10 + abStack_678[local_9 + 0x18];
      if (abStack_678[local_9 + 0x18] < 0x15) {
        abStack_678[local_9] = abStack_678[local_9 + 0x18];
      }
      else {
        abStack_678[local_9] = 0x14;
      }
      local_12 = local_12 + abStack_678[local_9];
    }
    for (local_9 = local_d; local_9 < abStack_678[0xd]; local_9 = local_9 + 1) {
      local_13 = *local_67c;
      local_67c = local_67c + 1;
      local_10 = local_10 + local_13;
    }
    local_c = 0;
    for (local_9 = 0; local_9 < local_d; local_9 = local_9 + 1) {
      for (local_a = 0; local_a < abStack_678[local_9]; local_a = local_a + 1) {
        aiStack_654[local_c] =
             (uint)*local_67c + (uint)local_67c[1] * 0x100 + (uint)local_67c[2] * 0x10000 +
             (uint)local_67c[3] * 0x1000000;
        local_67c = local_67c + 4;
        local_c = local_c + 1;
      }
      for (local_a = abStack_678[local_9]; local_a < abStack_678[local_9 + 0x18];
          local_a = local_a + 1) {
        local_67c = local_67c + 4;
      }
    }
    for (local_c = local_12; local_c < local_10; local_c = local_c + 1) {
      local_67c = local_67c + 4;
    }
    local_c = 0;
    for (local_9 = 0; local_9 < local_d; local_9 = local_9 + 1) {
      for (local_a = 0; local_a < abStack_678[local_9]; local_a = local_a + 1) {
        aiStack_654[local_c + 200] =
             (uint)*local_67c + (uint)local_67c[1] * 0x100 + (uint)local_67c[2] * 0x10000 +
             (uint)local_67c[3] * 0x1000000;
        local_67c = local_67c + 4;
        local_c = local_c + 1;
      }
      for (local_a = abStack_678[local_9]; local_a < abStack_678[local_9 + 0x18];
          local_a = local_a + 1) {
        local_67c = local_67c + 4;
      }
    }
  }
  if (*(int *)(DAT_600c7874 + 0x7fc) != 0) {
    (**(code **)(DAT_600c7874 + 0x7fc))(8,param_2,abStack_678 + 0xc);
  }
  return;
}


