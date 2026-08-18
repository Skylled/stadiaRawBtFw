// 600ceba4  FUN_600ceba4  size=66 bytes
// --- callers ---
// --- callees ---


void FUN_600ceba4(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined2 uVar1;
  
  *param_1 = *param_2;
  param_1[4] = param_2[1];
  *(ushort *)((int)param_1 + 6) =
       *(byte *)((int)param_2 + 9) & 7 | (*(byte *)(param_2 + 2) & 7) << 8;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)((int)param_2 + 10);
  *(undefined2 *)(param_1 + 5) = *(undefined2 *)(param_2 + 3);
  param_1[2] = param_2[4];
  uVar1 = *(undefined2 *)(param_2 + 5);
  *(undefined2 *)((int)param_1 + 0x16) = uVar1;
  *(undefined2 *)((int)param_1 + 0x1e) = uVar1;
  if (param_3 != 0) {
    param_1[6] = param_3;
    *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) & 0xfff7 | 0x10;
  }
  return;
}


