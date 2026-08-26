// 600feb2e  FUN_600feb2e  size=122 bytes
// --- callers ---
//   600feba8 FUN_600feba8
// --- callees ---
//   600efcc6 FUN_600efcc6
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600feb2e(undefined2 *param_1,char param_2,int param_3,undefined2 *param_4)

{
  *(bool *)(param_4 + 0x157) = param_2 != '\a';
  param_4[0x2a] = *(undefined2 *)(param_3 + 6);
  FUN_600efcc6(param_4 + 1,param_1 + 1);
  thunk_EXT_FUN_0000b572(param_4 + 0x2b,param_3 + 9,*(undefined2 *)(param_3 + 6));
  *param_4 = *param_1;
  if (**(int **)(param_1 + 6) != 0) {
    (*(code *)**(undefined4 **)(param_1 + 6))(10,param_4);
  }
  return;
}


