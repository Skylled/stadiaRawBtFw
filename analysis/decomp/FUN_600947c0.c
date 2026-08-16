// 600947c0  FUN_600947c0  size=168 bytes
// --- callers ---
//   600fe05a FUN_600fe05a
// --- callees ---
//   600aa648 FUN_600aa648
//   6006ddd8 FUN_6006ddd8
//   60094754 FUN_60094754
//   6006dbac FUN_6006dbac
//   600d9250 FUN_600d9250


undefined1 FUN_600947c0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_9;
  
  local_9 = 0;
  while (*(int *)(param_1 + 0x14) != 0) {
    uVar1 = FUN_600d9250(param_1 + 0x14);
    FUN_6006ddd8(uVar1,DAT_60094868,0xa0);
  }
  FUN_600aa648(param_1 + 0x28);
  uVar1 = FUN_6006dbac(0x348,DAT_60094868,0xa4);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  if (*(int *)(param_1 + 0x28) == 0) {
    local_9 = 0x80;
  }
  else {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(undefined1 *)(param_1 + 0x2e) = 0;
    *(undefined1 *)(param_1 + 0x2d) = *(undefined1 *)(param_1 + 0x2e);
    *(undefined1 *)(param_1 + 0x2c) = *(undefined1 *)(param_1 + 0x2d);
    iVar2 = FUN_60094754(param_1);
    if (iVar2 == 0) {
      local_9 = 0x80;
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
    }
  }
  return local_9;
}


