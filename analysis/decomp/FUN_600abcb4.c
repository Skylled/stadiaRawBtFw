// 600abcb4  FUN_600abcb4  size=118 bytes
// --- callers ---
//   600f3f70 FUN_600f3f70
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined1 FUN_600abcb4(undefined4 param_1,short *param_2,int param_3)

{
  undefined1 local_9;
  
  if ((char)param_2[2] != '\0') {
    *(short *)(param_3 + 4) = param_2[1];
  }
  *(short *)(param_3 + 2) = *param_2;
  if (*(short *)(DAT_600abd2c + 0x1550) == *param_2) {
    local_9 = 2;
  }
  else if (*param_2 == *DAT_600abd30) {
    *(undefined2 *)(param_3 + 6) = 2;
    thunk_EXT_FUN_0000b572(param_3 + 9,DAT_600abd34,2);
    local_9 = 0;
  }
  else {
    local_9 = 10;
  }
  return local_9;
}


