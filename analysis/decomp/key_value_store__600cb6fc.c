// 600cb6fc  key_value_store__600cb6fc  size=1006 bytes
// src: key_value_store.cc
// --- callers ---
//   600717d4 FUN_600717d4
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d37b8 FUN_600d37b8
//   600cbb14 FUN_600cbb14
//   60101ba2 FUN_60101ba2
//   6013cef0 thunk_EXT_FUN_0000887a
//   600cb39c key_value_store__600cb39c
//   600cb270 FUN_600cb270
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60100e78 FUN_60100e78
//   60100b24 FUN_60100b24
//   60050c18 FUN_60050c18
//   6010165c FUN_6010165c
//   600d37ac FUN_600d37ac
//   60100b38 FUN_60100b38
//   60100b48 FUN_60100b48
//   601018de FUN_601018de
//   600cb2fc key_value_store__600cb2fc
//   60100b6a FUN_60100b6a


/* src: key_value_store.cc */

uint key_value_store__600cb6fc(int *param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  bool bVar14;
  byte local_d3;
  char local_d2;
  char local_d1;
  int *local_d0;
  short local_cc;
  ushort local_ca;
  ushort local_c8;
  uint local_c4;
  undefined4 local_c0;
  byte *local_bc;
  int local_b8;
  uint uStack_b4;
  byte local_b0;
  byte local_af;
  byte local_ae [130];
  char local_2c;
  
  local_d0 = param_1 + 1;
  thunk_EXT_FUN_0000b4c2();
  if ((char)param_1[0x16] == '\0') {
    thunk_EXT_FUN_0000b5ba(param_1 + 0x1a,0,0x50);
    *(undefined1 *)(param_1 + 0x2ae) = 0;
    uVar2 = (**(code **)(*(int *)*param_1 + 0x10))();
    *(undefined1 *)((int)param_1 + 0x59) = uVar2;
    uVar4 = (**(code **)(*(int *)*param_1 + 0x14))();
    if (0x14 < uVar4) {
      FUN_6010165c(0x1e,DAT_600cba6c,0x40,DAT_600cba68);
    }
    puVar12 = (uint *)(param_1 + 0x2e);
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    for (uVar4 = 0; uVar7 = FUN_60100b38(*param_1), uVar4 < uVar7; uVar4 = uVar4 + 1) {
      piVar8 = (int *)*param_1;
      iVar10 = *(int *)(piVar8[1] + 4);
      uVar5 = FUN_60100b24(*(undefined1 *)((int)param_1 + 0x59),8);
      uVar7 = (**(code **)(*piVar8 + 0xc))(piVar8,uVar4 * iVar10,uVar5,&local_d3);
      if (((uVar7 & 0xff) != 0) ||
         (uVar7 = FUN_601018de(*param_1,&local_cc,uVar4 * *(int *)(*(int *)(*param_1 + 4) + 4),8),
         (uVar7 & 0xff) != 0)) goto LAB_600cb816;
      if ((local_d3 == 0) && (local_cc == -0x5433)) {
        if (local_ca - 2 < 3) {
          iVar10 = FUN_60100b24(*(undefined1 *)((int)param_1 + 0x59),8);
          piVar8 = (int *)*param_1;
          uVar7 = (**(code **)(*piVar8 + 0xc))
                            (piVar8,*(int *)(piVar8[1] + 4) * uVar4 + iVar10,iVar10,&local_d2);
          if ((uVar7 & 0xff) != 0) goto LAB_600cb816;
          if (local_d2 == '\0') {
            uVar7 = FUN_601018de(*param_1,puVar12,
                                 *(int *)(*(int *)(*param_1 + 4) + 4) * uVar4 + iVar10,8);
            if ((uVar7 & 0xff) != 0) goto LAB_600cb816;
            uVar6 = param_1[0x19];
            uVar7 = *puVar12 + 1;
            uVar11 = puVar12[1] + (uint)(0xfffffffe < *puVar12);
            bVar14 = uVar6 <= uVar11;
            if (uVar11 == uVar6) {
              bVar14 = (uint)param_1[0x18] <= uVar7;
            }
            if (!bVar14) {
              uVar11 = uVar6;
              uVar7 = param_1[0x18];
            }
            param_1[0x18] = uVar7;
            param_1[0x19] = uVar11;
          }
          else {
            *puVar12 = 0xffffffff;
            puVar12[1] = 0xffffffff;
          }
          if (local_ca == 2) {
            local_c8 = 1;
          }
          if (local_c8 == *(byte *)((int)param_1 + 0x59)) {
            iVar10 = FUN_60100b24((ushort)*(byte *)((int)param_1 + 0x59),8);
            uVar11 = iVar10 * 2;
            param_1[uVar4 + 0x1a] = *(int *)(*(int *)(*param_1 + 4) + 4) + iVar10 * -2;
            while( true ) {
              piVar8 = (int *)*param_1;
              iVar9 = *(int *)(piVar8[1] + 4);
              iVar10 = FUN_60100b24(*(undefined1 *)((int)param_1 + 0x59),8);
              if ((uint)(iVar9 - iVar10) <= uVar11) break;
              iVar9 = uVar4 * iVar9 + uVar11;
              uVar7 = (**(code **)(*piVar8 + 0xc))(piVar8,iVar9,iVar10,&local_d1);
              if (((uVar7 & 0xff) != 0) ||
                 (uVar7 = FUN_601018de(*param_1,&local_c4,iVar9,8), (uVar7 & 0xff) != 0))
              goto LAB_600cb816;
              if (local_d1 != '\0') break;
              if ((local_c4 & 0xffff) != 0x55aa) {
                FUN_6010165c(0x28,DAT_600cbb04,0x99,DAT_600cbb10);
                break;
              }
              iVar10 = FUN_60100b24(*(undefined1 *)((int)param_1 + 0x59),8);
              iVar13 = (int)param_1 + 0xab9;
              uVar7 = FUN_601018de(*param_1,iVar13,iVar10 + iVar9,local_c0._2_1_ & 0xf);
              if ((uVar7 & 0xff) != 0) goto LAB_600cb816;
              *(char *)((int)param_1 + (local_c0 >> 0x10 & 0xf) + 0xab9) = (char)uVar7;
              iVar10 = FUN_60100e78(param_1,iVar13);
              if (iVar10 == 100) {
                uVar7 = key_value_store__600cb2fc
                                  (param_1,iVar13,iVar9,local_c0._2_2_ >> 4,local_c0 & 1);
                if ((uVar7 & 0xff) != 0) goto LAB_600cb816;
              }
              else {
                uVar7 = (uint)param_1[iVar10 * 6 + 0x5a] / *(uint *)(*(int *)(*param_1 + 4) + 4);
                bVar14 = (uint)param_1[uVar7 * 2 + 0x2f] <= puVar12[1];
                if (puVar12[1] == param_1[uVar7 * 2 + 0x2f]) {
                  bVar14 = (uint)param_1[uVar7 * 2 + 0x2e] <= *puVar12;
                }
                if (bVar14) {
                  param_1[iVar10 * 6 + 0x5a] = iVar9;
                  *(ushort *)(param_1 + iVar10 * 6 + 0x5b) = local_c0._2_2_ >> 4;
                  *(char *)((int)param_1 + iVar10 * 0x18 + 0x16e) = (char)(local_c0 & 1);
                }
              }
              uVar1 = local_c0._2_2_;
              iVar10 = FUN_60100b6a(param_1,local_c0._2_1_ & 0xf,uVar1 >> 4);
              uVar11 = uVar11 + iVar10;
            }
            iVar10 = 0;
            if (local_d2 != '\0') {
              iVar10 = *(int *)(*(int *)(*param_1 + 4) + 4) - uVar11;
            }
            param_1[uVar4 + 0x1a] = iVar10;
            goto LAB_600cb7ca;
          }
          local_c4 = DAT_600cba6c;
          local_c0 = 0x7c;
          local_bc = local_ae;
          local_b8 = 0x80;
          uStack_b4 = 0;
          local_b0 = 0;
          local_af = 0;
          local_ae[0] = 0;
          FUN_600d37ac(&local_bc,DAT_600cba74);
          FUN_60100b48(&local_bc,uVar4);
          FUN_600d37ac(&local_bc,DAT_600cba78);
          uVar5 = FUN_60050c18(*(undefined1 *)((int)param_1 + 0x59),0,local_bc + uStack_b4,
                               local_b8 - uStack_b4);
          FUN_60101ba2(&local_bc,uVar5);
          FUN_600d37ac(&local_bc,DAT_600cba7c);
          uVar5 = FUN_60050c18(local_c8,0,local_bc + uStack_b4,local_b8 - uStack_b4);
          FUN_60101ba2(&local_bc,uVar5);
        }
        else {
          local_c4 = DAT_600cba6c;
          local_b0 = local_d3;
          local_c0 = 0x5d;
          local_bc = local_ae;
          local_af = local_d3;
          local_ae[0] = local_d3;
          local_b8 = 0x80;
          uStack_b4 = (uint)local_d3;
          FUN_600d37ac(&local_bc,DAT_600cba70);
          FUN_60100b48(&local_bc,uVar4);
        }
        uVar7 = 9;
        FUN_600d37b8(&local_c4);
        goto LAB_600cb816;
      }
      uVar7 = FUN_600cb270(param_1,uVar4);
      if ((uVar7 & 0xff) != 0) goto LAB_600cb816;
LAB_600cb7ca:
      puVar12 = puVar12 + 2;
    }
    cVar3 = key_value_store__600cb39c(param_1);
    if (cVar3 != '\0') {
      local_cc = CONCAT11(local_cc._1_1_,cVar3);
      local_c4 = DAT_600cbb04;
      local_c0 = 0xc1;
      local_bc = local_ae;
      local_b8 = 0x80;
      uStack_b4 = 0;
      local_b0 = 0;
      local_af = 0;
      local_ae[0] = 0;
      local_2c = cVar3;
      uVar5 = FUN_600cbb14(&local_cc);
      FUN_600d37ac(&local_bc,uVar5);
      FUN_600d37ac(&local_bc,DAT_600cbb08);
      FUN_600d37ac(&local_bc,DAT_600cbb0c);
      FUN_600d37b8(&local_c4);
    }
    *(undefined1 *)(param_1 + 0x16) = 1;
  }
  uVar7 = 0;
LAB_600cb816:
  thunk_EXT_FUN_0000887a(&local_d0);
  return uVar7;
}


