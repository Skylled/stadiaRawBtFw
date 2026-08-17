// 600810bc  types__600810bc  size=190 bytes
// src: types.h
// --- callers ---
//   60081234 advertiser__60081234
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   60080fb8 FUN_60080fb8
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6004cb28 FUN_6004cb28
//   600d44f2 FUN_600d44f2
//   60080e60 types__60080e60
//   600d4550 FUN_600d4550
//   60101740 FUN_60101740
//   6005da44 types__6005da44
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d37ac FUN_600d37ac


/* src: types.h */

undefined4 types__600810bc(int param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  undefined1 *local_154;
  undefined4 local_150;
  undefined1 local_14c [16];
  undefined1 auStack_13c [140];
  undefined *local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [144];
  
  local_154 = local_14c;
  local_150 = 0;
  local_14c[0] = 0;
  FUN_60080fb8(&local_154);
  thunk_EXT_FUN_0000b5ba(auStack_13c,0,0x8c);
  FUN_600d44f2(auStack_13c);
  iVar1 = types__60080e60(auStack_13c,PTR_DAT_6008117c,1,0);
  puVar3 = local_154;
  iVar2 = FUN_6004cb28(local_154);
  if (0x1f < iVar2 + 1U) {
    local_b0 = PTR_s_types_h_60081180;
    local_ac = 0x146;
    FUN_600d3b3a(auStack_a8);
    FUN_600d37ac(auStack_a8,PTR_s_CHECK_failed_60122ce9_9_60081184);
    FUN_60101740(&local_b0);
  }
  puVar4 = puVar3 + iVar2;
  puVar6 = (undefined1 *)(iVar1 + 9);
  for (; puVar3 != puVar4; puVar3 = puVar3 + 1) {
    *puVar6 = *puVar3;
    puVar6 = puVar6 + 1;
  }
  *(int *)(iVar1 + 4) = iVar2;
  types__6005da44(iVar1);
  thunk_EXT_FUN_0000b572(param_2,iVar1,0x8c);
  param_2[0x8b] = 1;
  iVar1 = *(int *)(param_1 + 0x58);
  *param_2 = 1;
  if (iVar1 == 1) {
    uVar5 = 6;
  }
  else {
    uVar5 = 5;
  }
  param_2[1] = uVar5;
  FUN_600d4550(&local_154);
  return 0;
}


