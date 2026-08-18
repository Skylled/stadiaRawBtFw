// 600d1ffa  FUN_600d1ffa  size=36 bytes
// --- callers ---
// --- callees ---
//   600d3386 FUN_600d3386


void FUN_600d1ffa(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (*(code **)(param_1 + 0x28) != (code *)0x0) {
    (**(code **)(param_1 + 0x28))
              (*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_2 + 4),
               *(undefined4 *)(param_2 + 0xc),param_3);
  }
  FUN_600d3386(*(undefined4 *)(param_1 + 4),param_2);
  return;
}


