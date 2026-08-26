// 6004bc98  FUN_6004bc98  size=70 bytes
// --- callers ---
//   600482a8 FUN_600482a8
// --- callees ---
//   6004bc28 FUN_6004bc28
//   60047d3c tasks__60047d3c
//   60048580 FUN_60048580
//   600485c8 FUN_600485c8


void FUN_6004bc98(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_60048580();
  if (*(char *)(param_1 + 0x44) == -1) {
    *(undefined1 *)(param_1 + 0x44) = 0;
  }
  if (*(char *)(param_1 + 0x45) == -1) {
    *(undefined1 *)(param_1 + 0x45) = 0;
  }
  FUN_600485c8();
  if (*(int *)(param_1 + 0x38) == 0) {
    tasks__60047d3c(param_1 + 0x24,param_2,param_3);
  }
  FUN_6004bc28(param_1);
  return;
}


