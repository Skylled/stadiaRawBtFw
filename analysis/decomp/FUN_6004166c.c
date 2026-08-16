// 6004166c  FUN_6004166c  size=94 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_6004166c(void)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  uint unaff_lr;
  int iVar7;
  undefined4 unaff_s16;
  undefined4 unaff_s17;
  undefined4 unaff_s18;
  undefined4 unaff_s19;
  undefined4 unaff_s20;
  undefined4 unaff_s21;
  undefined4 unaff_s22;
  undefined4 unaff_s23;
  undefined4 unaff_s24;
  undefined4 unaff_s25;
  undefined4 unaff_s26;
  undefined4 unaff_s27;
  undefined4 unaff_s28;
  undefined4 unaff_s29;
  undefined4 unaff_s30;
  undefined4 unaff_s31;
  
  puVar2 = _DAT_600416cc;
  puVar3 = (undefined4 *)getProcessStackPointer();
  InstructionSynchronizationBarrier(0xf);
  puVar6 = (undefined4 *)*_DAT_600416cc;
  puVar4 = puVar3;
  if ((unaff_lr & 0x10) == 0) {
    puVar4 = puVar3 + -0x10;
    *puVar4 = unaff_s16;
    puVar3[-0xf] = unaff_s17;
    puVar3[-0xe] = unaff_s18;
    puVar3[-0xd] = unaff_s19;
    puVar3[-0xc] = unaff_s20;
    puVar3[-0xb] = unaff_s21;
    puVar3[-10] = unaff_s22;
    puVar3[-9] = unaff_s23;
    puVar3[-8] = unaff_s24;
    puVar3[-7] = unaff_s25;
    puVar3[-6] = unaff_s26;
    puVar3[-5] = unaff_s27;
    puVar3[-4] = unaff_s28;
    puVar3[-3] = unaff_s29;
    puVar3[-2] = unaff_s30;
    puVar3[-1] = unaff_s31;
  }
  puVar4[-1] = unaff_lr;
  puVar4[-2] = unaff_r11;
  puVar4[-3] = unaff_r10;
  puVar4[-4] = unaff_r9;
  puVar4[-5] = unaff_r8;
  puVar4[-6] = unaff_r7;
  puVar4[-7] = unaff_r6;
  puVar4[-8] = unaff_r5;
  puVar4[-9] = unaff_r4;
  *puVar6 = puVar4 + -9;
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x50);
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  enableIRQinterrupts();
  func_0x60047be8(0x50);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  iVar5 = *(int *)*puVar2;
  iVar7 = iVar5 + 0x24;
  if ((*(uint *)(iVar5 + 0x20) & 0x10) == 0) {
    iVar7 = iVar5 + 100;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(iVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return iVar7;
}


