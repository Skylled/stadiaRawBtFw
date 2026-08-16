// 600c2a28  FUN_600c2a28  size=270 bytes
// --- callers ---
// --- callees ---
//   6009fae0 FUN_6009fae0
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c2a28(int param_1)

{
  uint uVar1;
  uint auStack_2c [2];
  undefined1 local_21;
  int local_20;
  byte local_19;
  int local_18;
  int local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_19 = 0;
  local_21 = 0;
  local_20 = param_1;
  thunk_EXT_FUN_0000b5ba(auStack_2c,0,8);
  if (*(char *)(local_20 + 0x2c) != '\0') {
    local_14 = local_20 + 0xe;
  }
  if (*(char *)(local_20 + 0x2b) != '\0') {
    local_18 = local_20 + 0x11;
  }
  if (*(char *)(local_20 + 0x28) != '\0') {
    for (; (*(int *)(local_20 + 0x24) != 0 && (local_19 < 0x1f)); local_19 = local_19 + 1) {
      if ((*(uint *)(local_20 + 0x24) & 1 << local_19) != 0) {
        uVar1 = *(uint *)(DAT_600c2b38 + (uint)local_19 * 4) >> 5;
        local_21 = (char)uVar1;
        auStack_2c[uVar1 & 0xff] =
             auStack_2c[uVar1 & 0xff] |
             1 << (*(int *)(DAT_600c2b38 + (uint)local_19 * 4) + (uVar1 & 0xff) * -0x20 & 0xff);
        *(uint *)(local_20 + 0x24) = ~(1 << local_19) & *(uint *)(local_20 + 0x24);
      }
    }
  }
  FUN_6009fae0(local_20 + 8,local_14,local_20 + 0x2d,local_20 + 0x126,auStack_2c,local_18,
               *(undefined1 *)(local_20 + 0x29),*(undefined1 *)(local_20 + 0x2a));
  return;
}


