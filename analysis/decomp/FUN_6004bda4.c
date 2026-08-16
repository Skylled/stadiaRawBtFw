// 6004bda4  FUN_6004bda4  size=50 bytes
// --- callers ---
//   60049d4a FUN_60049d4a
//   6004a4e6 FUN_6004a4e6
//   600461bc FUN_600461bc
//   6004b06e FUN_6004b06e
//   60045e4c FUN_60045e4c
//   600466cc FUN_600466cc
//   60049b20 FUN_60049b20
//   60044440 FUN_60044440
//   60045b40 FUN_60045b40
// --- callees ---


void FUN_6004bda4(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_2 + param_3;
  if ((param_2 < param_1) && (param_1 < puVar1)) {
    param_1 = param_1 + param_3;
    param_3 = param_3 - (int)puVar1;
    while (puVar1 + param_3 != (undefined1 *)0x0) {
      puVar1 = puVar1 + -1;
      param_1 = param_1 + -1;
      *param_1 = *puVar1;
    }
  }
  else {
    param_1 = param_1 + -1;
    for (; param_2 != puVar1; param_2 = param_2 + 1) {
      param_1 = param_1 + 1;
      *param_1 = *param_2;
    }
  }
  return;
}


