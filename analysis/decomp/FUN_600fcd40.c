// 600fcd40  FUN_600fcd40  size=86 bytes
// --- callers ---
//   600fce8c FUN_600fce8c
//   600fc7ca FUN_600fc7ca
//   600fc758 FUN_600fc758
// --- callees ---
//   600f05da FUN_600f05da


void FUN_600fcd40(undefined1 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_1c [8];
  undefined1 *local_14;
  
  auStack_1c[7] = 0;
  local_14 = param_1;
  FUN_600f05da(param_2 + 0x1d,auStack_1c,auStack_1c + 7);
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    *local_14 = auStack_1c[5 - iVar1];
    local_14 = local_14 + 1;
  }
  *local_14 = auStack_1c[7];
  return;
}


