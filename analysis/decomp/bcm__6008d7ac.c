// 6008d7ac  bcm__6008d7ac  size=642 bytes
// src: bcm.c
// --- callers ---
//   60091330 ec_asn1__60091330
//   60091238 ec_asn1__60091238
// --- callees ---
//   6008b50c bcm__6008b50c
//   600e6a22 FUN_600e6a22
//   6008d2a8 bcm__6008d2a8
//   600e7490 FUN_600e7490
//   600e0552 FUN_600e0552
//   600e7554 FUN_600e7554
//   600e0ca2 thunk_FUN_600e0c94
//   6008cbfc bcm__6008cbfc
//   600867c8 FUN_600867c8
//   600e7d36 FUN_600e7d36
//   6008d730 bcm__6008d730
//   600e0c82 FUN_600e0c82
//   600e0c90 thunk_FUN_600e0c82
//   600ea7a4 FUN_600ea7a4
//   6008b3d4 bcm__6008b3d4
//   6008b544 FUN_6008b544
//   600e0c94 FUN_600e0c94
//   6008cbe0 FUN_6008cbe0
//   600ea802 FUN_600ea802
//   600e9af4 FUN_600e9af4


/* src: bcm.c */

int * bcm__6008d7ac(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 uVar13;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  iVar12 = 0;
  iVar1 = FUN_6008cbe0();
  while( true ) {
    iVar4 = *(int *)(iVar1 + iVar12 * 0x1c);
    if (iVar4 == param_1) break;
    iVar12 = iVar12 + 1;
    if (iVar12 == 4) {
      FUN_600e0552(0xf,0,0x7b,DAT_6008da38,0x207);
      return (int *)0x0;
    }
  }
  FUN_600e0c82(DAT_6008da30);
  piVar7 = *(int **)(DAT_6008da34 + iVar12 * 4);
  FUN_600e0c94(DAT_6008da30);
  if (piVar7 != (int *)0x0) {
    return piVar7;
  }
  iVar2 = bcm__6008b50c();
  if (iVar2 == 0) {
    FUN_600e0552(0xf,0,0x41,DAT_6008da38,0x1a7);
    piVar7 = (int *)0x0;
    iVar1 = 0;
    iVar10 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    goto LAB_6008d80c;
  }
  iVar1 = iVar12 * 0x1c + iVar1;
  uVar11 = (uint)*(byte *)(iVar1 + 0x10);
  iVar9 = *(int *)(iVar1 + 0x14);
  local_3c = FUN_600e7490(iVar9,uVar11,0);
  if (local_3c == 0) {
LAB_6008d84a:
    local_38 = 0;
LAB_6008d84e:
    piVar7 = (int *)0x0;
    iVar10 = 0;
    FUN_600e0552(0xf,0,3,DAT_6008da38,0x1b1);
    iVar1 = 0;
    local_40 = 0;
    local_34 = 0;
  }
  else {
    iVar9 = iVar9 + uVar11;
    local_38 = FUN_600e7490(iVar9,uVar11,0);
    if (local_38 == 0) goto LAB_6008d84a;
    iVar9 = iVar9 + uVar11;
    local_34 = FUN_600e7490(iVar9,uVar11,0);
    if (local_34 == 0) goto LAB_6008d84e;
    piVar7 = (int *)bcm__6008cbfc(*(undefined4 *)(iVar1 + 0x18));
    if ((piVar7 == (int *)0x0) ||
       (iVar1 = (**(code **)(*piVar7 + 8))(piVar7,local_3c,local_38,local_34,iVar2), iVar1 == 0)) {
      iVar10 = 0;
      iVar1 = 0;
      FUN_600e0552(0xf,0,0xf,DAT_6008da38,0x1b8);
      local_40 = 0;
    }
    else {
      iVar1 = bcm__6008d2a8(piVar7);
      if (iVar1 == 0) {
        FUN_600e0552(0xf,0,0xf,DAT_6008da38,0x1bd);
        iVar10 = 0;
        local_40 = 0;
      }
      else {
        iVar9 = iVar9 + uVar11;
        local_40 = FUN_600e7490(iVar9,uVar11,0);
        if (local_40 != 0) {
          iVar9 = iVar9 + uVar11;
          iVar10 = FUN_600e7490(iVar9,uVar11,0);
          if (iVar10 != 0) {
            iVar3 = bcm__6008d730(piVar7,iVar1,local_40,iVar10,iVar2);
            if (iVar3 == 0) {
              uVar5 = 0xf;
              uVar13 = 0x1c8;
            }
            else {
              piVar6 = piVar7 + 2;
              iVar9 = FUN_600e7490(iVar9 + uVar11,uVar11,piVar6);
              if (iVar9 == 0) {
                uVar13 = 0x1cc;
              }
              else {
                iVar9 = FUN_600e7554(piVar7 + 9,piVar6);
                piVar7[0x31] = (uint)(0 < iVar9);
                if ((0 < iVar9) &&
                   ((iVar9 = FUN_600e7d36(local_3c,piVar7 + 9,piVar6), iVar9 == 0 ||
                    (iVar9 = bcm__6008b3d4(piVar7 + 0x32,piVar7[10],local_3c), iVar9 == 0))))
                goto LAB_6008d80c;
                iVar9 = FUN_600e9af4(piVar6,iVar2);
                piVar7[8] = iVar9;
                if (iVar9 != 0) {
                  piVar7[1] = iVar1;
                  iVar1 = 0;
                  FUN_600867c8(piVar7 + 0x43,iVar9);
                  goto LAB_6008d9d2;
                }
                uVar13 = 0x1da;
              }
              uVar5 = 3;
            }
            FUN_600e0552(0xf,0,uVar5,DAT_6008da38,uVar13);
            goto LAB_6008d80c;
          }
        }
        iVar10 = 0;
        FUN_600e0552(0xf,0,3,DAT_6008da38,0x1c3);
      }
    }
  }
LAB_6008d80c:
  FUN_600ea7a4(piVar7);
  piVar7 = (int *)0x0;
LAB_6008d9d2:
  FUN_600ea802(iVar1);
  FUN_6008b544(iVar2);
  FUN_600e6a22(local_3c);
  FUN_600e6a22(local_38);
  FUN_600e6a22(local_34);
  FUN_600e6a22(local_40);
  FUN_600e6a22(iVar10);
  if (piVar7 == (int *)0x0) {
    return (int *)0x0;
  }
  thunk_FUN_600e0c82(DAT_6008da30);
  piVar6 = *(int **)(DAT_6008da34 + iVar12 * 4);
  piVar8 = piVar7;
  if (piVar6 == (int *)0x0) {
    *(int **)(DAT_6008da34 + iVar12 * 4) = piVar7;
    piVar7[7] = iVar4;
    piVar8 = (int *)0x0;
    piVar6 = piVar7;
  }
  thunk_FUN_600e0c94(DAT_6008da30);
  FUN_600ea7a4(piVar8);
  return piVar6;
}


