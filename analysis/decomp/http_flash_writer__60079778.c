// 60079778  http_flash_writer__60079778  size=394 bytes
// src: http_flash_writer.cc
// --- callers ---
//   60078340 firmware_image_upload__60078340
// --- callees ---
//   600d37ac FUN_600d37ac
//   6013cf40 thunk_EXT_FUN_00007d10
//   600d37b8 FUN_600d37b8
//   600db6f2 FUN_600db6f2
//   600d3b24 FUN_600d3b24
//   600db800 FUN_600db800
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6010165c FUN_6010165c
//   600cbb14 FUN_600cbb14
//   60101b76 FUN_60101b76
//   6008ee14 FUN_6008ee14


/* src: http_flash_writer.cc */

void http_flash_writer__60079778(int *param_1)

{
  bool bVar1;
  undefined *puVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  char local_c4 [3];
  char local_c1;
  undefined *local_c0;
  undefined4 local_bc;
  undefined1 *local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa [134];
  
  puVar2 = PTR_s_http_flash_writer_cc_60079910;
  iVar7 = 0;
  thunk_EXT_FUN_0000b4c2(param_1 + 0x2d);
  param_1[4] = 0;
  puVar10 = (uint *)(param_1 + 3);
  uVar8 = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  thunk_EXT_FUN_00007d10(param_1 + 0x2d);
  DataMemoryBarrier(0x1b);
  param_1[3] = 0;
  DataMemoryBarrier(0x1b);
  local_bc = 0x1f;
  local_b8 = local_aa;
  local_c0 = puVar2;
  local_ac = 0;
  local_ab = 0;
  local_aa[0] = 0;
  local_b4 = 0x80;
  uStack_b0 = 0;
  FUN_600d37ac(&local_b8,PTR_s_Erasing_60079904);
  FUN_600db6f2(&local_b8,param_1[2]);
  FUN_600d37ac(&local_b8,PTR_s_sectors_starting_at_60079908);
  FUN_600db6f2(&local_b8,param_1[1]);
  FUN_600d3b24(&local_c0);
  iVar9 = *(int *)(*(int *)(*param_1 + 4) + 4);
  do {
    if ((uint)param_1[2] <= uVar8) {
LAB_60079896:
      *(undefined1 *)(param_1 + 0x42) = 0;
      (*(code *)param_1[0x43])(param_1[0x44]);
      FUN_6008ee14(param_1 + 0xb);
      FUN_600db800(param_1 + 0x27,PTR_s__6011b41a_0xc_60079918);
      return;
    }
    iVar6 = param_1[1];
    local_c1 = '\0';
    cVar3 = (**(code **)(*(int *)*param_1 + 0xc))((int *)*param_1,iVar7 + iVar6,iVar9,&local_c1);
    if ((cVar3 == '\0') && (local_c1 != '\0')) {
      cVar3 = '\0';
    }
    else {
      cVar3 = (*(code *)**(undefined4 **)*param_1)((undefined4 *)*param_1,iVar7 + iVar6,1);
    }
    if ((char)param_1[0x42] != '\0') {
      FUN_6010165c(0x14,PTR_s_http_flash_writer_cc_60079910,0x2c,
                   PTR_s_Erase_cancelled_at_index__lu_6007990c,uVar8);
      if (cVar3 != '\0') {
LAB_60079854:
        local_c0 = puVar2;
        local_bc = 0x30;
        local_b8 = local_aa;
        local_b4 = 0x80;
        uStack_b0 = 0;
        local_ac = 0;
        local_ab = 0;
        local_aa[0] = 0;
        FUN_600d37ac(&local_b8,PTR_s_Error_while_erasing_flash__60079914);
        local_c4[0] = cVar3;
        uVar4 = FUN_600cbb14(local_c4);
        FUN_60101b76(&local_b8,uVar4);
        FUN_600d37b8(&local_c0);
      }
      goto LAB_60079896;
    }
    if (cVar3 != '\0') goto LAB_60079854;
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(puVar10);
      uVar5 = *puVar10 + 1;
      bVar1 = (bool)hasExclusiveAccess(puVar10);
    } while (!bVar1);
    *puVar10 = uVar5;
    DataMemoryBarrier(0x1b);
    if (uVar5 == (uVar5 / 100) * 100) {
      (*(code *)param_1[0x43])(param_1[0x44]);
    }
    uVar8 = uVar8 + 1;
    iVar7 = iVar7 + iVar9;
  } while( true );
}


