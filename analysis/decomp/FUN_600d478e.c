// 600d478e  FUN_600d478e  size=38 bytes
// --- callers ---
//   6005f610 FUN_6005f610
// --- callees ---


undefined4 FUN_600d478e(undefined4 param_1,uint param_2,int param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_3 * 4 + 0x400ec000);
  *puVar1 = *puVar1 & 0xffffff80 | param_2 & 0x7f;
  *puVar1 = *puVar1 | 0x80000000;
  return 0;
}


