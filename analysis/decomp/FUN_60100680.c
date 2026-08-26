// 60100680  FUN_60100680  size=306 bytes
// --- callers ---
//   601005ac FUN_601005ac
// --- callees ---
//   60100246 FUN_60100246


void FUN_60100680(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  FUN_60100246(param_1,param_4);
  for (local_14 = 0; local_14 < param_4; local_14 = local_14 + 1) {
    local_1c = 0;
    for (local_18 = 0; local_18 < param_4; local_18 = local_18 + 1) {
      uVar1 = local_1c + *(int *)(local_18 * 4 + param_3) * *(int *)(local_14 * 4 + param_2);
      uVar2 = *(int *)((local_18 + local_14) * 4 + param_1) + uVar1;
      local_1c = (int)((ulonglong)*(uint *)(local_14 * 4 + param_2) *
                       (ulonglong)*(uint *)(local_18 * 4 + param_3) >> 0x20) +
                 (uint)(uVar1 < local_1c) +
                 (uint)(uVar2 < *(uint *)((local_18 + local_14) * 4 + param_1));
      *(uint *)((local_18 + local_14) * 4 + param_1) = uVar2;
    }
    *(uint *)((param_4 + local_14) * 4 + param_1) = local_1c;
  }
  return;
}


