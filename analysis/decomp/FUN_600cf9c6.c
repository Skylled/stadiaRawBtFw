// 600cf9c6  FUN_600cf9c6  size=92 bytes
// --- callers ---
//   60060634 sai__60060634
// --- callees ---
//   6013d2b8 thunk_EXT_FUN_0000851a
//   600ced08 FUN_600ced08


void FUN_600cf9c6(int param_1,undefined4 *param_2)

{
  byte bVar1;
  
  FUN_600ced08(*param_2);
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfff0ffff;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffe3fffe;
  thunk_EXT_FUN_0000851a(param_1,0);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x3000000;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfeffffff;
  bVar1 = *(byte *)((int)param_2 + 0xe5);
  param_2[(uint)bVar1 * 2 + 0x2d] = 0;
  param_2[(uint)bVar1 * 2 + 0x2e] = 0;
  *(byte *)((int)param_2 + 0xe5) = *(char *)((int)param_2 + 0xe5) + 1U & 3;
  param_2[2] = 1;
  return;
}


