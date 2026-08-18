// 600d178e  FUN_600d178e  size=32 bytes
// --- callers ---
// --- callees ---
//   600d3386 FUN_600d3386


void FUN_600d178e(undefined4 *param_1,int param_2,undefined4 param_3)

{
  if ((code *)param_1[0xe] != (code *)0x0) {
    (*(code *)param_1[0xe])
              (param_1[0xf],*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 0xc),param_3);
  }
  FUN_600d3386(*param_1,param_2);
  return;
}


