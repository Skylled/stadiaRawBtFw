// 601323f6  FUN_601323f6  size=152 bytes
// --- callers ---
// --- callees ---
//   600f4ff4 FUN_600f4ff4
//   600bc9e4 FUN_600bc9e4
//   600b4e8a FUN_600b4e8a
//   6010d090 FUN_6010d090


/* WARNING: Control flow encountered bad instruction data */

void FUN_601323f6(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ushort uVar7;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  uint extraout_r2_03;
  int iVar8;
  byte *pbVar9;
  undefined4 unaff_r11;
  undefined4 extraout_r12;
  undefined4 in_cr15;
  undefined8 uVar10;
  
  iVar3 = *(int *)(param_1 + 4);
  pbVar9 = (byte *)(iVar3 + 0x10);
  bVar1 = *(byte *)(iVar3 + 0xc);
  iVar4 = FUN_600bc9e4(*(undefined2 *)(param_1 + 2));
  bVar2 = *pbVar9;
  iVar8 = extraout_r2;
  if (*(char *)(DAT_601324c4 + 9) != '\0') {
    if (bVar2 == 0xff) {
      uVar7 = *(ushort *)(param_1 + 2) & 0xff | (ushort)*(byte *)(iVar3 + 0x11) << 8;
      uVar5 = 0x61;
    }
    else {
      uVar7 = *(ushort *)(param_1 + 2) & 0xff | (ushort)bVar2 << 8;
      uVar5 = 0x5f;
    }
    FUN_600b4e8a(uVar5,uVar7);
    iVar8 = extraout_r2_00;
  }
  uVar6 = 0;
  if (iVar4 != 0) {
    iVar3 = FUN_600f4ff4(iVar4,*(undefined4 *)(param_1 + 4));
    uVar6 = 0;
    iVar8 = extraout_r2_01;
    if (iVar3 != 0) {
      if ((*DAT_601324c8 != 0x26) || (bVar2 < 0xe)) {
        uVar10 = FUN_6010d090(*(undefined4 *)(param_1 + 4));
        pbVar9 = (byte *)0x0;
        if ((int)uVar10 != 0) {
          coprocessor_moveto2(0xe,0xf,unaff_r11,extraout_r12,in_cr15);
          iVar8 = (extraout_r2_03 >> 0x14) << 0x1b;
          SignedSaturate(iVar8,0x18);
          SignedDoesSaturate(iVar8,0x18);
          *(short *)((uint)bVar1 + (int)((ulonglong)uVar10 >> 0x20)) = (short)param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
      uVar6 = func_0x600e63d0(iVar4,bVar2);
      iVar8 = extraout_r2_02;
    }
  }
  *(uint *)(iVar8 + 0x1c) = uVar6;
  *(uint *)((uVar6 ^ (uint)pbVar9) + 4) = (uint)bVar1;
  return;
}


