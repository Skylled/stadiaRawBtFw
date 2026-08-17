// 60080e60  types__60080e60  size=126 bytes
// src: types.h
// --- callers ---
//   600810bc types__600810bc
//   60080ee8 FUN_60080ee8
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   60101740 FUN_60101740
//   6005da44 types__6005da44
//   600d37ac FUN_600d37ac


/* src: types.h */

int types__60080e60(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [148];
  
  if (0x1f < param_3 * 2 + 1U) {
    local_b0 = DAT_60080ee0;
    local_ac = 0x1c7;
    FUN_600d3b3a(auStack_a8);
    FUN_600d37ac(auStack_a8,DAT_60080ee4);
    FUN_60101740(&local_b0);
  }
  if (param_4 == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 3;
  }
  piVar2 = param_2 + param_3 * 5;
  *(undefined1 *)(param_1 + 0x2c) = uVar3;
  uVar4 = 1;
  while ((param_2 != piVar2 && (uVar4 < 0x20))) {
    if (*param_2 == 0) {
      iVar1 = param_1 + uVar4;
      uVar4 = uVar4 + 2;
      *(char *)(iVar1 + 0x2c) = (char)(short)param_2[1];
      *(char *)(iVar1 + 0x2d) = (char)((ushort)(short)param_2[1] >> 8);
    }
    param_2 = param_2 + 5;
  }
  *(int *)(param_1 + 0x28) = param_3;
  types__6005da44(param_1);
  return param_1;
}


