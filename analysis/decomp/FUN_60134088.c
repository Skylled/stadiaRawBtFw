// 60134088  FUN_60134088  size=158 bytes
// --- callers ---
// --- callees ---
//   60134126 FUN_60134126


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_60134088(undefined4 *param_1)

{
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r3;
  int extraout_r3_00;
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *unaff_r9;
  undefined4 extraout_r12;
  uint uVar6;
  undefined4 in_cr15;
  int in_stack_00000170;
  undefined4 in_stack_000001d8;
  
  uVar2 = 1;
  func_0x60101468();
  coprocessor_moveto2(2,0xf,extraout_r3,extraout_r12,in_cr15);
  iVar4 = 0;
  uVar1 = 0;
  if ((uint)param_1 >> 0x14 != 0) {
    uVar6 = 9;
    iVar5 = param_1[1];
    *(short *)(extraout_r3 + 2) = (short)(extraout_r1 << 1);
    iVar4 = _DAT_00000240;
    iVar5 = iVar5 + -0x29;
    software_interrupt(0x78);
    uVar3 = uVar6;
    if (SCARRY4(iVar5,extraout_r3)) {
      do {
        iVar5 = *(int *)(iVar5 << 3);
        *(short *)(uVar6 + 6) = (short)extraout_r3;
        uVar3 = ((uint)&stack0x00000168 & 0xfffffff) >> 5;
        *(short *)(in_stack_00000170 + 10) = (short)uVar3;
        uVar6 = 0;
      } while (uVar3 == 0);
      *(int *)(iVar5 * 0x800) = iVar4;
      ((int *)(iVar5 * 0x800))[1] = iVar5;
    }
    iVar5 = *unaff_r9;
    *(short *)(*(ushort *)(iVar5 + 0xe) + 6) = (short)iVar5;
    *(undefined4 *)(iVar4 + 0x10) = 0;
    *(undefined4 *)(iVar4 + 0x10) = 0;
    iVar4 = *(int *)(iVar5 + 4);
    uVar1 = *(undefined4 *)(iVar5 + 8);
    uVar6 = *(uint *)(iVar5 + 0xc);
    *(int *)iVar4 = iVar4;
    *(int *)(iVar4 + 4) = iVar5 + 0x10;
    *(undefined2 **)(iVar4 + 8) = (undefined2 *)(uVar3 * 8);
    *(undefined4 *)(iVar4 + 0xc) = uVar1;
    *(uint *)(iVar4 + 0x10) = uVar6;
    *(undefined4 *)(iVar4 + 0x14) = 0xf0e8bdb0;
    *(int *)iVar4 = iVar4;
    *(undefined2 *)(uVar3 * 8) = (short)iVar4;
    *(undefined4 *)(uVar6 + 0x7c) = 0xf0e8bdb0;
    (*(code *)0x60134126)(iVar4,uVar6,0x875168f8,uVar6 >> 0x13);
    *(short *)(extraout_r3_00 + 4) = (short)extraout_r1_00;
    *(undefined4 *)(uVar6 + 0x3c) = 0xf0e8bdb0;
    uVar1 = *(undefined4 *)(extraout_r1_00 + 0xc);
    param_1 = *(undefined4 **)(extraout_r1_00 + 0x10);
    uVar2 = *(undefined4 *)(extraout_r1_00 + 0x14);
    iVar4 = *(int *)(extraout_r1_00 + 0x18);
  }
  *param_1 = uVar1;
  param_1[1] = param_1;
  param_1[2] = uVar2;
  param_1[3] = iVar4;
  return iVar4 >> 7;
}


