// 600d31cc  FUN_600d31cc  size=26 bytes
// --- callers ---
//   6005663c FUN_6005663c
// --- callees ---
//   600d3196 FUN_600d3196


void FUN_600d31cc(undefined4 param_1,int param_2,ushort *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x1c);
  *(ushort *)(iVar1 + 2) = *param_3 << 8 | *param_3 >> 8;
  *(ushort *)(iVar1 + 4) = (ushort)(byte)param_3[1];
  FUN_600d3196(param_1,param_2,*(undefined4 *)(param_3 + 2),param_3[4]);
  return;
}


