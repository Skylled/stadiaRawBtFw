// 6006c340  remote_device_db__6006c340  size=1162 bytes
// src: remote_device_db.cc
// --- callers ---
// --- callees ---
//   600d53ae FUN_600d53ae
//   600dfca0 FUN_600dfca0
//   60082b08 FUN_60082b08
//   600dfc30 FUN_600dfc30
//   600dfc68 FUN_600dfc68
//   600cbb14 FUN_600cbb14
//   6013d168 thunk_EXT_FUN_0000b554
//   600d7d4c thunk_FUN_600d7cdc
//   600cdcc4 FUN_600cdcc4
//   601024a4 FUN_601024a4
//   600dfc7e FUN_600dfc7e
//   601016f0 FUN_601016f0
//   60082aac FUN_60082aac
//   600d37ac FUN_600d37ac
//   6010165c FUN_6010165c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60101b76 FUN_60101b76


/* src: remote_device_db.cc */

void remote_device_db__6006c340(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  byte bVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  bool bVar18;
  int local_e4;
  undefined4 local_e0;
  undefined2 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 uStack_cc;
  uint local_c8;
  undefined4 *local_c0;
  undefined4 local_bc;
  byte *local_b8;
  undefined4 local_b4;
  uint uStack_b0;
  byte local_ac;
  byte local_ab;
  byte local_aa [134];
  
  thunk_EXT_FUN_0000b5ba(DAT_6006c358,0,0x908);
  iVar5 = thunk_EXT_FUN_0000b5ba(DAT_6006d6a8,0,0x908);
  FUN_601024a4(iVar5 + 2,DAT_6006d6ac);
  puVar2 = DAT_60082cd4;
  FUN_6010165c(0x14,DAT_60082cd4,0x178,DAT_60082cd8);
  thunk_EXT_FUN_0000b5ba(DAT_60082cdc,0,0x8c0);
  FUN_60082aac(&local_e4);
  iVar5 = local_e4;
  if (local_e4 == 0) {
    FUN_6010165c(0x1e,puVar2,0x180,DAT_60082ce0);
    bVar18 = false;
    goto LAB_60082b86;
  }
  piVar6 = (int *)FUN_600dfca0();
  bVar4 = (**(code **)(*piVar6 + 4))(piVar6,iVar5,0,0x800);
  uVar15 = (uint)bVar4;
  if (uVar15 == 0) {
    iVar13 = *(int *)(iVar5 + 0x800);
    local_d8 = *DAT_60082ce4;
    local_d4 = DAT_60082ce4[1];
    local_d0 = 1;
    uStack_cc = 0x9d;
    local_c8 = uVar15;
    iVar7 = thunk_EXT_FUN_0000b554(&local_d8,iVar13,8);
    if (iVar7 == 0) {
      if (*(int *)(iVar13 + 8) == 1) {
        if (*(int *)(iVar13 + 0xc) == 0x9d) {
          if (*(uint *)(iVar13 + 0x10) < 9) {
            iVar11 = *(int *)(iVar13 + 0x14);
            iVar7 = FUN_600dfc30(iVar13,*(undefined4 *)(iVar5 + 0x804));
            uVar8 = DAT_60082ff0;
            if (iVar11 == iVar7) {
              local_dc = 0;
              iVar5 = 0;
              local_e0 = 0;
              for (uVar15 = 0; uVar15 < *(uint *)(*(int *)(local_e4 + 0x800) + 0x10);
                  uVar15 = uVar15 + 1) {
                puVar14 = (undefined4 *)(uVar15 * 0x9d + *(int *)(local_e4 + 0x804));
                iVar7 = thunk_EXT_FUN_0000b554(&local_e0,puVar14,6);
                puVar3 = DAT_60082fe0;
                if (iVar7 == 0) {
                  *DAT_60082fe0 = *(undefined1 *)((int)puVar14 + 6);
                  puVar10 = (undefined4 *)(puVar3 + 1);
                  puVar16 = (undefined4 *)((int)puVar14 + 7);
                  do {
                    puVar12 = puVar16 + 1;
                    *puVar10 = *puVar16;
                    puVar10 = puVar10 + 1;
                    puVar16 = puVar12;
                  } while (puVar12 != (undefined4 *)((int)puVar14 + 0x17));
                  puVar10 = DAT_60082fe4;
                  do {
                    puVar16 = puVar12 + 1;
                    *puVar10 = *puVar12;
                    puVar10 = puVar10 + 1;
                    puVar12 = puVar16;
                  } while (puVar16 != (undefined4 *)((int)puVar14 + 0x27));
                  puVar10 = DAT_60082fe8;
                  do {
                    puVar12 = puVar16 + 1;
                    *puVar10 = *puVar16;
                    puVar10 = puVar10 + 1;
                    puVar16 = puVar12;
                  } while (puVar12 != (undefined4 *)((int)puVar14 + 0x37));
                  puVar10 = DAT_60082fec;
                  do {
                    puVar16 = puVar12 + 1;
                    *puVar10 = *puVar12;
                    puVar10 = puVar10 + 1;
                    puVar12 = puVar16;
                  } while (puVar16 != (undefined4 *)((int)puVar14 + 0x47));
                  FUN_6010165c(0x14,puVar2,0x1a0,uVar8);
                }
                else {
                  iVar7 = DAT_60082fc4 + iVar5 * 0x118;
                  *(undefined4 *)(iVar7 + 1) = *puVar14;
                  puVar16 = (undefined4 *)(iVar7 + 0x88);
                  *(undefined2 *)(iVar7 + 5) = *(undefined2 *)(puVar14 + 1);
                  *(undefined4 *)(iVar7 + 0x80) = *(undefined4 *)((int)puVar14 + 6);
                  *(undefined1 *)(iVar7 + 0x84) = *(undefined1 *)((int)puVar14 + 10);
                  *(undefined1 *)(iVar7 + 0x85) = *(undefined1 *)((int)puVar14 + 0xb);
                  *(undefined1 *)(iVar7 + 0x86) = *(undefined1 *)(puVar14 + 3);
                  *(undefined1 *)(iVar7 + 0x87) = *(undefined1 *)((int)puVar14 + 0xd);
                  puVar10 = (undefined4 *)((int)puVar14 + 0xe);
                  do {
                    puVar12 = puVar10 + 2;
                    uVar9 = puVar10[1];
                    *puVar16 = *puVar10;
                    puVar16[1] = uVar9;
                    puVar16 = puVar16 + 2;
                    puVar10 = puVar12;
                  } while (puVar12 != (undefined4 *)((int)puVar14 + 0x26));
                  *puVar16 = *puVar12;
                  puVar16 = (undefined4 *)(iVar7 + 0xa4);
                  puVar10 = (undefined4 *)((int)puVar14 + 0x2a);
                  do {
                    puVar12 = puVar10 + 2;
                    uVar9 = puVar10[1];
                    *puVar16 = *puVar10;
                    puVar16[1] = uVar9;
                    puVar16 = puVar16 + 2;
                    puVar10 = puVar12;
                  } while (puVar12 != (undefined4 *)((int)puVar14 + 0x42));
                  puVar10 = (undefined4 *)((int)puVar14 + 0x42);
                  puVar16 = (undefined4 *)(iVar7 + 0xbc);
                  do {
                    puVar17 = puVar16;
                    puVar12 = puVar10;
                    puVar10 = puVar12 + 2;
                    uVar9 = puVar12[1];
                    *puVar17 = *puVar12;
                    puVar17[1] = uVar9;
                    puVar16 = puVar17 + 2;
                  } while (puVar10 != (undefined4 *)((int)puVar14 + 0x52));
                  puVar16 = (undefined4 *)(iVar7 + 0xd4);
                  puVar17[2] = *puVar10;
                  uVar1 = *(undefined1 *)((int)puVar12 + 0xe);
                  *(undefined2 *)(puVar17 + 3) = *(undefined2 *)(puVar12 + 3);
                  *(undefined1 *)((int)puVar17 + 0xe) = uVar1;
                  puVar10 = (undefined4 *)((int)puVar14 + 0x59);
                  do {
                    puVar12 = puVar10 + 2;
                    uVar9 = puVar10[1];
                    *puVar16 = *puVar10;
                    puVar16[1] = uVar9;
                    puVar16 = puVar16 + 2;
                    puVar10 = puVar12;
                  } while (puVar12 != (undefined4 *)((int)puVar14 + 0x69));
                  *puVar16 = *puVar12;
                  puVar16 = (undefined4 *)(iVar7 + 0xe8);
                  puVar10 = (undefined4 *)((int)puVar14 + 0x6d);
                  do {
                    puVar12 = puVar10 + 2;
                    uVar9 = puVar10[1];
                    *puVar16 = *puVar10;
                    puVar16[1] = uVar9;
                    puVar16 = puVar16 + 2;
                    puVar10 = puVar12;
                  } while (puVar12 != (undefined4 *)((int)puVar14 + 0x85));
                  puVar10 = (undefined4 *)((int)puVar14 + 0x85);
                  puVar16 = (undefined4 *)(iVar7 + 0x100);
                  do {
                    puVar17 = puVar16;
                    puVar12 = puVar10;
                    puVar10 = puVar12 + 2;
                    uVar9 = puVar12[1];
                    *puVar17 = *puVar12;
                    puVar17[1] = uVar9;
                    puVar16 = puVar17 + 2;
                  } while (puVar10 != (undefined4 *)((int)puVar14 + 0x95));
                  iVar11 = iVar5 * 0x118 + 0x29;
                  puVar17[2] = *puVar10;
                  uVar1 = *(undefined1 *)((int)puVar12 + 0xe);
                  *(undefined2 *)(puVar17 + 3) = *(undefined2 *)(puVar12 + 3);
                  *(undefined1 *)((int)puVar17 + 0xe) = uVar1;
                  *(undefined1 *)(iVar7 + 0x117) = *(undefined1 *)(puVar14 + 0x27);
                  iVar7 = DAT_60082fc8;
                  *(undefined1 *)(iVar5 * 0x118 + DAT_60082fc8 + 0x28) = 1;
                  iVar13 = iVar11 + iVar7;
                  local_d8 = CONCAT13(*(undefined1 *)(iVar13 + 3),
                                      CONCAT12(*(undefined1 *)(iVar13 + 2),
                                               CONCAT11(*(undefined1 *)(iVar13 + 1),
                                                        *(undefined1 *)(iVar11 + iVar7))));
                  local_d4 = CONCAT22(local_d4._2_2_,*(undefined2 *)(iVar13 + 4));
                  local_c0 = &local_d8;
                  iVar7 = thunk_FUN_600d7cdc();
                  puVar14 = DAT_60082fdc;
                  if (iVar7 != 0) {
                    FUN_600cdcc4(&local_bc,0x28,DAT_60082fcc,*(undefined1 *)((int)local_c0 + 5),
                                 *(undefined1 *)(local_c0 + 1),*(undefined1 *)((int)local_c0 + 3),
                                 *(undefined1 *)((int)local_c0 + 2),
                                 *(undefined1 *)((int)local_c0 + 1),*(undefined1 *)local_c0);
                    puVar14 = &local_bc;
                  }
                  iVar5 = iVar5 + 1;
                  FUN_6010165c(0x14,puVar2,0x19b,DAT_60082fd0,puVar14);
                }
              }
              bVar18 = iVar5 != 0;
              goto LAB_60082b86;
            }
            local_c0 = puVar2;
            local_bc = 0x105;
            local_b8 = local_aa;
            local_b4 = 0x80;
            uStack_b0 = uVar15;
            local_ac = bVar4;
            local_ab = bVar4;
            local_aa[0] = bVar4;
            FUN_600d37ac(&local_b8,DAT_60082fd4);
            FUN_600dfc7e(&local_b8,*(undefined4 *)(*(int *)(iVar5 + 0x800) + 0x14));
            FUN_600d37ac(&local_b8,DAT_60082fd8);
            uVar8 = FUN_600dfc30(*(undefined4 *)(iVar5 + 0x800),*(undefined4 *)(iVar5 + 0x804));
            FUN_600dfc7e(&local_b8,uVar8);
            FUN_601016f0(0x28,local_c0,local_bc,&local_b8);
            goto LAB_60082bec;
          }
          local_ac = 0;
          local_ab = 0;
          local_bc = 0xbd;
          local_b8 = local_aa;
          local_aa[0] = 0;
          local_c0 = puVar2;
          local_b4 = 0x80;
          uStack_b0 = iVar7;
          FUN_600d37ac(&local_b8,DAT_60082cf8);
          uVar8 = *(undefined4 *)(iVar13 + 0x10);
        }
        else {
          local_ac = 0;
          local_ab = 0;
          local_bc = 0xb8;
          local_b8 = local_aa;
          local_aa[0] = 0;
          local_c0 = puVar2;
          local_b4 = 0x80;
          uStack_b0 = iVar7;
          FUN_600d37ac(&local_b8,DAT_60082cf4);
          uVar8 = *(undefined4 *)(iVar13 + 0xc);
        }
      }
      else {
        local_ac = 0;
        local_ab = 0;
        local_bc = 0xb4;
        local_b8 = local_aa;
        local_aa[0] = 0;
        local_c0 = puVar2;
        local_b4 = 0x80;
        uStack_b0 = iVar7;
        FUN_600d37ac(&local_b8,DAT_60082cf0);
        uVar8 = *(undefined4 *)(iVar13 + 8);
      }
      FUN_600dfc7e(&local_b8,uVar8);
      FUN_600d53ae(&local_c0);
    }
    else {
      FUN_6010165c(0x1e,puVar2,0xb0,DAT_60082ce8);
    }
LAB_60082bec:
    bVar4 = 9;
  }
  local_bc = 0x188;
  local_b8 = local_aa;
  local_c0 = puVar2;
  local_ac = 0;
  local_ab = 0;
  local_aa[0] = 0;
  local_b4 = 0x80;
  uStack_b0 = 0;
  FUN_600d37ac(&local_b8,DAT_60082cec);
  local_d8 = CONCAT31(local_d8._1_3_,bVar4);
  uVar8 = FUN_600cbb14(&local_d8);
  FUN_60101b76(&local_b8,uVar8);
  FUN_600d53ae(&local_c0);
  bVar18 = false;
LAB_60082b86:
  FUN_60082b08(bVar18);
  FUN_600dfc68(&local_e4);
  return;
}


