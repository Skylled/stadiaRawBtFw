// 60079668  http_flash_writer__60079668  size=242 bytes
// src: http_flash_writer.cc
// --- callers ---
//   6007991c http_flash_writer__6007991c
// --- callees ---
//   600d37ac FUN_600d37ac
//   60101c5c thunk_EXT_FUN_0000b52a
//   600db6f2 FUN_600db6f2
//   600d3b24 FUN_600d3b24
//   600ce31c FUN_600ce31c
//   60101c52 thunk_EXT_FUN_0000b532
//   600ebf7c FUN_600ebf7c
//   60079618 FUN_60079618
//   6008ee14 FUN_6008ee14
//   600ec016 FUN_600ec016


/* src: http_flash_writer.cc */

undefined4 http_flash_writer__60079668(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined1 auStack_120 [4];
  undefined1 auStack_11c [32];
  undefined1 auStack_fc [68];
  undefined *local_b8;
  undefined4 local_b4;
  undefined1 *local_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2 [130];
  
  iVar8 = param_2[4];
  uVar6 = *(int *)(*(int *)(*param_2 + 4) + 4) * param_2[1];
  local_b8 = PTR_s_http_flash_writer_cc_60079760;
  local_b4 = 0xbd;
  local_b0 = local_a2;
  local_ac = 0x80;
  uStack_a8 = 0;
  local_a4 = 0;
  local_a3 = 0;
  local_a2[0] = 0;
  FUN_600d37ac(&local_b0,PTR_s_Validating_6007975c);
  FUN_600db6f2(&local_b0,iVar8);
  FUN_600d37ac(&local_b0,PTR_s_bytes_starting_at_60079764);
  FUN_600db6f2(&local_b0,uVar6);
  FUN_600d3b24(&local_b8);
  iVar2 = FUN_6008ee14(&local_b8);
  if (iVar2 == 0) {
    FUN_60079618(param_1,PTR_s_SHA256_INIT_FAILED_60079768,auStack_fc);
  }
  else {
    uVar9 = iVar8 + uVar6;
    uVar3 = thunk_EXT_FUN_0000b532(0x400);
    do {
      if (uVar9 <= uVar6) {
        iVar2 = FUN_600ec016(auStack_11c,&local_b8);
        puVar5 = auStack_fc;
        puVar4 = PTR_s_SHA256_FINAL_FAILED_60079774;
        if (iVar2 != 0) {
          FUN_600ce31c(auStack_11c,0x20,puVar5);
          puVar4 = auStack_fc;
          puVar5 = auStack_120;
        }
        goto LAB_60079718;
      }
      uVar7 = uVar9 - uVar6;
      if (0x3ff < uVar7) {
        uVar7 = 0x400;
      }
      cVar1 = (**(code **)(*(int *)*param_2 + 4))((int *)*param_2,uVar3,uVar6,uVar7);
      if (cVar1 != '\0') {
        puVar4 = PTR_s_FLASH_READ_FAILED_6007976c;
        puVar5 = auStack_fc;
        goto LAB_60079718;
      }
      uVar6 = uVar6 + uVar7;
      iVar2 = FUN_600ebf7c(&local_b8,uVar3,uVar7);
    } while (iVar2 != 0);
    puVar4 = PTR_s_SHA256_UPDATE_FAILED_60079770;
    puVar5 = auStack_fc;
LAB_60079718:
    FUN_60079618(param_1,puVar4,puVar5);
    thunk_EXT_FUN_0000b52a(uVar3);
  }
  return param_1;
}


