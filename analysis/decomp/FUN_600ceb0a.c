// 600ceb0a  FUN_600ceb0a  size=112 bytes
// --- callers ---
// --- callees ---


void FUN_600ceb0a(int param_1,int param_2,undefined4 *param_3)

{
  param_1 = param_1 + param_2 * 0x20;
  *(undefined4 *)(param_1 + 0x1000) = *param_3;
  *(undefined2 *)(param_1 + 0x1004) = *(undefined2 *)(param_3 + 1);
  *(undefined2 *)(param_1 + 0x1006) = *(undefined2 *)((int)param_3 + 6);
  *(undefined4 *)(param_1 + 0x1008) = param_3[2];
  *(undefined4 *)(param_1 + 0x100c) = param_3[3];
  *(undefined4 *)(param_1 + 0x1010) = param_3[4];
  *(undefined2 *)(param_1 + 0x1014) = *(undefined2 *)(param_3 + 5);
  *(undefined2 *)(param_1 + 0x1016) = *(undefined2 *)((int)param_3 + 0x16);
  *(undefined4 *)(param_1 + 0x1018) = param_3[6];
  *(undefined2 *)(param_1 + 0x101c) = 0;
  *(undefined2 *)(param_1 + 0x101c) = *(undefined2 *)(param_3 + 7);
  *(undefined2 *)(param_1 + 0x101e) = *(undefined2 *)((int)param_3 + 0x1e);
  return;
}


