// 6005da44  types__6005da44  size=108 bytes
// src: types.h
// --- callers ---
//   600810bc types__600810bc
//   60080e60 types__60080e60
// --- callees ---
//   60050c18 FUN_60050c18
//   600d3b3a FUN_600d3b3a
//   60101ba2 FUN_60101ba2
//   60101740 FUN_60101740
//   600d37ac FUN_600d37ac


/* src: types.h */

void types__6005da44(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *local_a0;
  undefined4 local_9c;
  int local_98;
  int local_94;
  int iStack_90;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    iVar2 = iVar2 + 1;
  }
  iVar4 = 0;
  if (*(int *)(param_1 + 0x28) != 0) {
    iVar4 = *(int *)(param_1 + 0x28) * 2 + 1;
  }
  uVar3 = (uint)*(byte *)(param_1 + 0x4b);
  if (uVar3 != 0) {
    uVar3 = uVar3 + 2;
  }
  uVar3 = (uint)*(byte *)(param_1 + 0x6b) + iVar2 + iVar4 + uVar3;
  if (0x1f < uVar3) {
    local_a0 = PTR_s_types_h_6005dab0;
    local_9c = 0x1c0;
    FUN_600d3b3a(&local_98);
    FUN_600d37ac(&local_98,PTR_s_Advertising_data_must_be_<__31_b_6005dab4);
    uVar1 = FUN_60050c18(uVar3,0,iStack_90 + local_98,local_94 - iStack_90);
    FUN_60101ba2(&local_98,uVar1);
    FUN_600d37ac(&local_98,PTR_s_bytes_6005dab8);
    FUN_60101740(&local_a0);
  }
  return;
}


