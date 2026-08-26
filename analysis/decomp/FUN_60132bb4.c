// 60132bb4  FUN_60132bb4  size=548 bytes
// --- callers ---
// --- callees ---
//   600b4ec2 FUN_600b4ec2
//   600b4ed0 FUN_600b4ed0
//   6006d076 FUN_6006d076
//   600ed66e FUN_600ed66e


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x60133330) */
/* WARNING: Removing unreachable block (ram,0x601332c6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_60132bb4(byte *param_1,uint param_2,byte *param_3,byte *param_4)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  byte *extraout_r2;
  byte *extraout_r2_00;
  byte *extraout_r2_01;
  byte *extraout_r2_02;
  byte *extraout_r2_03;
  byte *pbVar8;
  byte *extraout_r3;
  uint extraout_r3_00;
  undefined4 uVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  undefined4 uVar17;
  byte *pbVar18;
  int iVar19;
  int iVar20;
  undefined4 in_r12;
  undefined4 extraout_r12;
  undefined4 extraout_r12_00;
  undefined4 extraout_r12_01;
  undefined4 extraout_r12_02;
  undefined4 extraout_r12_03;
  byte **ppbVar21;
  int unaff_lr;
  bool bVar22;
  char cVar23;
  undefined4 in_cr7;
  undefined4 in_cr9;
  undefined4 in_cr15;
  int in_stack_000003a0;
  undefined1 auStack_1fc [448];
  undefined4 local_3c;
  undefined4 *puStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  byte *pbStack_2c;
  byte *local_28;
  byte *pbStack_24;
  
  pbVar18 = DAT_60132ebc;
  ppbVar21 = &local_28;
  puStack_38 = (undefined4 *)0x0;
  pbVar8 = param_3;
  local_28 = param_3;
  pbStack_24 = param_4;
  if (DAT_60132ebc[9] != 0) {
    FUN_600b4ec2(99,(uint)param_1[0xda] | (param_1[0x13e] & 7) << 8 | (param_2 & 0x1f) << 0xb);
    unaff_lr = 0x60132beb;
    puStack_38 = (undefined4 *)FUN_600b4ec2(0x62,1);
    pbVar8 = extraout_r2;
    param_4 = extraout_r3;
    in_r12 = extraout_r12;
  }
  pbVar15 = (byte *)0x0;
  cVar23 = SBORROW4(param_2,8);
  bVar22 = (int)(param_2 - 8) < 0;
  switch(param_2) {
  case 0:
    puStack_38 = (undefined4 *)(uint)param_1[0x13e];
    cVar23 = '\0';
    if (puStack_38 == (undefined4 *)0x0) {
      puStack_38 = (undefined4 *)FUN_600ed66e(param_1);
      pbVar8 = extraout_r2_00;
      in_r12 = extraout_r12_00;
    }
    break;
  case 1:
    pbStack_2c = pbVar18;
    uStack_30 = 0xffffff08;
    uStack_34 = 0x60132d04;
    local_3c = 0x60132d04;
    pbVar18[(int)param_4] = pbVar18[(int)param_4];
    uVar4 = *(uint *)(in_stack_000003a0 + 4);
    uVar14 = *(uint *)(in_stack_000003a0 + 8);
    iVar20 = *(int *)(in_stack_000003a0 + 0x10);
    iVar6 = (int)pbVar8 >> (uVar4 & 0xff);
    iVar19 = *(int *)((uVar14 >> 0x10) + 4);
    if (iVar6 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    while( true ) {
      if (*(char *)(uVar14 + 0x2e) == '\x01') {
        func_0x600fad24(1,(int)pbVar8 << 3,iVar6,uVar4 << 8);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (uVar14 << 4 == 0) break;
      *(char *)(iVar19 + 0x2f) = (char)(uVar14 << 4);
      if ((*(char *)(uVar4 + 0x5f) == '\0') || (*(char *)(uVar4 + 0x5f) == '\x01')) {
        *(uint *)(uVar4 + 0x3c) = *(uint *)(uVar4 + 0x3c) | 0x2000000;
      }
    }
    piVar10 = (int *)(iVar20 * 0x800);
    if (uVar4 >> 3 == 0xffffffdf) {
      *(int *)iVar6 = iVar6;
      iVar6 = DAT_60133500;
      *(undefined1 *)(iVar20 * 0x801) = 0;
      bRam00000003 = 0;
      piVar5 = (int *)*piVar10;
      uVar4 = piVar10[1];
      iVar19 = piVar10[2];
      iVar20 = piVar10[3];
      uVar14 = piVar10[4];
      *(char *)(piVar10[5] * 2) = (char)piVar5;
      *piVar5 = (int)piVar5;
      *(short *)(iVar19 + 8) = (short)piVar5;
      *(short *)(iVar20 + 10) = (short)piVar5;
      *piVar5 = (uVar4 | uVar14) + 0x20;
      piVar5[1] = iVar6;
      piVar5[2] = uVar14;
      software_bkpt(0xf7);
      *(short *)((int)piVar5 + 0x26) = (short)((uint)(piVar5 + 3) >> 1);
      *(char *)(((int)uVar14 >> 0x1f) * 0x80001) = (char)(piVar5 + 3);
                    /* WARNING: Could not recover jumptable at 0x60133174. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*(code *)(unaff_lr + 0x60133178))(0x28,((int)uVar14 >> 0x1f) << 3);
      return uVar4;
    }
    *(char *)(uVar4 * 8 + uVar14 + 0x1b) = (char)iVar20;
    *(undefined4 *)(*(int *)(iVar6 + 0x10) + 0x7c) = *(undefined4 *)(iVar6 + 0x14);
    return 0x60132d04;
  case 2:
switchD_60132bf2_caseD_2:
    cVar23 = SBORROW4((int)puStack_38 * 0x200000,0xf8);
    break;
  case 3:
    if (param_1[0x13e] != 0) {
      if (param_1[0xd9] == 0) {
        puStack_38 = (undefined4 *)func_0x600e7124(param_1,0x23,0xf);
        pbVar8 = extraout_r2_02;
        in_r12 = extraout_r12_02;
        break;
      }
      param_1[0x13e] = 0;
      if (pbVar18[9] != 0) {
        FUN_600b4ec2(99,param_1[0xda] + 0x5000);
      }
    }
    puStack_38 = (undefined4 *)func_0x600ed38e(param_1,param_3);
    pbVar8 = extraout_r2_01;
    in_r12 = extraout_r12_01;
    break;
  case 4:
    uVar3 = (ushort)param_1[0x13e];
    if (param_1[0x13e] != 1) {
      func_0x600e7124(param_1,0x24,0x10);
      param_1[0x13e] = 0;
      pbVar8 = extraout_r2_03;
      if (pbVar18[9] == 0) {
        puStack_38 = (undefined4 *)0x0;
        in_r12 = extraout_r12_03;
        goto switchD_60132bf2_caseD_2;
      }
      coprocessor_moveto2(6,0xf,param_3,extraout_r12_03,in_cr15);
      *(uint *)((extraout_r3_00 >> 0x14) + 0x60) = extraout_r3_00 >> 0x14;
      param_4 = (byte *)0x0;
      uVar3 = 0x20;
      param_1 = (byte *)(uint)bRam00000003;
      ppbVar21 = (byte **)auStack_1fc;
    }
    *(ushort *)(param_1 + 0x10) = uVar3;
    cVar23 = SBORROW4(0,(int)pbVar18);
    pbVar18 = (byte *)-(int)pbVar18;
    puStack_38 = (undefined4 *)&DAT_00000046;
    bVar22 = false;
  case 5:
    pbVar15 = (byte *)(((uint)puStack_38 >> 0x10) << 0x18 | ((uint)puStack_38 >> 0x18) << 0x10 |
                       ((uint)puStack_38 & 0xff) << 8 | (uint)puStack_38 >> 8 & 0xff);
    if (pbVar18 != (byte *)0x0) goto LAB_60132cda;
    ppbVar21[0xe0] = param_1;
    do {
      pbVar16 = pbVar15;
      pbVar15 = pbVar16 + -0xf8;
      bVar22 = (int)pbVar8 << 0xf < 0;
      sVar2 = *(short *)param_1;
      ppbVar21[0xd1] = param_1;
    } while (bVar22 == SBORROW4((int)pbVar16,0xf8));
    if (bVar22) {
      pbVar18 = (byte *)0xf7;
    }
    ppbVar21[-1] = pbVar18;
    ppbVar21[-2] = pbVar15;
    ppbVar21[-3] = (byte *)0x0;
    ppbVar21[-4] = param_1;
    ppbVar21[-5] = param_4;
    ppbVar21 = ppbVar21 + -6;
    *ppbVar21 = (byte *)(int)sVar2;
    pbRam0000005c = pbVar8;
    *(short *)(pbVar16 + -0xf2) = (short)param_1;
switchD_60132bf2_caseD_6:
    ppbVar21[0xe0] = (byte *)0x60132e3c;
    cVar23 = SBORROW4((int)pbVar15,0xf8);
    do {
      puStack_38 = (undefined4 *)&DAT_00000046;
      bVar22 = false;
switchD_60132bf2_caseD_7:
      pbVar15 = (byte *)(((uint)puStack_38 >> 0x10) << 0x18 | ((uint)puStack_38 >> 0x18) << 0x10 |
                         ((uint)puStack_38 & 0xff) << 8 | (uint)puStack_38 >> 8 & 0xff);
      param_1 = (byte *)coprocessor_movefromRt(7,7,7,in_cr7,in_cr9);
LAB_60132cda:
      ppbVar21[0xe0] = param_1;
    } while (bVar22 == (bool)cVar23);
    if (bVar22 != false) {
      pbVar18 = pbVar15 + -7;
    }
    while( true ) {
      uVar7 = *puStack_38;
      ppbVar21[0xb3] = param_1;
      if ((int)puStack_38 < 0x7a) break;
      puStack_38 = (undefined4 *)&DAT_00000055;
      _DAT_00000075 = 0x55;
      pbVar15 = pbVar15 + -0xf8;
    }
    *(undefined1 **)(pbVar8 + 0x10) = (undefined1 *)((int)puStack_38 + -0x7a);
    *ppbVar21 = param_1;
    *(short *)pbVar8 = (short)uVar7;
    *(byte **)(pbVar15 + -0xe0) = pbVar8;
    bVar1 = pbVar15[-0xf5];
    ppbVar21[0xf5] = (byte *)0x20;
    _DAT_00000054 = 0x400;
    *(undefined2 *)(bVar1 + 8) = 0x20;
    pbVar18 = pbVar18 + 0x3fc;
    coprocessor_loadlong(4,in_cr9,pbVar18);
    _Reserved2 = 0x400;
    iVar6 = (int)(pbVar15 + -0x1f0) >> 0xe;
    pbVar15[-0x1e1] = (byte)pbVar18;
    uVar7 = DAT_601332f8;
    ppbVar21[-1] = pbVar18;
    ppbVar21[-2] = pbVar15 + -0x1f0;
    ppbVar21[-3] = (byte *)0x0;
    ppbVar21[-4] = (byte *)(uint)bVar1;
    ppbVar21[-5] = (byte *)((uint)(pbVar15 + -0xf8) >> 0xb);
    ppbVar21[-6] = pbVar8;
    ppbVar21[-7] = &DAT_60132f54;
    puVar11 = &DAT_60132f5c;
    do {
      uVar9 = *puVar11;
      puVar12 = (undefined4 *)puVar11[1];
      uVar13 = puVar11[2];
      uVar17 = puVar11[3];
      iVar19 = (int)puVar12 << 3;
      puVar12[8] = iVar6;
      *(undefined2 *)(puVar12 + 2) = 0xfc;
      puVar11 = puVar12;
    } while (-1 < iVar19);
    ppbVar21[-8] = (byte *)iVar19;
    ppbVar21[-9] = (byte *)uVar17;
    ppbVar21[-10] = (byte *)uVar13;
    ppbVar21[-0xb] = (byte *)puVar12;
    ppbVar21[-0xc] = (byte *)uVar9;
    ppbVar21[-0xd] = (byte *)uVar7;
    ppbVar21[-0xe] = (byte *)iVar6;
    ppbVar21[-0xf] = (byte *)0xfc;
    ppbVar21[-0x10] = (byte *)iVar19;
    ppbVar21[-0x11] = (byte *)uVar13;
    ppbVar21[-0x12] = (byte *)puVar12;
    ppbVar21[-0x13] = (byte *)0xfc;
                    /* WARNING: Could not recover jumptable at 0x60132f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)ppbVar21[-0x10])(0x1b1,ppbVar21[-0x13],ppbVar21[-0x12]);
    return uVar4;
  case 6:
    goto switchD_60132bf2_caseD_6;
  case 7:
    goto switchD_60132bf2_caseD_7;
  }
  do {
    iVar6 = (int)puStack_38 * 0x10000;
    puStack_38 = (undefined4 *)((uint)pbVar8 >> 0x13);
    bVar1 = *param_1;
    *(byte **)(pbVar18 + iVar6) = pbVar8;
  } while (cVar23 == '\0');
  *(undefined4 **)(pbVar8 + 0x10) = puStack_38;
  pbVar8[0] = 0;
  pbVar8[1] = 0;
  coprocessor_moveto2(1,0xf,param_3,in_r12,in_cr15);
  local_28 = param_1;
  FUN_600b4ed0(99,((int)(short)(ushort)((uint)pbVar8 >> 0x13) & 0xffff00ffU) + 0x4800);
  if (param_1[0x13e] == 0) {
    FUN_600b4ed0(0x62,0);
  }
  if ((*(short *)(param_1 + 0x46) != 0) && (*(short *)(param_1 + 0x44) == 0)) {
    FUN_6006d076(param_1);
  }
  return (uint)bVar1;
}


