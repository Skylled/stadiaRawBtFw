// 600d0332  FUN_600d0332  size=1244 bytes
// --- callers ---
//   6005505c FUN_6005505c
// --- callees ---
//   600d018c FUN_600d018c
//   600547ac FUN_600547ac
//   600cfe6a FUN_600cfe6a
//   600d0278 FUN_600d0278
//   60054728 FUN_60054728
//   600cfc8e FUN_600cfc8e
//   600d1156 FUN_600d1156
//   600d1134 FUN_600d1134


undefined4 FUN_600d0332(undefined4 *param_1,undefined4 param_2,ushort *param_3)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  code *UNRECOVERED_JUMPTABLE_00;
  int iVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  if ((param_3 == (ushort *)0x0) || (param_1 == (undefined4 *)0x0)) {
    return 3;
  }
  switch(param_2) {
  case 1:
    bVar3 = (*(byte **)param_3)[4];
    if (((*(byte *)((int)param_1 + 0x15) != bVar3) && (*(byte *)((int)param_1 + 0x17) != bVar3)) &&
       (*(byte *)((int)param_1 + 0x19) != bVar3)) {
      return 1;
    }
    bVar3 = **(byte **)param_3;
    if ((bVar3 & 0x1f) != 1) {
      return 1;
    }
    if ((bVar3 & 0x60) != 0x20) {
      return 1;
    }
    if (bVar3 != 0x22) {
      if (bVar3 < 0x23) {
        if (bVar3 != 0x21) {
          return 1;
        }
        uVar2 = *(ushort *)(*(int *)param_3 + 4);
        uVar7 = 1;
        piVar14 = *(int **)(param_1[2] + 0xc);
        for (iVar15 = 0; iVar15 < (int)(uint)*(byte *)(piVar14 + 1); iVar15 = iVar15 + 1) {
          iVar6 = *piVar14;
          if ((ushort)*(byte *)(iVar6 + iVar15 * 4) == uVar2 >> 8) {
            cVar4 = *(char *)(iVar6 + iVar15 * 4 + 1);
            if (cVar4 == '\x03') {
              uVar7 = 1;
            }
            else if (cVar4 == '\x06') {
              uVar7 = FUN_600d018c(param_1,param_3);
            }
          }
        }
        return uVar7;
      }
      if (bVar3 == 0xa1) {
        uVar2 = *(ushort *)(*(int *)param_3 + 4);
        uVar7 = 1;
        piVar14 = *(int **)(param_1[2] + 0xc);
        for (iVar15 = 0; iVar15 < (int)(uint)*(byte *)(piVar14 + 1); iVar15 = iVar15 + 1) {
          iVar6 = *piVar14;
          if ((ushort)*(byte *)(iVar6 + iVar15 * 4) == uVar2 >> 8) {
            cVar4 = *(char *)(iVar6 + iVar15 * 4 + 1);
            if (cVar4 == '\x02') {
              uVar7 = 1;
            }
            else if (cVar4 == '\x06') {
              uVar7 = FUN_600d0278(param_1,param_3);
            }
          }
        }
        return uVar7;
      }
      if (bVar3 != 0xa2) {
        return 1;
      }
      uVar2 = *(ushort *)(*(int *)param_3 + 2) >> 8;
      switch(*(undefined1 *)(*(int *)param_3 + 1)) {
      case 0x81:
        if (uVar2 != 1) {
          return 1;
        }
        uVar7 = 0x810c;
        break;
      case 0x82:
        if (uVar2 != 1) {
          return 1;
        }
        uVar7 = 0x820c;
        break;
      case 0x83:
        if (uVar2 != 1) {
          return 1;
        }
        uVar7 = 0x830c;
        break;
      case 0x84:
        if (uVar2 != 1) {
          return 1;
        }
        uVar7 = 0x840c;
        break;
      default:
        goto switchD_600d022c_default;
      }
      if (((undefined4 *)param_1[1] != (undefined4 *)0x0) &&
         (UNRECOVERED_JUMPTABLE_00 = *(code **)param_1[1], UNRECOVERED_JUMPTABLE_00 != (code *)0x0))
      {
                    /* WARNING: Could not recover jumptable at 0x600d0276. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar7 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar7,param_3);
        return uVar7;
      }
switchD_600d022c_default:
      return 1;
    }
    uVar2 = *(ushort *)(*(int *)param_3 + 2) >> 8;
    switch(*(undefined1 *)(*(int *)param_3 + 1)) {
    case 1:
      if (uVar2 == 1) {
        uVar7 = 0x10c;
      }
      else {
        if (uVar2 != 2) {
          return 1;
        }
        uVar7 = 0x10d;
      }
      break;
    case 2:
      if (uVar2 != 1) {
        return 1;
      }
      uVar7 = 0x20c;
      break;
    case 3:
      if (uVar2 != 1) {
        return 1;
      }
      uVar7 = 0x30c;
      break;
    case 4:
      if (uVar2 != 1) {
        return 1;
      }
      uVar7 = 0x40c;
      break;
    default:
      goto switchD_600d01c4_default;
    }
    if (((undefined4 *)param_1[1] != (undefined4 *)0x0) &&
       (UNRECOVERED_JUMPTABLE_00 = *(code **)param_1[1], UNRECOVERED_JUMPTABLE_00 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x600d01f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar7 = (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar7,param_3);
      return uVar7;
    }
switchD_600d01c4_default:
    return 1;
  case 2:
    *(undefined1 *)(param_1 + 5) = 0;
    *(undefined1 *)(param_1 + 7) = 0;
    *(undefined1 *)((int)param_1 + 0x1b) = 0;
    *(undefined1 *)((int)param_1 + 0x1d) = 0;
    break;
  case 3:
    if ((param_1[1] != 0) && ((char)*param_3 != *(char *)(param_1 + 5))) {
      if (*(char *)(param_1 + 5) != '\0') {
        FUN_600cfe6a();
        if (param_1[3] != 0) {
          FUN_600cfc8e(param_1,param_1 + 3);
        }
        if (param_1[4] != 0) {
          FUN_600cfc8e(param_1,param_1 + 4);
        }
      }
      *(char *)(param_1 + 5) = (char)*param_3;
      *(undefined1 *)((int)param_1 + 0x16) = 0;
      *(undefined1 *)(param_1 + 6) = 0;
      *(undefined1 *)((int)param_1 + 0x1a) = 0;
      param_1[4] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      FUN_600547ac(param_1);
      uVar8 = 3;
      goto LAB_600d03b2;
    }
    break;
  case 4:
    if (param_1[1] != 0) {
      cVar4 = (char)*param_3;
      uVar2 = *param_3 >> 8;
      if (*(byte *)((int)param_1 + 0x15) == uVar2) {
        if (*(char *)((int)param_1 + 0x16) != cVar4) {
          FUN_600cfe6a();
          *(char *)((int)param_1 + 0x16) = cVar4;
          uVar7 = FUN_600547ac(param_1);
          return uVar7;
        }
      }
      else if (*(byte *)((int)param_1 + 0x17) == uVar2) {
        if (*(char *)(param_1 + 6) != cVar4) {
          FUN_600cfc8e(param_1,param_1 + 3);
          *(char *)(param_1 + 6) = cVar4;
          uVar8 = 1;
LAB_600d03b2:
          uVar11 = (uint)*(byte *)(param_1 + 5);
          if (((uVar11 != 0) && (uVar11 <= *(byte *)((int)*(int **)(param_1[1] + 8) + 5))) &&
             (iVar15 = **(int **)(param_1[1] + 8), iVar15 != 0)) {
            bVar5 = false;
            bVar3 = *(byte *)(iVar15 + (uVar11 + 0x1fffffff) * 8);
            for (iVar6 = 0; iVar6 < (int)(uint)bVar3; iVar6 = iVar6 + 1) {
              iVar9 = *(int *)(iVar15 + (uVar11 + 0x1fffffff) * 8 + 4);
              iVar13 = iVar9 + iVar6 * 0xc;
              if (*(short *)(iVar9 + iVar6 * 0xc) == 0x201) {
                bVar1 = *(byte *)(iVar13 + 8);
                for (iVar9 = 0; iVar9 < (int)(uint)bVar1; iVar9 = iVar9 + 1) {
                  iVar17 = *(int *)(iVar13 + 4);
                  iVar18 = iVar9 * 0x10;
                  iVar16 = iVar17 + iVar18;
                  uVar12 = 0;
                  for (iVar10 = 0; iVar10 < (int)(uint)*(byte *)(iVar16 + 4); iVar10 = iVar10 + 1) {
                    if ((*(byte *)(*(int *)(iVar16 + 8) + iVar10 * 4 + 1) & 0x30) != 0x10) {
                      if (*(char *)(*(int *)(iVar16 + 8) + iVar10 * 4) < '\0') {
                        uVar12 = uVar12 | 1;
                      }
                      else {
                        uVar12 = uVar12 | 2;
                      }
                    }
                  }
                  if ((uVar8 & uVar12) != 0) {
                    if ((int)(uVar12 << 0x1f) < 0) {
                      *(undefined1 *)((int)param_1 + 0x17) = *(undefined1 *)(iVar13 + 3);
                      if (*(char *)(iVar17 + iVar18) == *(char *)(param_1 + 6)) {
                        bVar5 = true;
                        param_1[3] = iVar16;
                      }
                    }
                    if ((int)(uVar12 << 0x1e) < 0) {
                      *(undefined1 *)((int)param_1 + 0x19) = *(undefined1 *)(iVar13 + 3);
                      if (*(char *)(iVar17 + iVar18) == *(char *)((int)param_1 + 0x1a)) {
                        bVar5 = true;
                        param_1[4] = iVar16;
                      }
                    }
                  }
                }
              }
            }
            if (bVar5) {
              if (((uVar8 == 3) && (param_1[3] != 0)) &&
                 ((param_1[4] != 0 && (param_1[3] != param_1[4])))) {
                FUN_60054728(param_1);
                iVar15 = param_1[4];
              }
              else if ((-1 < (int)(uVar8 << 0x1f)) || (iVar15 = param_1[3], iVar15 == 0)) {
                if (-1 < (int)(uVar8 << 0x1e)) {
                  return 1;
                }
                iVar15 = param_1[4];
                if (iVar15 == 0) {
                  return 1;
                }
              }
              uVar7 = FUN_60054728(param_1,iVar15);
              return uVar7;
            }
          }
          return 1;
        }
      }
      else if ((*(byte *)((int)param_1 + 0x19) == uVar2) &&
              (*(char *)((int)param_1 + 0x1a) != cVar4)) {
        FUN_600cfc8e(param_1,param_1 + 4);
        *(char *)((int)param_1 + 0x1a) = cVar4;
        uVar8 = 2;
        goto LAB_600d03b2;
      }
    }
    break;
  case 5:
    if (param_1[1] != 0) {
      if (param_1[2] == 0) {
        uVar7 = 1;
      }
      else {
        uVar7 = 1;
        for (iVar15 = 0; iVar15 < (int)(uint)*(byte *)(param_1[2] + 4); iVar15 = iVar15 + 1) {
          if (*(char *)(*(int *)(param_1[2] + 8) + iVar15 * 4) == (char)*param_3) {
            uVar7 = FUN_600d1134(*param_1);
          }
        }
      }
      if (param_1[3] != 0) {
        for (iVar15 = 0; iVar15 < (int)(uint)*(byte *)(param_1[3] + 4); iVar15 = iVar15 + 1) {
          if (*(char *)(*(int *)(param_1[3] + 8) + iVar15 * 4) == (char)*param_3) {
            uVar7 = FUN_600d1134(*param_1);
          }
        }
      }
      if (param_1[4] != 0) {
        for (iVar15 = 0; iVar15 < (int)(uint)*(byte *)(param_1[4] + 4); iVar15 = iVar15 + 1) {
          if (*(char *)(*(int *)(param_1[4] + 8) + iVar15 * 4) == (char)*param_3) {
            uVar7 = FUN_600d1134(*param_1);
          }
        }
        return uVar7;
      }
      return uVar7;
    }
    break;
  case 6:
    if (param_1[1] != 0) {
      if (param_1[2] == 0) {
        uVar7 = 1;
      }
      else {
        uVar7 = 1;
        for (iVar15 = 0; iVar15 < (int)(uint)*(byte *)(param_1[2] + 4); iVar15 = iVar15 + 1) {
          if (*(char *)(*(int *)(param_1[2] + 8) + iVar15 * 4) == (char)*param_3) {
            uVar7 = FUN_600d1156(*param_1);
          }
        }
      }
      if (param_1[3] != 0) {
        for (iVar15 = 0; iVar15 < (int)(uint)*(byte *)(param_1[3] + 4); iVar15 = iVar15 + 1) {
          if (*(char *)(*(int *)(param_1[3] + 8) + iVar15 * 4) == (char)*param_3) {
            uVar7 = FUN_600d1156(*param_1);
          }
        }
      }
      if (param_1[4] != 0) {
        for (iVar15 = 0; iVar15 < (int)(uint)*(byte *)(param_1[4] + 4); iVar15 = iVar15 + 1) {
          if (*(char *)(*(int *)(param_1[4] + 8) + iVar15 * 4) == (char)*param_3) {
            uVar7 = FUN_600d1156(*param_1);
          }
        }
        return uVar7;
      }
      return uVar7;
    }
  }
  return 1;
}


