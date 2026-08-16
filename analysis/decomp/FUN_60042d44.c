// 60042d44  FUN_60042d44  size=270 bytes
// --- callers ---
//   60043028 FUN_60043028
// --- callees ---


void FUN_60042d44(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_2c;
  
  puVar2 = DAT_60042e54;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar3 = *DAT_60042e54;
  iVar5 = DAT_60042e58 + uVar3 * 8;
  local_2c = (uint)CONCAT12(*(byte *)(param_1 + 0x21d) & 1 | (*(byte *)(param_1 + 0x21a) & 1) << 1 |
                            (*(byte *)(param_1 + 0x21b) & 1) << 2,
                            CONCAT11(*(byte *)(param_1 + 0x221) & 1 |
                                     (*(byte *)(param_1 + 0x220) & 1) << 1 |
                                     (*(byte *)(param_1 + 0x21f) & 1) << 2 |
                                     (*(byte *)(param_1 + 0x21e) & 1) << 3 |
                                     (*(byte *)(param_1 + 0x222) & 1) << 4 |
                                     (*(byte *)(param_1 + 0x218) & 1) << 5 |
                                     (*(byte *)(param_1 + 0x219) & 1) << 6 |
                                     *(char *)(param_1 + 0x21c) << 7,
                                     *(byte *)(param_1 + 0x210) & 1 |
                                     (*(byte *)(param_1 + 0x211) & 1) << 1 |
                                     (*(byte *)(param_1 + 0x212) & 1) << 2 |
                                     (*(byte *)(param_1 + 0x213) & 1) << 3 |
                                     (*(byte *)(param_1 + 0x216) & 1) << 4 |
                                     (*(byte *)(param_1 + 0x217) & 1) << 5 |
                                     (*(byte *)(param_1 + 0x214) & 1) << 6 |
                                     *(char *)(param_1 + 0x215) << 7));
  *(undefined4 *)(DAT_60042e58 + uVar3 * 8) = param_2;
  *(uint *)(iVar5 + 4) = local_2c;
  *puVar2 = uVar3 + 1 & 0xf;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}


