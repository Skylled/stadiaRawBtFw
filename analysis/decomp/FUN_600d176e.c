// 600d176e  FUN_600d176e  size=32 bytes
// --- callers ---
// --- callees ---
//   600d3386 FUN_600d3386


void FUN_600d176e(undefined4 *param_1,int param_2,undefined4 param_3)

{
  if ((code *)param_1[0xc] != (code *)0x0) {
    (*(code *)param_1[0xc])
              (param_1[0xd],*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 0xc),param_3);
  }
  FUN_600d3386(*param_1,param_2);
  return;
}


