// 600ccfb4  FUN_600ccfb4  size=1568 bytes
// --- callers ---
//   600ccc10 FUN_600ccc10
// --- callees ---
//   600cd9bc FUN_600cd9bc
//   600cda48 FUN_600cda48


uint FUN_600ccfb4(float *param_1,float *param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  float **ppfVar2;
  byte bVar3;
  bool bVar4;
  float *pfVar5;
  uint uVar6;
  float *pfVar7;
  float **ppfVar8;
  undefined4 *puVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  float *pfVar15;
  float *pfVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint in_fpscr;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  longlong lVar26;
  uint uVar27;
  float *local_17c [21];
  float local_128 [20];
  float local_d8 [20];
  float local_88 [21];
  float **ppfVar9;
  
  fVar21 = DAT_600cd2a0;
  iVar19 = param_4 + -1;
  iVar13 = param_3 + -3;
  if (iVar13 < 0) {
    iVar13 = param_3 + 4;
  }
  local_17c[0] = param_2;
  uVar14 = iVar13 >> 3 & ~(iVar13 >> 0x1f);
  iVar18 = *(int *)(DAT_600cd294 + param_5 * 4);
  param_3 = param_3 + (uVar14 + 1) * -8;
  iVar13 = uVar14 - iVar19;
  if (-1 < iVar18 + iVar19) {
    iVar12 = iVar18 + iVar19 + iVar13;
    pfVar16 = local_128;
    do {
      fVar23 = DAT_600cd298;
      if (-1 < iVar13) {
        fVar23 = (float)VectorSignedToFloat(*(undefined4 *)(param_6 + iVar13 * 4),
                                            (byte)(in_fpscr >> 0x16) & 3);
      }
      iVar13 = iVar13 + 1;
      *pfVar16 = fVar23;
      pfVar16 = pfVar16 + 1;
    } while (iVar13 != iVar12 + 1);
  }
  if (-1 < iVar18) {
    pfVar5 = local_128 + param_4;
    pfVar16 = local_88;
    do {
      pfVar7 = pfVar5;
      pfVar11 = param_1;
      fVar23 = DAT_600cd298;
      if (-1 < iVar19) {
        do {
          pfVar15 = pfVar11 + 1;
          fVar23 = fVar23 + *pfVar11 * pfVar7[-1];
          pfVar7 = pfVar7 + -1;
          pfVar11 = pfVar15;
        } while (pfVar15 != param_1 + param_4);
      }
      *pfVar16 = fVar23;
      pfVar16 = pfVar16 + 1;
      pfVar5 = pfVar5 + 1;
    } while (pfVar16 != local_88 + iVar18 + 1);
  }
  ppfVar2 = local_17c + 1;
  lVar26 = (ulonglong)(uint)DAT_600cd29c << 0x20;
  iVar13 = iVar18;
LAB_600cd088:
  iVar12 = iVar13;
  fVar23 = local_88[iVar12];
  fVar25 = (float)((ulonglong)lVar26 >> 0x20);
  if (0 < iVar12) {
    pfVar16 = local_88 + iVar12;
    ppfVar8 = ppfVar2;
    do {
      pfVar16 = pfVar16 + -1;
      fVar24 = (float)VectorSignedToFloat((int)(fVar23 * fVar21),(byte)(in_fpscr >> 0x16) & 3);
      fVar22 = fVar23 + -fVar24 * fVar25;
      fVar23 = fVar24 + *pfVar16;
      *ppfVar8 = (float *)(int)fVar22;
      ppfVar8 = ppfVar8 + 1;
    } while (pfVar16 != local_88);
  }
  fVar23 = (float)FUN_600cda48(param_3);
  fVar22 = (float)FUN_600cd9bc(fVar23 * 0.125);
  fVar23 = fVar23 + -fVar22 * 8.0;
  uVar27 = (uint)fVar23;
  fVar22 = (float)VectorSignedToFloat(uVar27,(byte)(in_fpscr >> 0x16) & 3);
  fVar23 = fVar23 - fVar22;
  lVar26 = CONCAT44(fVar25,fVar23);
  if (param_3 < 1) {
    if (param_3 == 0) {
      iVar13 = (int)ppfVar2[iVar12 + -1] >> 8;
      goto LAB_600cd12a;
    }
    uVar6 = in_fpscr & 0xfffffff;
    uVar1 = uVar6 | (uint)(fVar23 < 0.5) << 0x1f;
    in_fpscr = uVar1 | (uint)NAN(fVar23) << 0x1c;
    if ((byte)(uVar1 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
      uVar27 = uVar27 + 1;
      if (0 < iVar12) {
        iVar13 = 2;
        goto LAB_600cd142;
      }
      lVar26 = CONCAT44(fVar25,1.0 - fVar23);
      iVar13 = 2;
      goto LAB_600cd192;
    }
    in_fpscr = uVar6 | (uint)(fVar23 == 0.0) << 0x1e;
    bVar3 = (byte)(in_fpscr >> 0x18);
    iVar13 = 0;
  }
  else {
    iVar13 = (int)ppfVar2[iVar12 + -1] >> (8U - param_3 & 0xff);
    pfVar16 = (float *)((int)ppfVar2[iVar12 + -1] - (iVar13 << (8U - param_3 & 0xff)));
    ppfVar2[iVar12 + -1] = pfVar16;
    uVar27 = uVar27 + iVar13;
    iVar13 = (int)pfVar16 >> (7U - param_3 & 0xff);
LAB_600cd12a:
    if (0 < iVar13) {
      uVar27 = uVar27 + 1;
      if (iVar12 < 1) {
        bVar4 = false;
      }
      else {
LAB_600cd142:
        if (local_17c[1] == (float *)0x0) {
          bVar4 = false;
          if (iVar12 != 1) {
            iVar20 = 1;
            ppfVar8 = ppfVar2;
            do {
              ppfVar8 = ppfVar8 + 1;
              iVar17 = iVar20 + 1;
              pfVar16 = *ppfVar8;
              if (*ppfVar8 != (float *)0x0) goto LAB_600cd25c;
              bVar4 = false;
              iVar20 = iVar17;
            } while (iVar12 != iVar17);
          }
        }
        else {
          iVar17 = 1;
          iVar20 = 0;
          pfVar16 = local_17c[1];
LAB_600cd25c:
          ppfVar2[iVar20] = (float *)(0x100 - (int)pfVar16);
          if (iVar17 < iVar12) {
            pfVar16 = ppfVar2[iVar17];
            ppfVar8 = ppfVar2 + iVar17;
            while( true ) {
              ppfVar9 = ppfVar8 + 1;
              *ppfVar8 = (float *)(0xff - (int)pfVar16);
              if (ppfVar9 == ppfVar2 + iVar12) break;
              pfVar16 = *ppfVar9;
              ppfVar8 = ppfVar9;
            }
          }
          bVar4 = true;
        }
      }
      if (0 < param_3) {
        if (param_3 == 1) {
          ppfVar2[iVar12 + -1] = (float *)((uint)ppfVar2[iVar12 + -1] & 0x7f);
        }
        else if (param_3 == 2) {
          ppfVar2[iVar12 + -1] = (float *)((uint)ppfVar2[iVar12 + -1] & 0x3f);
        }
      }
      if (iVar13 == 2) {
        lVar26 = CONCAT44(fVar25,1.0 - fVar23);
        if (bVar4) {
          fVar22 = (float)FUN_600cda48(param_3);
          lVar26 = CONCAT44(fVar25,(1.0 - fVar23) - fVar22);
        }
      }
    }
LAB_600cd192:
    in_fpscr = in_fpscr & 0xfffffff | (uint)((float)lVar26 == 0.0) << 0x1e;
    bVar3 = (byte)(in_fpscr >> 0x18);
  }
  if (bVar3 >> 6 == 0) {
    fVar21 = (float)FUN_600cda48((int)lVar26,-param_3);
    uVar14 = in_fpscr & 0xfffffff | (uint)(fVar21 < DAT_600cd29c) << 0x1f;
    in_fpscr = uVar14 | (uint)(NAN(fVar21) || NAN(DAT_600cd29c)) << 0x1c;
    if ((byte)(uVar14 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
      param_3 = param_3 + 8;
      fVar23 = (float)VectorSignedToFloat((int)(fVar21 * DAT_600cd2a0),(byte)(in_fpscr >> 0x16) & 3)
      ;
      ppfVar2[iVar12] = (float *)(int)(fVar21 + -fVar23 * DAT_600cd29c);
      ppfVar2[iVar12 + 1] = (float *)(int)fVar23;
      iVar20 = iVar12 + 1;
    }
    else {
      ppfVar2[iVar12] = (float *)(int)fVar21;
      iVar20 = iVar12;
    }
    goto LAB_600cd31c;
  }
  iVar20 = iVar12 + -1;
  if (iVar18 <= iVar20) {
    uVar6 = 0;
    ppfVar8 = ppfVar2 + iVar12 + 0x3fffffff;
    do {
      ppfVar9 = ppfVar8 + -1;
      uVar6 = uVar6 | (uint)*ppfVar8;
      ppfVar8 = ppfVar9;
    } while (ppfVar9 != local_17c + iVar18);
    if (uVar6 != 0) goto LAB_600cd3ec;
  }
  if (ppfVar2[iVar18 + -1] == (float *)0x0) {
    iVar13 = 1;
    ppfVar8 = ppfVar2 + iVar18 + -2;
    do {
      pfVar16 = *ppfVar8;
      iVar13 = iVar13 + 1;
      ppfVar8 = ppfVar8 + -1;
    } while (pfVar16 == (float *)0x0);
  }
  else {
    iVar13 = 1;
  }
  iVar13 = iVar13 + iVar12;
  iVar20 = iVar12 + 1;
  if (iVar20 <= iVar13) {
    puVar10 = (undefined4 *)(param_6 + (iVar20 + uVar14 + 0x3fffffff) * 4);
    pfVar5 = local_88 + iVar20;
    pfVar16 = local_128 + param_4 + iVar12;
    do {
      puVar10 = puVar10 + 1;
      fVar25 = (float)VectorSignedToFloat(*puVar10,(byte)(in_fpscr >> 0x16) & 3);
      *pfVar16 = fVar25;
      pfVar11 = pfVar16 + 1;
      pfVar7 = param_1;
      fVar23 = DAT_600cd298;
      if (-1 < iVar19) {
        while( true ) {
          fVar23 = fVar23 + *pfVar7 * fVar25;
          if (pfVar7 + 1 == param_1 + param_4) break;
          pfVar16 = pfVar16 + -1;
          fVar25 = *pfVar16;
          pfVar7 = pfVar7 + 1;
        }
      }
      *pfVar5 = fVar23;
      pfVar5 = pfVar5 + 1;
      pfVar16 = pfVar11;
    } while (puVar10 != (undefined4 *)(param_6 + (uVar14 + iVar13) * 4));
  }
  goto LAB_600cd088;
LAB_600cd3ec:
  param_3 = param_3 + -8;
  if (ppfVar2[iVar20] == (float *)0x0) {
    ppfVar8 = ppfVar2 + iVar12 + 0x3ffffffe;
    do {
      pfVar16 = *ppfVar8;
      iVar20 = iVar20 + -1;
      param_3 = param_3 + -8;
      ppfVar8 = ppfVar8 + -1;
    } while (pfVar16 == (float *)0x0);
  }
LAB_600cd31c:
  fVar23 = (float)FUN_600cda48(0x3f800000,param_3);
  fVar21 = DAT_600cd600;
  if (iVar20 < 0) {
    switch(param_5) {
    case 0:
      break;
    case 1:
    case 2:
      goto switchD_600cd3ae_caseD_1;
    case 3:
      goto switchD_600cd3ae_caseD_3;
    default:
      goto switchD_600cd3ae_default;
    }
  }
  else {
    pfVar5 = local_88 + iVar20;
    pfVar16 = local_88 + iVar20 + 1;
    ppfVar8 = ppfVar2 + iVar20 + 1;
    do {
      ppfVar8 = ppfVar8 + -1;
      fVar25 = (float)VectorSignedToFloat(*ppfVar8,(byte)(in_fpscr >> 0x16) & 3);
      fVar25 = fVar25 * fVar23;
      fVar23 = fVar23 * DAT_600cd2a0;
      pfVar16 = pfVar16 + -1;
      *pfVar16 = fVar25;
    } while (ppfVar8 != ppfVar2);
    iVar19 = 0;
    pfVar16 = local_d8;
    do {
      while (iVar18 < 0) {
        iVar19 = iVar19 + 1;
        *pfVar16 = DAT_600cd600;
        pfVar16 = pfVar16 + 1;
        pfVar5 = pfVar5 + -1;
        if (iVar19 == iVar20 + 1) goto LAB_600cd3a8;
      }
      iVar12 = 0;
      pfVar7 = DAT_600cd5fc;
      pfVar11 = pfVar5;
      fVar23 = DAT_600cd2a4;
      fVar25 = DAT_600cd600;
      while( true ) {
        fVar22 = *pfVar11;
        pfVar11 = pfVar11 + 1;
        iVar12 = iVar12 + 1;
        fVar25 = fVar25 + fVar22 * fVar23;
        if ((iVar18 < iVar12) || (iVar19 < iVar12)) break;
        fVar23 = *pfVar7;
        pfVar7 = pfVar7 + 1;
      }
      iVar19 = iVar19 + 1;
      *pfVar16 = fVar25;
      pfVar16 = pfVar16 + 1;
      pfVar5 = pfVar5 + -1;
    } while (iVar19 != iVar20 + 1);
LAB_600cd3a8:
    switch(param_5) {
    case 0:
      pfVar16 = local_d8 + iVar20 + 1;
      do {
        pfVar16 = pfVar16 + -1;
        fVar21 = fVar21 + *pfVar16;
      } while (local_d8 != pfVar16);
      break;
    case 1:
    case 2:
switchD_600cd3ae_caseD_1:
      if (iVar20 < 0) {
        if (iVar13 != 0) goto LAB_600cd5a8;
LAB_600cd424:
        *local_17c[0] = fVar21;
        local_d8[0] = local_d8[0] - fVar21;
        if (0 < iVar20) {
LAB_600cd436:
          pfVar16 = local_d8;
          iVar19 = 1;
          do {
            pfVar16 = pfVar16 + 1;
            iVar19 = iVar19 + 1;
            local_d8[0] = local_d8[0] + *pfVar16;
          } while (iVar19 <= iVar20);
          if (iVar13 != 0) goto LAB_600cd5c0;
        }
      }
      else {
        pfVar16 = local_d8 + iVar20 + 1;
        do {
          pfVar16 = pfVar16 + -1;
          fVar21 = fVar21 + *pfVar16;
        } while (local_d8 != pfVar16);
        if (iVar13 == 0) goto LAB_600cd424;
LAB_600cd5a8:
        local_d8[0] = local_d8[0] - fVar21;
        *local_17c[0] = -fVar21;
        if (0 < iVar20) goto LAB_600cd436;
LAB_600cd5c0:
        local_d8[0] = -local_d8[0];
      }
      local_17c[0][1] = local_d8[0];
      goto switchD_600cd3ae_default;
    case 3:
switchD_600cd3ae_caseD_3:
      if (0 < iVar20) {
        pfVar16 = local_d8 + iVar20;
        fVar23 = local_d8[iVar20];
        do {
          pfVar5 = pfVar16 + -1;
          fVar22 = *pfVar5;
          fVar25 = fVar22 + fVar23;
          *pfVar5 = fVar25;
          *pfVar16 = (fVar22 - fVar25) + fVar23;
          pfVar16 = pfVar5;
          fVar23 = fVar25;
        } while (local_d8 != pfVar5);
        if (1 < iVar20) {
          pfVar16 = local_d8 + iVar20 + 0x40000000;
          fVar23 = local_d8[iVar20];
          do {
            pfVar5 = pfVar16 + -1;
            fVar22 = *pfVar5;
            fVar25 = fVar22 + fVar23;
            *pfVar5 = fVar25;
            *pfVar16 = (fVar22 - fVar25) + fVar23;
            pfVar16 = pfVar5;
            fVar23 = fVar25;
          } while (local_d8 + 1 != pfVar5);
          pfVar16 = local_d8 + iVar20 + 0x40000001;
          do {
            pfVar16 = pfVar16 + -1;
            fVar21 = fVar21 + *pfVar16;
          } while (local_d8 + 2 != pfVar16);
        }
      }
      if (iVar13 != 0) {
        local_d8[0] = -local_d8[0];
        local_d8[1] = -local_d8[1];
        fVar21 = -fVar21;
      }
      *local_17c[0] = local_d8[0];
      local_17c[0][1] = local_d8[1];
      local_17c[0][2] = fVar21;
    default:
      goto switchD_600cd3ae_default;
    }
  }
  if (iVar13 != 0) {
    fVar21 = -fVar21;
  }
  *local_17c[0] = fVar21;
switchD_600cd3ae_default:
  return uVar27 & 7;
}


