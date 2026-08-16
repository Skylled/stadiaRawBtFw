// 600cdfb4  FUN_600cdfb4  size=540 bytes
// --- callers ---
//   600cddc8 FUN_600cddc8
// --- callees ---
//   6010265c FUN_6010265c
//   6004c620 FUN_6004c620


uint FUN_600cdfb4(undefined4 param_1,uint *param_2,undefined4 param_3,code *param_4,int *param_5)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint local_24 [2];
  
  puVar2 = DAT_600ce1d0;
  puVar12 = (undefined1 *)((int)param_2 + 0x43);
  bVar1 = (byte)param_2[6];
  if (bVar1 == 0x6e) {
    puVar9 = (undefined4 *)*param_5;
    uVar5 = *param_2;
    uVar8 = param_2[5];
    *param_5 = (int)(puVar9 + 1);
    puVar6 = (uint *)*puVar9;
    if (((int)(uVar5 << 0x18) < 0) || (-1 < (int)(uVar5 << 0x19))) {
      *puVar6 = uVar8;
    }
    else {
      *(short *)puVar6 = (short)uVar8;
    }
LAB_600ce150:
    param_2[4] = 0;
    goto LAB_600ce0cc;
  }
  if (bVar1 < 0x6f) {
    if (bVar1 != 99) {
      if (bVar1 < 100) {
        if (bVar1 == 0) goto LAB_600ce150;
        if (bVar1 != 0x58) goto LAB_600cdfe4;
        *(undefined1 *)((int)param_2 + 0x45) = 0x58;
LAB_600ce0f0:
        uVar5 = *param_2;
        uVar8 = *(uint *)*param_5;
        *param_5 = (int)((uint *)*param_5 + 1);
        if ((-1 < (int)(uVar5 << 0x18)) && ((int)(uVar5 << 0x19) < 0)) {
          uVar8 = uVar8 & 0xffff;
        }
        if ((int)(uVar5 << 0x1f) < 0) {
          *param_2 = uVar5 | 0x20;
        }
        if (uVar8 == 0) {
          *param_2 = *param_2 & 0xffffffdf;
        }
        uVar5 = 0x10;
LAB_600ce086:
        *(undefined1 *)((int)param_2 + 0x43) = 0;
      }
      else {
        if ((bVar1 != 100) && (bVar1 != 0x69)) goto LAB_600cdfe4;
        uVar5 = *param_2;
        puVar6 = (uint *)*param_5;
        if ((int)(uVar5 << 0x18) < 0) {
          uVar8 = *puVar6;
          *param_5 = (int)(puVar6 + 1);
        }
        else {
          uVar8 = *puVar6;
          *param_5 = (int)(puVar6 + 1);
          if ((uVar5 & 0x40) != 0) {
            uVar8 = (uint)(short)uVar8;
          }
        }
        if ((int)uVar8 < 0) {
          uVar8 = -uVar8;
          *(undefined1 *)((int)param_2 + 0x43) = 0x2d;
        }
        uVar5 = 10;
        puVar2 = DAT_600ce1d0;
      }
      uVar10 = param_2[1];
      param_2[2] = uVar10;
      puVar11 = puVar12;
      if ((int)uVar10 < 0) {
        if (uVar8 != 0) goto LAB_600ce120;
LAB_600ce1c4:
        *(undefined1 *)((int)param_2 + 0x42) = *puVar2;
        puVar11 = (undefined1 *)((int)param_2 + 0x42);
      }
      else {
        *param_2 = *param_2 & 0xfffffffb;
        if (uVar8 == 0) {
          if (uVar10 != 0) goto LAB_600ce1c4;
        }
        else {
LAB_600ce120:
          do {
            uVar10 = uVar8 / uVar5;
            puVar11 = puVar11 + -1;
            *puVar11 = puVar2[uVar8 - uVar5 * uVar10];
            uVar8 = uVar10;
          } while (uVar10 != 0);
        }
      }
      if (((uVar5 == 8) && ((int)(*param_2 << 0x1f) < 0)) && ((int)param_2[1] <= (int)param_2[4])) {
        puVar11[-1] = 0x30;
        puVar11 = puVar11 + -1;
      }
      param_2[4] = (int)puVar12 - (int)puVar11;
      puVar12 = puVar11;
      goto LAB_600ce0cc;
    }
    uVar7 = *(undefined4 *)*param_5;
    *param_5 = (int)((undefined4 *)*param_5 + 1);
    *(char *)((int)param_2 + 0x42) = (char)uVar7;
LAB_600ce054:
    puVar12 = (undefined1 *)((int)param_2 + 0x42);
    uVar8 = 1;
  }
  else {
    if (bVar1 != 0x73) {
      if (bVar1 < 0x74) {
        if (bVar1 == 0x6f) {
LAB_600ce066:
          puVar6 = (uint *)*param_5;
          uVar8 = *param_2;
          *param_5 = (int)(puVar6 + 1);
          if (((int)(uVar8 << 0x18) < 0) || (-1 < (int)(uVar8 << 0x19))) {
            uVar8 = *puVar6;
          }
          else {
            uVar8 = (uint)(ushort)*puVar6;
          }
          puVar2 = DAT_600ce1d0;
          if (bVar1 == 0x6f) {
            uVar5 = 8;
          }
          else {
            uVar5 = 10;
          }
          goto LAB_600ce086;
        }
        if (bVar1 == 0x70) {
          *param_2 = *param_2 | 0x20;
LAB_600ce03a:
          *(undefined1 *)((int)param_2 + 0x45) = 0x78;
          puVar2 = DAT_600ce1d4;
          goto LAB_600ce0f0;
        }
      }
      else {
        if (bVar1 == 0x75) goto LAB_600ce066;
        if (bVar1 == 0x78) goto LAB_600ce03a;
      }
LAB_600cdfe4:
      *(byte *)((int)param_2 + 0x42) = bVar1;
      goto LAB_600ce054;
    }
    puVar9 = (undefined4 *)*param_5;
    *param_5 = (int)(puVar9 + 1);
    puVar12 = (undefined1 *)*puVar9;
    iVar3 = FUN_6004c620(puVar12,0,param_2[1]);
    if (iVar3 != 0) {
      param_2[1] = iVar3 - (int)puVar12;
    }
    uVar8 = param_2[1];
  }
  param_2[4] = uVar8;
  *(undefined1 *)((int)param_2 + 0x43) = 0;
LAB_600ce0cc:
  iVar3 = FUN_6010265c(param_1,param_2,local_24,param_3,param_4);
  if ((iVar3 == -1) || (iVar3 = (*param_4)(param_1,param_3,puVar12,param_2[4]), iVar3 == -1)) {
LAB_600ce0e0:
    uVar8 = 0xffffffff;
  }
  else {
    if ((int)(*param_2 << 0x1e) < 0) {
      for (iVar3 = 0; iVar3 < (int)(param_2[3] - local_24[0]); iVar3 = iVar3 + 1) {
        iVar4 = (*param_4)(param_1,param_3,(int)param_2 + 0x19,1);
        if (iVar4 == -1) goto LAB_600ce0e0;
      }
    }
    uVar8 = param_2[3];
    if ((int)param_2[3] < (int)local_24[0]) {
      uVar8 = local_24[0];
    }
  }
  return uVar8;
}


