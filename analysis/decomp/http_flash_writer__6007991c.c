// 6007991c  http_flash_writer__6007991c  size=262 bytes
// src: http_flash_writer.cc
// --- callers ---
//   60078340 firmware_image_upload__60078340
// --- callees ---
//   600d3b80 FUN_600d3b80
//   6013d168 thunk_EXT_FUN_0000b554
//   600ce31c FUN_600ce31c
//   600db714 FUN_600db714
//   6007952c http_flash_writer__6007952c
//   600db800 FUN_600db800
//   60079668 http_flash_writer__60079668
//   600794f8 FUN_600794f8
//   600d4550 FUN_600d4550
//   6005d714 trigger_bug_report__6005d714
//   6010165c FUN_6010165c
//   600ec016 FUN_600ec016


/* src: http_flash_writer.cc */

void http_flash_writer__6007991c(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint local_80;
  undefined1 auStack_7c [32];
  undefined4 local_5c;
  uint local_58;
  
  if (*(char *)(param_1 + 0x108) == '\0') {
    if ((*(int *)(param_1 + 0x24) != 0) &&
       (cVar1 = http_flash_writer__6007952c(param_1,param_1 + 0x14), cVar1 == '\0')) {
      FUN_600db714(param_1);
    }
    iVar2 = FUN_600ec016(auStack_7c,param_1 + 0x2c);
    if (iVar2 == 0) {
      FUN_6010165c(0x28,PTR_s_http_flash_writer_cc_60079a24,0x57,
                   PTR_s_Unable_to_calculate_hash_of_writ_60079a30);
      puVar4 = (undefined4 *)PTR_s__6011b41a_0xc_60079a34;
    }
    else {
      FUN_600ce31c(auStack_7c,0x20,&local_5c);
      puVar4 = &local_5c;
    }
    FUN_600db800(param_1 + 0x9c,puVar4);
    http_flash_writer__60079668(&local_5c,param_1);
    if ((local_58 == *(uint *)(param_1 + 0xa0)) &&
       ((local_58 == 0 ||
        (iVar2 = thunk_EXT_FUN_0000b554(local_5c,*(undefined4 *)(param_1 + 0x9c)), iVar2 == 0)))) {
      FUN_6010165c(0x14,PTR_s_http_flash_writer_cc_60079a24,100,
                   PTR_s_Verified_on_disk_data__60079a38);
    }
    else {
      FUN_6010165c(0x28,PTR_s_http_flash_writer_cc_60079a24,0x5f,
                   PTR_s_On_disk_hash__s_different_from___60079a28,local_5c,
                   *(undefined4 *)(param_1 + 0x9c));
      trigger_bug_report__6005d714(PTR_s_ON_DISK_OTA_HASH_MISMATCH_60079a2c,0);
      if (*(int *)(param_1 + 0x9c) == param_1 + 0xa4) {
        uVar5 = 0xf;
      }
      else {
        uVar5 = *(uint *)(param_1 + 0xa4);
      }
      if (uVar5 < local_58) {
        local_80 = local_58;
        uVar3 = FUN_600794f8(&local_80);
        FUN_600d4550(param_1 + 0x9c);
        *(undefined4 *)(param_1 + 0x9c) = uVar3;
        *(uint *)(param_1 + 0xa4) = local_80;
      }
      if (local_58 != 0) {
        FUN_600d3b80(*(undefined4 *)(param_1 + 0x9c),local_5c,local_58);
      }
      *(uint *)(param_1 + 0xa0) = local_58;
      *(undefined1 *)(*(int *)(param_1 + 0x9c) + local_58) = 0;
    }
    FUN_600d4550(&local_5c);
  }
  else {
    *(undefined1 *)(param_1 + 0x108) = 0;
  }
  return;
}


