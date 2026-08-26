// 60131e14  FUN_60131e14  size=340 bytes
// --- callers ---
// --- callees ---


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x60131e7e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_60131e14(int param_1,byte *param_2)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  uint extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  uint unaff_r8;
  undefined4 unaff_r11;
  undefined4 extraout_r12;
  undefined4 in_cr15;
  undefined8 in_d7;
  undefined8 in_d16;
  undefined8 uVar12;
  
  iVar5 = DAT_6013204c;
  iVar11 = *DAT_60132004;
  pbVar9 = param_2 + 0x148;
  uVar8 = (uint)*DAT_6013200c;
  uVar6 = *DAT_60132014;
  uVar3 = (uint)uVar6;
  if (param_1 == 1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 == 4) goto LAB_60131eee;
  if ((param_1 != 8) || (*(int *)DAT_60132014 == 0x26)) {
    return uVar3;
  }
  bVar1 = param_2[0x149];
  uVar7 = (uint)bVar1 << 0x1f;
  if (uVar7 == 0) {
    uVar7 = (uint)*(ushort *)(param_2 + 0x150);
    if ((uVar7 == uVar8) && (uVar7 = (uint)*(ushort *)(param_2 + 0x154), uVar7 == uVar8)) {
      coprocessor_moveto2(0xc,0xf,&stack0xffffffe8,8,in_cr15);
      *(ushort *)(uVar3 + 0x10) = uVar6;
      uVar7 = uVar3 << 9;
    }
    bVar1 = *param_2;
    if (*(char *)(DAT_601324c4 + 9) != '\0') {
      if (bVar1 == 0xff) {
        uVar6 = *(ushort *)(param_2 + 0x14a) & 0xff | (ushort)param_2[1] << 8;
        uVar4 = 0x61;
      }
      else {
        uVar6 = *(ushort *)(param_2 + 0x14a) & 0xff | (ushort)bVar1 << 8;
        uVar4 = 0x5f;
      }
      FUN_600b4e8a(uVar4,uVar6);
      uVar7 = extraout_r2;
    }
    uVar8 = 0;
    if (uVar3 != 0) {
      iVar5 = FUN_600f4ff4(uVar3,*(undefined4 *)(param_2 + 0x14c));
      uVar8 = 0;
      uVar7 = extraout_r2_00;
      if (iVar5 != 0) {
        if ((*DAT_601324c8 != 0x26) || (bVar1 < 0xe)) {
          uVar12 = FUN_6010d090(*(undefined4 *)(param_2 + 0x14c));
          param_2 = (byte *)0x0;
          if ((int)uVar12 != 0) {
            coprocessor_moveto2(0xe,0xf,unaff_r11,extraout_r12,in_cr15);
            iVar5 = (extraout_r2_02 >> 0x14) << 0x1b;
            SignedSaturate(iVar5,0x18);
            SignedDoesSaturate(iVar5,0x18);
            *(short *)(iVar11 + (int)((ulonglong)uVar12 >> 0x20)) = (short)pbVar9;
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
        }
        uVar8 = func_0x600e63d0(uVar3,bVar1);
        uVar7 = extraout_r2_01;
      }
    }
    *(uint *)(uVar7 + 0x1c) = uVar8;
    *(int *)((uVar8 ^ (uint)param_2) + 4) = iVar11;
    return uVar8 ^ (uint)param_2;
  }
  _Reserved4 = uVar8;
  if ((bVar1 & 2) != 0) {
    iVar10 = unaff_r8 + ((unaff_r8 >> 0x14 & 1) != 0);
    iVar11 = iVar10 + -8;
    *(int *)pbVar9 = iVar10 * 0x80;
    *(int *)(param_2 + 0x14c) = iVar11;
    *(uint *)(param_2 + 0x150) = uVar7;
    *(uint *)(param_2 + 0x154) = uVar8;
    *(int *)(param_2 + 0x158) = iVar10;
    uVar4 = *(undefined4 *)(param_2 + iVar11);
    *(char *)(iVar5 + 6) = (char)iVar5;
    *(char *)(*(ushort *)(param_2 + 0x184) + 0x11) = (char)uVar4;
    *(char *)((iVar11 * 0x2000 + 0x88 >> 0x13) + 3) = (char)param_2 + '\\';
    param_2[0x18e] = 0x88;
    param_2[399] = 0x1c;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pbVar9 = param_2 + 0x122;
  if (uVar7 == uVar8) {
LAB_60131eca:
    _Reset = 0x20;
  }
  else {
    *(uint *)((uVar3 & 0x1f) * 0x4000 + 0x2c) = uVar8;
    if ((uVar6 & 0x1f) != 0) {
      _UsageFault = 0;
      sVar2 = *(short *)(uVar3 * 0x10);
      *(ushort *)(bVar1 + 0x1c) = (ushort)bVar1 << 1;
      _DAT_01a8000c = (int)sVar2 >> 0xb;
      goto LAB_60131eca;
    }
  }
  _MasterStackPointer = 0;
  _Reset = CONCAT22((short)pbVar9,_Reset);
LAB_60131eee:
  uVar4 = VectorGetElement(in_d7,1,4,0);
  VectorMultiplyAccumulate(in_d16,uVar4,4,1);
  return (int)pbVar9 << 0xb;
}


