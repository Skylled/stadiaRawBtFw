// 600d8920  FUN_600d8920  size=34 bytes
// --- callers ---
//   60081234 advertiser__60081234
// --- callees ---
//   600aad90 FUN_600aad90


void FUN_600d8920(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 local_10;
  undefined2 uStack_e;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(short *)(param_1 + 0x10a) = (short)param_2;
  _local_10 = CONCAT22((short)((uint)param_1 >> 0x10),(short)param_2);
  *(undefined1 *)(param_1 + 0x10c) = 1;
  uStack_c = param_2;
  uStack_8 = param_3;
  FUN_600aad90(0x2a01,&local_10);
  return;
}


