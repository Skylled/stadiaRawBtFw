// 6005ebe0  FUN_6005ebe0  size=436 bytes
// --- callers ---
//   6005edb8 FUN_6005edb8
// --- callees ---
//   6005e164 FUN_6005e164
//   6013d000 thunk_EXT_FUN_00007dac
//   60101a64 FUN_60101a64
//   60101a80 FUN_60101a80
//   6013cf40 thunk_EXT_FUN_00007d10
//   60058600 FUN_60058600
//   60083900 FUN_60083900
//   6013d360 thunk_EXT_FUN_00007d64
//   600cdcc4 FUN_600cdcc4
//   6005e8d8 FUN_6005e8d8
//   6005e2a0 FUN_6005e2a0
//   6013cf88 thunk_EXT_FUN_0000b4cc
//   6010138c FUN_6010138c
//   600d460c FUN_600d460c
//   600cc450 FUN_600cc450
//   600585f8 FUN_600585f8


/* WARNING: Type propagation algorithm not settling */

uint FUN_6005ebe0(int param_1)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *******pppppppuVar12;
  undefined4 *******pppppppuVar13;
  int *piVar14;
  uint uVar15;
  undefined4 *******local_58;
  undefined1 local_54;
  undefined *local_50;
  int iStack_4c;
  
  iVar3 = DAT_6005edb0;
  uVar15 = 0;
  do {
    iVar6 = FUN_6005e164(uVar15);
    if (iVar6 == 0) {
      return 0;
    }
    iVar6 = uVar15 + DAT_6005ed94;
    sVar1 = *(short *)(iVar6 + 2);
    *(undefined1 *)(iVar6 + 2) = 0;
    *(undefined1 *)(iVar6 + 3) = 0;
    if (sVar1 == 2) {
      uVar7 = FUN_6005e8d8(param_1,PTR_s_FaultInfo_6005eda0);
      if ((uVar7 & 0xff) != 0) {
        return uVar7;
      }
      uVar7 = FUN_60083900(param_1,uVar15 + iVar3);
      if ((uVar7 & 0xff) != 0) {
        return uVar7;
      }
    }
    else if (sVar1 == 3) {
      uVar7 = FUN_6005e8d8(param_1,PTR_s_PreEscalatedCrashInfo_6005eda4);
      if ((uVar7 & 0xff) != 0) {
        return uVar7;
      }
      uVar10 = FUN_60101a80(*(undefined4 *)(param_1 + 0x14));
      uVar4 = DAT_6005edb4;
      bVar5 = *(byte *)(uVar15 + iVar3);
      iVar8 = 0x1b;
      iVar9 = 0;
      do {
        iVar11 = iVar9 + iVar8 >> 1;
        piVar14 = (int *)(DAT_6005eda8 + iVar11 * 0x1c);
        bVar2 = *(byte *)(DAT_6005eda8 + iVar11 * 0x1c);
        if (bVar5 == bVar2) goto LAB_6005ed0c;
        if (bVar5 < bVar2) {
          iVar8 = iVar11 + -1;
        }
        else {
          iVar9 = iVar11 + 1;
        }
      } while (iVar9 < iVar8);
      if ((bVar5 < *(byte *)(DAT_6005eda8 + iVar9 * 0x1c)) && (iVar9 != 0)) {
        piVar14 = (int *)((iVar9 + -1) * 0x1c + DAT_6005eda8);
      }
      else {
        piVar14 = (int *)(iVar9 * 0x1c + DAT_6005eda8);
      }
LAB_6005ed0c:
      iVar8 = 0;
      FUN_600cc450(uVar10,DAT_6005edac,piVar14[4]);
      do {
        piVar14 = piVar14 + 1;
        iVar11 = *piVar14;
        iVar9 = iVar8 * 4;
        iVar8 = iVar8 + 1;
        pppppppuVar12 = *(undefined4 ********)(uVar15 + iVar3 + iVar9 + 1);
        iVar9 = FUN_600d460c(uVar4,iVar11);
        pppppppuVar13 = pppppppuVar12;
        if (iVar11 == 4) {
          local_54 = 0;
          pppppppuVar13 = &local_58;
          local_58 = pppppppuVar12;
        }
        FUN_600cdcc4(&local_50,0x28,*(undefined4 *)(iVar9 + 8),pppppppuVar13);
        iVar9 = FUN_600d460c(uVar4,*piVar14);
        FUN_600cc450(uVar10,*(undefined4 *)(iVar9 + 4),&local_50);
      } while (iVar8 != 3);
      bVar5 = FUN_6010138c(param_1,uVar10);
      if (bVar5 != 0) {
        return (uint)bVar5;
      }
      FUN_60101a64(uVar10);
    }
    else if (sVar1 == 1) {
      uVar7 = FUN_6005e8d8(param_1,PTR_s_LogBuffer_6005ed98);
      if ((uVar7 & 0xff) != 0) {
        return uVar7;
      }
      thunk_EXT_FUN_00007d64();
      iVar8 = FUN_600585f8();
      iVar9 = thunk_EXT_FUN_0000b4cc(iVar8 + 0x1824,0);
      if (iVar9 == 0) {
        thunk_EXT_FUN_00007dac();
        return 0xe;
      }
      thunk_EXT_FUN_00007d10(iVar8 + 0x1824);
      FUN_6005e2a0(uVar15 + iVar3,iVar8);
      local_50 = PTR_thunk_FUN_600d45ba_1_6005ed9c;
      iStack_4c = param_1;
      FUN_60058600(iVar8,PTR_thunk_FUN_600d45ba_1_6005ed9c,param_1);
      FUN_6005e2a0(uVar15 + iVar3,iVar8);
      thunk_EXT_FUN_00007dac();
    }
    uVar15 = uVar15 + *(ushort *)(iVar6 + 4) + 8;
    if (0x27ff < uVar15) {
      return 0;
    }
  } while( true );
}


