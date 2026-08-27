// 600cc5ac  FUN_600cc5ac  size=212 bytes
// --- callers ---
//   600ca4ac tasks__600ca4ac
// --- callees ---
//   601016a2 FUN_601016a2
//   600cc518 FUN_600cc518
//   600cc578 FUN_600cc578
//   6013d0a0 thunk_EXT_FUN_000073cc
//   600cc540 FUN_600cc540


/* WARNING: Removing unreachable block (ram,0x600cc668) */

void FUN_600cc5ac(void)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  uint *puVar4;
  int *piVar5;
  uint uVar6;
  undefined1 local_19;
  
  puVar4 = DAT_600cc684;
  pbVar3 = DAT_600cc680;
  bVar1 = *DAT_600cc680;
  *DAT_600cc680 = 0xff;
  local_19 = *pbVar3;
  *DAT_600cc688 = local_19 & 0x50;
  bVar2 = false;
  *puVar4 = 7;
  uVar6 = 7;
  for (; (int)((uint)local_19 << 0x18) < 0; local_19 = local_19 << 1) {
    bVar2 = true;
    uVar6 = uVar6 - 1;
  }
  if (bVar2) {
    *puVar4 = uVar6;
  }
  if (*puVar4 != 3) {
    FUN_601016a2(DAT_600cc690,0x14e,DAT_600cc68c);
  }
  pbVar3 = DAT_600cc680;
  *puVar4 = (*puVar4 & 7) << 8;
  piVar5 = DAT_600cc694;
  *pbVar3 = bVar1;
  puVar4 = DAT_600cc698;
  *DAT_600cc698 = *DAT_600cc698 | 0xf00000;
  *puVar4 = *puVar4 | 0xf0000000;
  FUN_600cc578();
  *piVar5 = 0;
  FUN_600cc540();
  *DAT_600cc69c = *DAT_600cc69c | 0xc0000000;
  FUN_600cc518();
  thunk_EXT_FUN_000073cc();
  if (*piVar5 != -1) {
    FUN_601016a2(DAT_600cc690,0xdd,DAT_600cc68c);
  }
  disableIRQinterrupts();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(0x50);
  }
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  enableIRQinterrupts();
  do {
  } while( true );
}


