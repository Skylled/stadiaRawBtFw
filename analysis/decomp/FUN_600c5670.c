// 600c5670  FUN_600c5670  size=198 bytes
// --- callers ---
// --- callees ---
//   600efcfe FUN_600efcfe
//   6006dfa4 FUN_6006dfa4
//   6006dbac FUN_6006dbac
//   600f1b72 FUN_600f1b72


void FUN_600c5670(int param_1)

{
  int iVar1;
  byte local_9;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    local_9 = 0;
    while ((local_9 < *(byte *)(DAT_600c5738 + 0xe4) &&
           ((iVar1 = FUN_600efcfe((uint)local_9 * 0x20 + DAT_600c5738 + 4,param_1 + 0x11),
            iVar1 != 0 || (*(char *)((uint)local_9 * 0x20 + DAT_600c5738 + 0xc) != '\x01'))))) {
      local_9 = local_9 + 1;
    }
    if (local_9 < *(byte *)(DAT_600c5738 + 0xe4)) {
      iVar1 = FUN_6006dbac(8,DAT_600c573c,0x1419);
      if (iVar1 == 0) {
        (**(code **)(param_1 + 0xc))(param_1 + 0x11,*(undefined1 *)(param_1 + 8),4);
      }
      else {
        *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 0xc);
        FUN_6006dfa4((uint)local_9 * 0x20 + DAT_600c5738 + 0x10,iVar1);
        FUN_600f1b72(param_1 + 0x11,*(undefined1 *)(param_1 + 8),DAT_600c5740,param_1 + 0x10);
      }
    }
  }
  return;
}


