// 600d1746  FUN_600d1746  size=40 bytes
// --- callers ---
// --- callees ---
//   600d3386 FUN_600d3386


void FUN_600d1746(undefined4 *param_1,int param_2,undefined4 param_3)

{
  param_1[0x17] = 0;
  if ((code *)param_1[0x15] != (code *)0x0) {
    (*(code *)param_1[0x15])
              (param_1[0x16],*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 0xc),param_3);
  }
  FUN_600d3386(*param_1,param_2);
  *(undefined1 *)(param_1 + 0x19) = 0;
  return;
}


