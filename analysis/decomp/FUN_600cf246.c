// 600cf246  FUN_600cf246  size=32 bytes
// --- callers ---
//   6006eb00 FUN_6006eb00
//   6006e9b0 FUN_6006e9b0
// --- callees ---
//   600538b4 FUN_600538b4


void FUN_600cf246(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x2d) == '\x02') {
    FUN_600538b4(param_1,0x8200000);
  }
  *(undefined2 *)(param_2 + 0x20) = 0;
  *(undefined2 *)(param_2 + 0x22) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return;
}


