// 600cfa22  FUN_600cfa22  size=108 bytes
// --- callers ---
//   60060708 sai__60060708
// --- callees ---
//   600ced08 FUN_600ced08
//   600cf63e FUN_600cf63e


void FUN_600cfa22(int param_1,undefined4 *param_2)

{
  byte bVar1;
  
  FUN_600ced08(*param_2);
  *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfff0ffff;
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xffe3fffe;
  FUN_600cf63e(param_1,0);
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 0x3000000;
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xfeffffff;
  bVar1 = *(byte *)((int)param_2 + 0xe5);
  param_2[(uint)bVar1 * 2 + 0x2d] = 0;
  param_2[(uint)bVar1 * 2 + 0x2e] = 0;
  *(byte *)((int)param_2 + 0xe5) = *(char *)((int)param_2 + 0xe5) + 1U & 3;
  param_2[2] = 1;
  return;
}


