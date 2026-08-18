// 600d1fda  FUN_600d1fda  size=32 bytes
// --- callers ---
// --- callees ---
//   600d3386 FUN_600d3386


void FUN_600d1fda(int param_1,int param_2,undefined4 param_3)

{
  if (*(code **)(param_1 + 0x20) != (code *)0x0) {
    (**(code **)(param_1 + 0x20))
              (*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 4),
               *(undefined4 *)(param_2 + 0xc),param_3);
  }
  FUN_600d3386(*(undefined4 *)(param_1 + 4),param_2);
  return;
}


