// 600d34fa  FUN_600d34fa  size=58 bytes
// --- callers ---
// --- callees ---
//   600d34f6 thunk_FUN_60057ff0


void FUN_600d34fa(int param_1,int *param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_4; iVar1 = iVar1 + 1) {
    if (0x7f < *param_2 + 1U) {
      thunk_FUN_60057ff0(param_1);
      *param_2 = 0;
    }
    *(undefined1 *)(param_1 + *param_2) = param_3;
    *param_2 = *param_2 + 1;
  }
  return;
}


