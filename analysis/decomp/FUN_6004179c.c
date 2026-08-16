// 6004179c  FUN_6004179c  size=40 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_6004179c(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_600417c4;
  iVar2 = (param_2 + param_1) - (param_1 & 0xffffffe0);
  DataSynchronizationBarrier(0xf);
  for (; 0 < iVar2; iVar2 = iVar2 + -0x20) {
    *(uint *)(iVar1 + 0x25c) = (param_2 + param_1) - iVar2;
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


