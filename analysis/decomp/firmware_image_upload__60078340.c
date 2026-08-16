// 60078340  firmware_image_upload__60078340  size=1714 bytes
// src: firmware_image_upload.cc
// src: http_flash_writer.h
// --- callers ---
// --- callees ---
//   6005f120 FUN_6005f120
//   600d37b8 FUN_600d37b8
//   60101b0c FUN_60101b0c
//   600db3a2 FUN_600db3a2
//   60101740 FUN_60101740
//   600db3ea FUN_600db3ea
//   601016f0 FUN_601016f0
//   6013d3c8 thunk_EXT_FUN_00001680
//   600d37ac FUN_600d37ac
//   600cc8f8 FUN_600cc8f8
//   6013cf80 thunk_EXT_FUN_0000714c
//   60079778 http_flash_writer__60079778
//   6013d378 thunk_EXT_FUN_0000b532
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60061684 partition_table__60061684
//   600781d4 FUN_600781d4
//   60101ba2 FUN_60101ba2
//   6007991c http_flash_writer__6007991c
//   6005a010 FUN_6005a010
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6007818c partition_table__6007818c
//   600db32c FUN_600db32c
//   600db36c FUN_600db36c
//   600e028e FUN_600e028e
//   600e0304 FUN_600e0304
//   60050c18 FUN_60050c18
//   600db394 FUN_600db394
//   600cc984 FUN_600cc984
//   601016a2 FUN_601016a2
//   600d3a16 thunk_FUN_60059eb8
//   60074ec8 FUN_60074ec8
//   600d4752 FUN_600d4752
//   600653f0 FUN_600653f0
//   600678ec binary_build_metadata__600678ec
//   601017e8 FUN_601017e8
//   6013d310 thunk_EXT_FUN_0000b52a
//   600db730 FUN_600db730
//   6010165c FUN_6010165c
//   60061794 FUN_60061794
//   600e0242 FUN_600e0242
//   600edfda thunk_FUN_600921b8
//   600db30a FUN_600db30a
//   60078170 FUN_60078170
//   60101fd2 FUN_60101fd2
//   600ce2a0 FUN_600ce2a0
//   600db3b6 FUN_600db3b6
//   60078218 FUN_60078218


/* src: firmware_image_upload.cc
   src: http_flash_writer.h */

undefined4 firmware_image_upload__60078340(int param_1,int param_2)

{
  byte bVar1;
  uint *puVar2;
  byte *pbVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined *puVar13;
  byte *pbVar14;
  undefined1 uVar15;
  int iVar16;
  int iVar17;
  undefined1 *puVar18;
  char cVar19;
  int local_d4;
  undefined4 **local_d0;
  undefined4 *local_cc;
  undefined4 *local_c8 [4];
  undefined4 *local_b8;
  int local_b4;
  byte *local_b0;
  int local_ac;
  uint uStack_a8;
  byte local_a4;
  byte local_a3;
  byte local_a2 [130];
  
  puVar9 = DAT_600785c8;
  if (*(int *)(param_1 + 8) != 6) {
    return 0;
  }
  cVar19 = *(char *)(param_1 + 0x10);
  if (cVar19 == '\0') {
    FUN_600db36c(&local_b8,param_2,1);
    FUN_600db3a2(&local_b8,DAT_600785c4);
    FUN_600db394(&local_b8);
    return 2;
  }
  pbVar14 = (byte *)*DAT_600785c8;
  local_d4 = DAT_600785c8[1];
  if (local_d4 != 0) {
    FUN_60074ec8();
  }
  switch(*(undefined1 *)(param_1 + 0x11)) {
  case 1:
    *(undefined4 *)(param_2 + 8) = 7;
    iVar10 = FUN_60061794();
    if ((iVar10 - 1U & 0xff) < 2) {
      if (iVar10 == 1) {
        uVar15 = 2;
      }
      else {
        uVar15 = 1;
      }
      uVar12 = FUN_600653f0();
      piVar11 = (int *)partition_table__6007818c(uVar12,uVar15);
      if (piVar11 == (int *)0x0) {
        FUN_6010165c(0x28,PTR_s_firmware_image_upload_cc_600785d8,0xab,
                     PTR_s_Failed_to_get_target_partition__600785d4);
        local_b8 = (undefined4 *)0x0;
        local_b4 = 0;
      }
      else {
        local_d0 = (undefined4 **)0x0;
        local_cc = (undefined4 *)0x0;
        ppuVar4 = (undefined4 **)thunk_EXT_FUN_0000b532(0x240);
        *(undefined1 *)(ppuVar4 + 2) = uVar15;
        *(undefined1 *)ppuVar4 = 0;
        *(undefined1 *)((int)ppuVar4 + 1) = 0;
        ppuVar4[1] = (undefined4 *)0x0;
        puVar5 = (undefined4 *)(**(code **)(*piVar11 + 0x14))(piVar11);
        ppuVar4[7] = (undefined4 *)0x0;
        ppuVar4[5] = puVar5;
        ppuVar4[6] = (undefined4 *)0x0;
        ppuVar4[3] = piVar11;
        ppuVar4[4] = (undefined4 *)0x0;
        thunk_EXT_FUN_0000b5ba(ppuVar4 + 8,0,0x10);
        ppuVar4[0xc] = (undefined4 *)0x0;
        ppuVar4[0xd] = (undefined4 *)0x0;
        thunk_EXT_FUN_0000b5ba(ppuVar4 + 0xe,0,0x70);
        puVar13 = PTR_s__6011b41a_0xc_600785dc;
        ppuVar4[0x2a] = ppuVar4 + 0x2c;
        FUN_600db3ea(ppuVar4 + 0x2c,puVar13);
        ppuVar4[0x2b] = (undefined4 *)0x0;
        *(undefined1 *)ppuVar4[0x2a] = 0;
        ppuVar4[0x44] = (undefined4 *)0x0;
        FUN_601017e8(ppuVar4 + 0x30);
        puVar13 = PTR_FUN_600ce232_1_600785e0;
        *(undefined1 *)(ppuVar4 + 0x45) = 0;
        ppuVar4[0x46] = (undefined4 *)puVar13;
        iVar10 = *piVar11;
        ppuVar4[0x47] = (undefined4 *)0x0;
        uVar7 = (**(code **)(iVar10 + 0x10))(piVar11);
        if (0x10 < uVar7) {
          uVar12 = (**(code **)(*piVar11 + 0x10))(piVar11);
          FUN_601016a2(PTR_s_http_flash_writer_h_600785e8,0x28,
                       PTR_s_Flash_alignment_of__lu_bytes_is_t_600785e4,uVar12);
        }
        puVar6 = (undefined4 *)(**(code **)(*piVar11 + 0x14))(piVar11);
        if (puVar6 < puVar5) {
          uVar12 = (**(code **)(*piVar11 + 0x14))(piVar11);
          FUN_601016a2(PTR_s_http_flash_writer_h_600785e8,0x2d,
                       PTR_s_Space_to_write___lu__lu__extends_600785ec,0,puVar5,uVar12);
        }
        local_b8 = (undefined4 *)0x0;
        puVar5 = (undefined4 *)thunk_EXT_FUN_0000b532(0x14);
        puVar5[4] = ppuVar4;
        puVar5[1] = 1;
        puVar5[2] = 1;
        *puVar5 = PTR_PTR_600785f0;
        local_b8 = local_cc;
        local_d0 = ppuVar4;
        local_cc = puVar5;
        thunk_EXT_FUN_00001680(&local_b8);
        puVar5 = local_cc;
        ppuVar4 = local_d0;
        local_b8 = (undefined4 *)*puVar9;
        local_d0 = (undefined4 **)0x0;
        local_cc = (undefined4 *)0x0;
        *puVar9 = ppuVar4;
        local_b4 = puVar9[1];
        puVar9[1] = puVar5;
        thunk_EXT_FUN_00001680(&local_b4);
        thunk_EXT_FUN_00001680(&local_cc);
        local_b8 = (undefined4 *)*puVar9;
        local_b4 = puVar9[1];
        if (local_b4 != 0) {
          FUN_60074ec8();
        }
      }
    }
    else {
      local_b8 = (undefined4 *)0x0;
      local_b4 = 0;
    }
    if (local_b8 == (undefined4 *)0x0) {
      cVar19 = '\0';
    }
    else {
      local_b8[0x46] = PTR_LAB_600d407e_1_600785cc;
      local_b8[0x47] = PTR_LAB_60078258_1_600785d0;
      http_flash_writer__60079778();
      *(undefined1 *)(param_2 + 0x10) = 1;
      uVar15 = 1;
      if (*(char *)(local_b8 + 2) != '\x01') {
        if (*(char *)(local_b8 + 2) == '\x02') {
          uVar15 = 2;
        }
        else {
          uVar15 = 0;
        }
      }
      *(undefined1 *)(param_2 + 0x11) = uVar15;
    }
    thunk_EXT_FUN_00001680(&local_b4);
    if (cVar19 == '\0') {
      FUN_600db36c(&local_b8,param_2,1);
      puVar13 = PTR_s_Failed_to_start_firmware_upload_600785f4;
      goto LAB_60078566;
    }
    break;
  case 2:
    if (pbVar14 != (byte *)0x0) {
      if (*(char *)(param_1 + 0x12) == '\0') {
        FUN_60078218();
        FUN_600db36c(&local_b8,param_2,1);
        puVar13 = PTR_s_Missing_data_600785f8;
      }
      else if (*(char *)(param_1 + 0x218) == '\0') {
        FUN_60078218();
        FUN_600db36c(&local_b8,param_2,1);
        puVar13 = PTR_s_Missing_offset_600785fc;
      }
      else {
        if (*(char *)(param_1 + 0x220) != '\0') {
          iVar16 = param_1 + 0x18;
          uVar12 = thunk_FUN_600921b8(0,0);
          iVar10 = thunk_FUN_600921b8(uVar12,iVar16,*(undefined4 *)(param_1 + 0x14));
          pbVar3 = DAT_60078954;
          puVar2 = DAT_6007892c;
          if (iVar10 != *(int *)(param_1 + 0x224)) {
            local_b8 = (undefined4 *)PTR_s_firmware_image_upload_cc_60078908;
            local_a4 = 0;
            local_b4 = 0x187;
            local_b0 = local_a2;
            local_a3 = 0;
            local_a2[0] = 0;
            local_ac = 0x80;
            uStack_a8 = 0;
            FUN_600d37ac(&local_b0,PTR_s_Invalid_data_crc__Expected_crc_6007890c);
            FUN_600db30a(&local_b0,*(undefined4 *)(param_1 + 0x224));
            FUN_600d37ac(&local_b0,PTR_s_but_buffer_crc_was_60078910);
            FUN_600db30a(&local_b0,iVar10);
            FUN_600d37ac(&local_b0,PTR_s_while_writing_60078914);
            FUN_600db30a(&local_b0,*(undefined4 *)(param_1 + 0x14));
            FUN_600d37ac(&local_b0,PTR_s_bytes_at_60078918);
            FUN_600db30a(&local_b0,*(undefined4 *)(param_1 + 0x21c));
            FUN_600d37b8(&local_b8);
            FUN_600781d4(&local_d0,PTR_s_BUFFER__6007891c);
            FUN_600e0304(local_d0,iVar16,*(undefined4 *)(param_1 + 0x14),0);
            FUN_600e028e(local_d0);
            FUN_60078218();
            FUN_600db36c(&local_b8,param_2,1);
            FUN_600db3a2(&local_b8,PTR_s_Bad_CRC_60078920);
            FUN_600db394(&local_b8);
            if (local_d0 != (undefined4 **)0x0) {
              FUN_600e0242();
            }
            break;
          }
          iVar17 = *(int *)(param_1 + 0x21c);
          bVar1 = *pbVar14;
          iVar10 = *(int *)(param_1 + 0x14);
          if (bVar1 == 0) {
            if (iVar17 == *(int *)(pbVar14 + 4)) {
              bVar1 = *DAT_60078954;
              DataMemoryBarrier(0x1b);
              if (((bVar1 & 1) == 0) && (iVar17 = FUN_600cc8f8(DAT_60078954), iVar17 != 0)) {
                *puVar2 = bVar1 & 1;
                FUN_600cc984(pbVar3);
              }
              uVar7 = thunk_EXT_FUN_0000714c();
              uVar7 = ((uVar7 % 1000) * 1000 + 500) / 1000 + (uVar7 / 1000) * 1000;
              if (*puVar2 + 1000 <= uVar7) {
                *puVar2 = uVar7;
                local_b8 = (undefined4 *)PTR_s_firmware_image_upload_cc_60078908;
                local_b4 = 0xc3;
                local_b0 = local_a2;
                local_ac = 0x80;
                uStack_a8 = 0;
                local_a4 = 0;
                local_a3 = 0;
                local_a2[0] = 0;
                FUN_600d37ac(&local_b0,PTR_s_WRITING_60078930);
                FUN_600db32c(&local_b0,iVar10);
                FUN_600d37ac(&local_b0,PTR_s_bytes__60078934);
                FUN_600db32c(&local_b0,*(undefined4 *)(pbVar14 + 0x1c));
                FUN_600d37ac(&local_b0,PTR_s_bytes_written_so_far_60078938);
                FUN_601016f0(0x14,local_b8,local_b4,&local_b0);
              }
              iVar16 = FUN_600db730(pbVar14 + 0xc,iVar16,iVar10);
              if ((-1 < iVar16) && (iVar10 == iVar16)) {
                *(int *)(pbVar14 + 4) = iVar10 + *(int *)(pbVar14 + 4);
                goto LAB_6007884a;
              }
              local_b8 = (undefined4 *)PTR_s_firmware_image_upload_cc_60078908;
              local_b4 = 0xcb;
              local_b0 = local_a2;
              local_ac = 0x80;
              uStack_a8 = 0;
              local_a4 = 0;
              local_a3 = 0;
              local_a2[0] = 0;
              FUN_600d37ac(&local_b0,PTR_s_Flash_write_of_6007893c);
              FUN_600db32c(&local_b0,iVar10);
              FUN_600d37ac(&local_b0,PTR_s_bytes_failed__Write_returned_60078940);
              uVar12 = FUN_60101b0c(iVar16,iVar16 >> 0x1f,local_b0 + uStack_a8,local_ac - uStack_a8)
              ;
              FUN_60101ba2(&local_b0,uVar12);
            }
            else {
              local_b8 = (undefined4 *)PTR_s_firmware_image_upload_cc_60078908;
              local_b4 = 0xbb;
              local_b0 = local_a2;
              local_ac = 0x80;
              uStack_a8 = (uint)bVar1;
              local_a4 = bVar1;
              local_a3 = bVar1;
              local_a2[0] = bVar1;
              FUN_600d37ac(&local_b0,PTR_s_Write_at_offset_60078924);
              FUN_600db32c(&local_b0,iVar17);
              FUN_600d37ac(&local_b0,PTR_s_but_expected_60078928);
              FUN_600db32c(&local_b0,*(undefined4 *)(pbVar14 + 4));
            }
            uVar12 = 1;
            FUN_600d37b8(&local_b8);
            *pbVar14 = 1;
          }
          else {
LAB_6007884a:
            uVar12 = 1;
          }
          goto LAB_600783fc;
        }
        FUN_60078218();
        FUN_600db36c(&local_b8,param_2,1);
        puVar13 = PTR_s_Missing_crc_of_data_60078600;
      }
LAB_60078566:
      FUN_600db3a2(&local_b8,puVar13);
      goto LAB_6007856c;
    }
    break;
  case 3:
    FUN_60078218();
    break;
  case 4:
    if (pbVar14 == (byte *)0x0) {
LAB_60078858:
      FUN_600db36c(&local_b8,param_2,1);
      puVar13 = PTR_s_No_current_active_upload_60078944;
      goto LAB_60078566;
    }
    if (*pbVar14 != 0) {
      FUN_600db36c(&local_b8,param_2,1);
      puVar13 = PTR_s_An_error_occurred_during_data_wr_60078948;
      goto LAB_60078566;
    }
    http_flash_writer__6007991c(pbVar14 + 0xc);
    iVar10 = *(int *)(pbVar14 + 0xa8);
    local_b8 = *(undefined4 **)(pbVar14 + 0xac);
    puVar18 = (undefined1 *)((int)local_b8 + iVar10);
    local_d0 = local_c8;
    if ((iVar10 == 0) && (puVar18 != (undefined1 *)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_60101fd2(PTR_s_basic_string__M_construct_null_n_6007894c);
    }
    if (&DAT_0000000f < local_b8) {
      local_d0 = (undefined4 **)FUN_60078170(&local_b8);
      local_c8[0] = local_b8;
    }
    FUN_600db3ea(local_d0,iVar10,puVar18);
    local_cc = local_b8;
    *(undefined1 *)((int)local_d0 + (int)local_b8) = 0;
    *(undefined4 *)(param_2 + 8) = 8;
    if ((undefined4 *)0x80 < local_b8) {
      FUN_600ce2a0(&local_b8,PTR_s_CHECK_failed_60122ce9_9_60078950,
                   PTR_s_firmware_image_upload_cc_60078908,0x12f);
      FUN_60101740(&local_b8);
    }
    puVar9 = local_cc;
    *(undefined1 *)(param_2 + 0x10) = 1;
    thunk_EXT_FUN_0000b572(param_2 + 0x18,local_d0,local_cc);
    *(undefined4 **)(param_2 + 0x14) = puVar9;
    pbVar14[1] = 1;
    if (local_d0 != local_c8) {
      thunk_EXT_FUN_0000b52a();
    }
    break;
  case 5:
    if (pbVar14 == (byte *)0x0) goto LAB_60078858;
    if (pbVar14[1] == 0) {
      FUN_600db36c(&local_b8,param_2,1);
      puVar13 = PTR_s_Current_upload_did_not_end__60078a90;
      goto LAB_60078566;
    }
    local_d0 = (undefined4 **)CONCAT31(local_d0._1_3_,pbVar14[8]);
    uVar12 = FUN_600653f0();
    piVar11 = (int *)binary_build_metadata__600678ec(uVar12,(uint)local_d0 & 0xff);
    if (piVar11 == (int *)0x0) {
      uVar12 = 0x3f;
      puVar13 = PTR_s_Failed_to_get_build_meta_data_60078a94;
    }
    else if (*piVar11 == DAT_60078aa0) {
      if (piVar11[0x3f] == DAT_60078aa8) {
        uVar8 = partition_table__6007818c(uVar12,(uint)local_d0 & 0xff);
        puVar9 = (undefined4 *)FUN_600d4752(uVar8,4);
        if (puVar9 == (undefined4 *)0x0) {
          FUN_600ce2a0(&local_b8,PTR_s_CHECK_failed_60122ce9_9_60078ab0,
                       PTR_s_firmware_image_upload_cc_60078a98,0x56);
          FUN_60101740(&local_b8);
        }
        if (((uint)puVar9 & 0x1ff) == 4) {
          local_b8 = (undefined4 *)*puVar9;
          iVar10 = partition_table__60061684(uVar12,&local_b8,&local_d0);
          if (iVar10 != 0) {
            if (pbVar14[8] == 1) {
              uVar12 = 5;
            }
            else {
              uVar12 = 6;
            }
            *(undefined4 *)(DAT_60078abc + 0x38) = uVar12;
            uVar12 = FUN_6005a010();
            thunk_FUN_60059eb8(1,0,uVar12);
            if (pbVar14[8] == 1) {
              uVar12 = 1;
            }
            else {
              uVar12 = 2;
            }
            FUN_6005f120(uVar12);
            FUN_601016a2(PTR_s_firmware_image_upload_cc_60078a98,0x11e,DAT_60078ac0);
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar12 = 100;
          puVar13 = PTR_s_Partition_vector_table_reset_add_60078ab8;
        }
        else {
          uVar12 = 0x5b;
          puVar13 = PTR_s_Vector_table_address_does_not_lo_60078ab4;
        }
      }
      else {
        uVar12 = 0x48;
        puVar13 = PTR_s_Invalid_footer_magic_in_build_me_60078aac;
      }
    }
    else {
      uVar12 = 0x44;
      puVar13 = DAT_60078aa4;
    }
    FUN_6010165c(0x28,PTR_s_firmware_image_upload_cc_60078a98,uVar12,puVar13);
    FUN_600db36c(&local_b8,param_2,1);
    FUN_600db3a2(&local_b8,PTR_s_Invalid_image_flashed__60078a9c);
    FUN_600db394(&local_b8);
    FUN_600db3b6(pbVar14);
    break;
  default:
    FUN_600db36c(&local_b8,param_2,1);
    piVar11 = (int *)FUN_600db3a2(&local_b8,DAT_60078ac4);
    *(undefined1 *)(*piVar11 + 0x18) = 1;
    uVar12 = FUN_60050c18(*(undefined1 *)(param_1 + 0x11),0,piVar11[3] + piVar11[1],
                          piVar11[2] - piVar11[3]);
    FUN_60101ba2(piVar11 + 1,uVar12);
LAB_6007856c:
    FUN_600db394(&local_b8);
  }
  uVar12 = 2;
LAB_600783fc:
  thunk_EXT_FUN_00001680(&local_d4);
  return uVar12;
}


