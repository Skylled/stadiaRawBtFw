// 60060040  FUN_60060040  size=122 bytes
// --- callers ---
//   6006efd4 FUN_6006efd4
//   60071624 FUN_60071624
// --- callees ---
//   6005ff5c platform__6005ff5c
//   600d49e4 FUN_600d49e4


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60060040(int param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  int *in_stack_00000010;
  
  if (in_stack_00000010 != (int *)0x0) {
    iVar4 = *in_stack_00000010;
    iVar2 = FUN_600d49e4(iVar4 + 0x2c);
    if ((iVar2 == 0) && (uVar3 = (uint)*(short *)(iVar4 + 0x2c), -1 < (int)uVar3)) {
      *(int *)(DAT_600600bc + ((uVar3 >> 5) + 0x20) * 4) = 1 << (uVar3 & 0x1f);
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
    }
    if (*(int *)(iVar4 + 0x34) != 0) {
      uVar3 = *(int *)(iVar4 + 0x34) - 1;
      if (4 < uVar3) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0x600600b8);
        (*pcVar1)();
      }
      iVar2 = *(int *)(DAT_600600c0 + uVar3 * 4);
      *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & ~(1 << (*(uint *)(iVar4 + 0x38) & 0xff));
    }
  }
  iVar2 = platform__6005ff5c(in_stack_00000008,in_stack_0000000c);
  *(int **)(param_1 + iVar2 * 4 + 4) = in_stack_00000010;
  return;
}


