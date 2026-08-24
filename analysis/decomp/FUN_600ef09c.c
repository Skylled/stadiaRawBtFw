// 600ef09c  FUN_600ef09c  size=88 bytes
// --- callers ---
//   600ef0f4 FUN_600ef0f4
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600ef09c(int param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4,
                 undefined1 param_5)

{
  undefined1 in_stack_00000018;
  undefined1 in_stack_0000001c;
  
  *(undefined2 *)(param_1 + 0x14) = param_3;
  *(undefined2 *)(param_1 + 0x16) = param_4;
  *(undefined1 *)(param_1 + 0x18) = param_2;
  *(undefined1 *)(param_1 + 0x1b) = in_stack_0000001c;
  *(undefined1 *)(param_1 + 0x19) = param_5;
  *(undefined1 *)(param_1 + 0x1a) = in_stack_00000018;
  thunk_EXT_FUN_0000b572(param_1,&stack0x00000004,0x14);
  return;
}


