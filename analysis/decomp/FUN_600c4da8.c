// 600c4da8  FUN_600c4da8  size=1030 bytes
// --- callers ---
// --- callees ---
//   600a1354 FUN_600a1354
//   600f04ba FUN_600f04ba
//   600945f8 FUN_600945f8
//   6009470c FUN_6009470c
//   60095bbc FUN_60095bbc
//   600c3e84 FUN_600c3e84
//   600d9250 FUN_600d9250
//   6009633c FUN_6009633c
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600efcc6 FUN_600efcc6
//   600d9246 FUN_600d9246
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f16ae FUN_600f16ae
//   60096314 FUN_60096314
//   60099d18 FUN_60099d18
//   600efcfe FUN_600efcfe
//   6006ddd8 FUN_6006ddd8
//   60099d64 FUN_60099d64
//   600c53f8 FUN_600c53f8


void FUN_600c4da8(int param_1)

{
  int iVar1;
  undefined1 auStack_130 [6];
  undefined1 local_12a;
  char local_129;
  undefined1 local_128;
  int local_18;
  int local_14;
  int local_10;
  char local_a;
  byte local_9;
  
  local_a = *(char *)(param_1 + 10);
  local_10 = param_1 + 0xc;
  thunk_EXT_FUN_0000b5ba(auStack_130,0,0x118);
  if (*(char *)(param_1 + 8) == '\x04') {
    FUN_60095bbc(local_10);
  }
  else {
    if (local_a == '\0') {
      local_9 = 0;
LAB_600c5090:
      if (local_9 < *(byte *)(DAT_600c51b8 + 0xe4)) {
        iVar1 = FUN_600efcfe((uint)local_9 * 0x20 + DAT_600c5088 + 4,local_10);
        if ((iVar1 != 0) ||
           (*(char *)((uint)local_9 * 0x20 + DAT_600c5088 + 0x22) != *(char *)(param_1 + 0x16)))
        goto LAB_600c4ffa;
        local_129 = *(char *)((uint)local_9 * 0x20 + DAT_600c5088 + 0x1e);
        while (local_14 = FUN_600d9250((uint)local_9 * 0x20 + DAT_600c5088 + 0x10), local_14 != 0) {
          FUN_6006ddd8(local_14,DAT_600c508c,0xe03);
        }
        local_14 = 0;
        for (; local_9 < *(byte *)(DAT_600c5088 + 0xe4); local_9 = local_9 + 1) {
          thunk_EXT_FUN_0000b572
                    ((uint)local_9 * 0x20 + DAT_600c5088 + 4,(local_9 + 1) * 0x20 + DAT_600c5088 + 4
                     ,0x20);
        }
      }
      if (*(char *)(DAT_600c51b8 + 0xe4) != '\0') {
        *(char *)(DAT_600c51b8 + 0xe4) = *(char *)(DAT_600c51b8 + 0xe4) + -1;
      }
      if ((*(char *)(param_1 + 0x16) == '\x02') && (*(char *)(DAT_600c51b8 + 0xe5) != '\0')) {
        *(char *)(DAT_600c51b8 + 0xe5) = *(char *)(DAT_600c51b8 + 0xe5) + -1;
      }
      local_128 = *(undefined1 *)(param_1 + 0x16);
      if (((*(char *)(DAT_600c51bc + 0x13c) != '\0') &&
          (iVar1 = FUN_600efcfe(DAT_600c51c0,local_10), iVar1 == 0)) &&
         (*(undefined1 *)(DAT_600c51bc + 0x13c) = 0, *(char *)(DAT_600c51bc + 0x13d) != '\0')) {
        FUN_6009633c(DAT_600c51c4);
        FUN_600c3e84();
      }
      if ((*(char *)(DAT_600c51b8 + 0x108) != '\0') && (iVar1 = FUN_60099d18(), iVar1 == 0)) {
        FUN_6009633c(DAT_600c51c8);
        *(undefined4 *)(DAT_600c51b8 + 0x114) = DAT_600c51cc;
        FUN_60096314(DAT_600c51c8,0,0x78);
      }
      if (local_129 != '\0') {
        FUN_600f16ae(local_10);
        FUN_600945f8(0,local_10,0);
        FUN_6009470c(local_10);
      }
      FUN_600efcc6(auStack_130,local_10);
      local_12a = FUN_60099d64();
      if (*(int *)(DAT_600c51b8 + 0xe8) != 0) {
        (**(code **)(DAT_600c51b8 + 0xe8))(6,auStack_130);
      }
      goto LAB_600c51a6;
    }
    local_9 = 0;
    while ((local_9 < *(byte *)(DAT_600c5088 + 0xe4) &&
           ((iVar1 = FUN_600efcfe((uint)local_9 * 0x20 + DAT_600c5088 + 4,local_10), iVar1 != 0 ||
            (*(short *)((uint)local_9 * 0x20 + DAT_600c5088 + 0x20) != *(short *)(param_1 + 0x14))))
           )) {
      local_9 = local_9 + 1;
    }
    if (local_9 == *(byte *)(DAT_600c5088 + 0xe4)) {
      if (6 < *(byte *)(DAT_600c5088 + 0xe4)) {
        return;
      }
      FUN_600efcc6((uint)*(byte *)(DAT_600c5088 + 0xe4) * 0x20 + DAT_600c5088 + 4,local_10);
      *(undefined2 *)((uint)*(byte *)(DAT_600c5088 + 0xe4) * 0x20 + DAT_600c5088 + 10) =
           *(undefined2 *)(DAT_600c5088 + 0x240);
      *(char *)(DAT_600c5088 + 0xe4) = *(char *)(DAT_600c5088 + 0xe4) + '\x01';
      *(undefined2 *)((uint)local_9 * 0x20 + DAT_600c5088 + 0x20) = *(undefined2 *)(param_1 + 0x14);
      if (*(char *)(param_1 + 0x16) == '\x02') {
        *(char *)(DAT_600c5088 + 0xe5) = *(char *)(DAT_600c5088 + 0xe5) + '\x01';
      }
    }
    *(undefined1 *)((uint)local_9 * 0x20 + DAT_600c5088 + 0xc) = 1;
    *(undefined1 *)((uint)local_9 * 0x20 + DAT_600c5088 + 0xd) = 0;
    FUN_600efcc6(auStack_130,local_10);
    *(undefined1 *)((uint)local_9 * 0x20 + DAT_600c5088 + 0xf) = 0;
    FUN_600d9246((uint)local_9 * 0x20 + DAT_600c5088 + 0x10);
    local_12a = *(undefined1 *)(param_1 + 0x16);
    *(undefined1 *)((uint)local_9 * 0x20 + DAT_600c5088 + 0x22) = *(undefined1 *)(param_1 + 0x16);
    local_18 = FUN_600a1354();
    if ((((local_18 != 0) && ((*(byte *)(local_18 + 5) & 2) != 0)) &&
        (local_18 = FUN_600f04ba(local_10), local_18 != 0)) && ((*(byte *)(local_18 + 5) & 2) != 0))
    {
      *(undefined1 *)((uint)local_9 * 0x20 + DAT_600c5088 + 0xf) = 0x10;
    }
    if (*(int *)(DAT_600c5088 + 0xe8) != 0) {
      (**(code **)(DAT_600c5088 + 0xe8))(5,auStack_130);
    }
LAB_600c51a6:
    FUN_600c53f8();
  }
  return;
LAB_600c4ffa:
  local_9 = local_9 + 1;
  goto LAB_600c5090;
}


