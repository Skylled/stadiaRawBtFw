// 6007952c  http_flash_writer__6007952c  size=218 bytes
// src: http_flash_writer.cc
// --- callers ---
//   6007991c http_flash_writer__6007991c
//   600db730 FUN_600db730
// --- callees ---
//   600d37ac FUN_600d37ac
//   6013cf40 thunk_EXT_FUN_00007d10
//   600d37b8 FUN_600d37b8
//   600db6f2 FUN_600db6f2
//   600ebf7c FUN_600ebf7c
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600cbb14 FUN_600cbb14
//   60101b76 FUN_60101b76


/* src: http_flash_writer.cc */

uint http_flash_writer__6007952c(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_bc [4];
  undefined *local_b8;
  undefined4 local_b4;
  undefined1 *puStack_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2 [134];
  
  piVar1 = (int *)*param_1;
  iVar4 = param_1[1] * *(int *)(piVar1[1] + 4) + param_1[4];
  uVar2 = (**(code **)(*piVar1 + 8))(piVar1,iVar4,param_2,param_3);
  if ((uVar2 & 0xff) == 0) {
    iVar4 = param_1[4];
    thunk_EXT_FUN_0000b4c2(param_1 + 0x2d);
    param_1[4] = param_3 + iVar4;
    thunk_EXT_FUN_00007d10(param_1 + 0x2d);
    FUN_600ebf7c(param_1 + 0xb,param_2,param_3);
  }
  else {
    puStack_b0 = local_a2;
    local_b8 = PTR_s_http_flash_writer_cc_60079608;
    if ((uVar2 & 0xff) == 3) {
      local_b4 = 0x6f;
      local_ac = 0x80;
      uStack_a8 = 0;
      local_a4 = 0;
      local_a3 = 0;
      local_a2[0] = 0;
      FUN_600d37ac(&puStack_b0,PTR_s_Not_enough_space__writing_6007960c);
      FUN_600db6f2(&puStack_b0,param_3);
      FUN_600d37ac(&puStack_b0,PTR_s_bytes_to_address_60079610);
      FUN_600db6f2(&puStack_b0,iVar4);
    }
    else {
      local_b4 = 0x72;
      local_a4 = 0;
      local_a3 = 0;
      local_a2[0] = 0;
      local_ac = 0x80;
      uStack_a8 = 0;
      FUN_600d37ac(&puStack_b0,PTR_s_Error_while_writing_to_flash__60079614);
      local_bc[0] = (undefined1)uVar2;
      uVar3 = FUN_600cbb14(local_bc);
      FUN_60101b76(&puStack_b0,uVar3);
    }
    FUN_600d37b8(&local_b8);
  }
  return uVar2;
}


