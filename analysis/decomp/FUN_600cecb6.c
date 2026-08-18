// 600cecb6  FUN_600cecb6  size=82 bytes
// --- callers ---
//   600cf8de FUN_600cf8de
// --- callees ---


void FUN_600cecb6(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    *(byte *)(*(int *)(param_1 + 8) + 0x1b) = *(byte *)(param_1 + 0x10) & 0x1f;
  }
  else {
    iVar2 = *(int *)(param_1 + 8) + (*(byte *)(param_1 + 0x10) + 0x80) * 0x20;
    *(byte *)(param_1 + 0x15) = *(byte *)(param_1 + 0x15) | 0x80;
    if (*(int *)(iVar2 + 0x18) != 0) {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      if (((1 << (uint)*(byte *)(param_1 + 0x10) & *(uint *)(*(int *)(param_1 + 8) + 0xc)) == 0) &&
         ((-1 < (int)((uint)*(ushort *)(iVar2 + 0x1c) << 0x18) ||
          ((int)((uint)*(ushort *)(iVar2 + 0x1c) << 0x1b) < 0)))) {
        *(byte *)(*(int *)(param_1 + 8) + 0x1b) = *(byte *)(param_1 + 0x10) & 0x1f;
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
  }
  return;
}


