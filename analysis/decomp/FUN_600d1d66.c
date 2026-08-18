// 600d1d66  FUN_600d1d66  size=36 bytes
// --- callers ---
// --- callees ---
//   600d3386 FUN_600d3386


void FUN_600d1d66(undefined4 *param_1,int param_2,undefined4 param_3)

{
  param_1[0xc] = 0;
  if ((code *)param_1[10] != (code *)0x0) {
    (*(code *)param_1[10])
              (param_1[0xb],*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 0xc),param_3);
  }
  FUN_600d3386(*param_1,param_2);
  return;
}


