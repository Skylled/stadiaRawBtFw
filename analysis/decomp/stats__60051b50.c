// 60051b50  stats__60051b50  size=816 bytes
// src: stats.cc
// --- callers ---
//   600ce5cc FUN_600ce5cc
// --- callees ---
//   60050c18 FUN_60050c18
//   60101ba2 FUN_60101ba2
//   600cc450 FUN_600cc450
//   600ce52c FUN_600ce52c
//   600ce440 FUN_600ce440
//   600cc6f0 FUN_600cc6f0
//   600ca72c FUN_600ca72c
//   600ca570 FUN_600ca570
//   600ce488 FUN_600ce488
//   600cc6a0 heap_5_improved__600cc6a0
//   60051a50 FUN_60051a50
//   60101b76 FUN_60101b76
//   60101a64 FUN_60101a64
//   6010138c FUN_6010138c
//   600cc6e4 FUN_600cc6e4
//   600ce4fc FUN_600ce4fc
//   601016f0 FUN_601016f0
//   600ce55c FUN_600ce55c
//   60052200 FUN_60052200


/* src: stats.cc */

uint stats__60051b50(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  uint in_fpscr;
  float fVar15;
  float fVar16;
  uint local_57c;
  undefined2 *local_578;
  undefined4 local_574;
  undefined4 local_570;
  undefined1 local_56c;
  undefined1 local_56b;
  undefined2 local_56a;
  undefined1 local_568;
  int local_468 [2];
  undefined1 *local_460;
  int local_45c;
  int iStack_458;
  undefined1 local_454;
  undefined1 uStack_453;
  undefined1 auStack_452 [554];
  int aiStack_228 [127];
  
  uVar1 = FUN_600ca570();
  piVar7 = local_468;
  if (uVar1 < 0x1f) {
    iVar3 = FUN_600ca72c(piVar7,uVar1,&local_57c);
    piVar12 = piVar7 + iVar3 * 9;
    if (piVar12 != piVar7) {
      FUN_60051a50(piVar7,piVar12,(0x1f - LZCOUNT((iVar3 * 0x24 >> 2) * DAT_60051e70)) * 2,0);
      if (iVar3 * 0x24 < 0x241) {
        FUN_600ce488(piVar7,piVar12);
      }
      else {
        FUN_600ce488(piVar7,aiStack_228);
        for (piVar8 = aiStack_228; piVar12 != piVar8; piVar8 = piVar8 + 9) {
          FUN_600ce440(piVar8);
        }
      }
    }
    uVar2 = DAT_60051e74;
    local_578 = &local_56a;
    local_56a = 0x7d7b;
    local_574 = 0xff;
    local_56c = 0;
    local_56b = 0;
    local_568 = 0;
    local_570 = 2;
    uVar11 = *DAT_60051e78;
    *DAT_60051e78 = local_57c;
    uVar11 = local_57c - uVar11;
    FUN_600ce4fc(&local_578,uVar2);
    FUN_600ce4fc(&local_578,DAT_60051e7c,uVar11);
    uVar1 = FUN_6010138c(param_1,&local_578);
    if ((uVar1 & 0xff) == 0) {
      FUN_60101a64(&local_578);
      local_57c = local_57c / 100;
      uVar11 = uVar11 / 100;
      uVar1 = 0;
      iVar13 = 0;
      iVar14 = 0;
      piVar8 = piVar7;
      for (iVar9 = 0; iVar3 != iVar9; iVar9 = iVar9 + 1) {
        FUN_600cc450(&local_578,DAT_60051e80,piVar8[1]);
        uVar2 = DAT_60051e8c;
        if (*(byte *)(piVar8 + 3) < 5) {
          uVar2 = *(undefined4 *)(DAT_60051e88 + (uint)*(byte *)(piVar8 + 3) * 4);
        }
        FUN_600cc450(&local_578,DAT_60051e84,uVar2);
        FUN_600ce52c(&local_578,DAT_60051e90,(uint)*(ushort *)(piVar8 + 8) << 2);
        FUN_600ce4fc(&local_578,DAT_60051e94,piVar8[5]);
        iVar4 = *(int *)(*piVar8 + 0x44) - piVar8[7];
        if (iVar4 != 0) {
          iVar14 = iVar14 + iVar4;
          iVar13 = iVar13 + (uint)*(ushort *)(piVar8 + 8) * -4 + iVar4;
          FUN_600ce4fc(&local_578,DAT_60051e98);
        }
        FUN_600ce4fc(&local_578,DAT_60051e9c,piVar8[6]);
        if (uVar11 != 0) {
          iVar4 = uVar1 << 3;
          while( true ) {
            uVar5 = ((int *)(DAT_60051ec4 + iVar4))[1];
            if ((uVar5 == 0) || ((uint)piVar8[2] <= uVar5)) break;
            iVar4 = iVar4 + 8;
            if (0x1d < uVar1) goto LAB_60051d9e;
            uVar1 = uVar1 + 1;
          }
          if (uVar5 == piVar8[2]) {
            iVar4 = *(int *)(DAT_60051ec4 + iVar4);
          }
          else {
LAB_60051d9e:
            iVar4 = 0;
          }
          fVar16 = (float)VectorSignedToFloat(uVar11,(byte)(in_fpscr >> 0x16) & 3);
          fVar15 = (float)VectorUnsignedToFloat(piVar8[6] - iVar4,(byte)(in_fpscr >> 0x16) & 3);
          FUN_600ce55c(fVar15 / fVar16,&local_578,DAT_60051ea0);
        }
        if (local_57c != 0) {
          fVar16 = (float)VectorUnsignedToFloat(piVar8[6],(byte)(in_fpscr >> 0x16) & 3);
          fVar15 = (float)VectorUnsignedToFloat(local_57c,(byte)(in_fpscr >> 0x16) & 3);
          FUN_600ce55c(fVar16 / fVar15,&local_578,DAT_60051ea4);
        }
        uVar5 = FUN_6010138c(param_1,&local_578);
        piVar8 = piVar8 + 9;
        if ((uVar5 & 0xff) != 0) {
          return uVar5;
        }
        FUN_60101a64(&local_578);
      }
      FUN_600ce4fc(&local_578,DAT_60051ea8,iVar14);
      FUN_600ce4fc(&local_578,DAT_60051eac,iVar13);
      uVar1 = FUN_6010138c(param_1,&local_578);
      if ((uVar1 & 0xff) == 0) {
        FUN_60101a64(&local_578);
        uVar2 = FUN_60052200();
        FUN_600ce52c(&local_578,DAT_60051eb0,uVar2);
        uVar2 = FUN_600cc6e4();
        FUN_600ce52c(&local_578,DAT_60051eb4,uVar2);
        uVar1 = FUN_6010138c(param_1,&local_578);
        if ((uVar1 & 0xff) == 0) {
          FUN_60101a64(&local_578);
          iVar3 = FUN_60052200();
          iVar13 = FUN_600cc6f0();
          FUN_600ce52c(&local_578,DAT_60051eb8,iVar3 - iVar13);
          uVar1 = FUN_6010138c(param_1,&local_578);
          if ((uVar1 & 0xff) == 0) {
            FUN_60101a64(&local_578);
            uVar2 = heap_5_improved__600cc6a0();
            FUN_600ce52c(&local_578,DAT_60051ebc,uVar2);
            uVar1 = FUN_6010138c(param_1,&local_578);
            if ((uVar1 & 0xff) == 0) {
              FUN_60101a64(&local_578);
              iVar3 = DAT_60051ec0;
              for (; piVar12 != piVar7; piVar7 = piVar7 + 9) {
                iVar13 = piVar7[2];
                *(int *)(iVar3 + -8) = piVar7[6];
                *(int *)(iVar3 + -4) = iVar13;
                iVar3 = iVar3 + 8;
              }
              puVar6 = (undefined4 *)(DAT_60051ee4 + 0xf8);
              puVar10 = (undefined4 *)(DAT_60051ee4 + iVar9 * 8);
              while (puVar6 != puVar10 + 2) {
                *puVar10 = 0;
                puVar10[1] = 0;
                puVar10 = puVar10 + 2;
              }
              uVar1 = 0;
            }
          }
        }
      }
    }
  }
  else {
    local_468[0] = DAT_60051e64;
    local_454 = 0;
    local_468[1] = 0x2f4;
    local_460 = auStack_452;
    uStack_453 = 0;
    auStack_452[0] = 0;
    local_45c = 0x80;
    iStack_458 = 0;
    FUN_60101b76(&local_460,DAT_60051e68);
    uVar2 = FUN_60050c18(uVar1,0,local_460 + iStack_458,local_45c - iStack_458);
    FUN_60101ba2(&local_460,uVar2);
    FUN_60101b76(&local_460,DAT_60051e6c);
    uVar2 = FUN_60050c18(0x1e,0,local_460 + iStack_458,local_45c - iStack_458);
    FUN_60101ba2(&local_460,uVar2);
    FUN_601016f0(0x28,local_468[0],local_468[1],&local_460);
    uVar1 = 9;
  }
  return uVar1;
}


