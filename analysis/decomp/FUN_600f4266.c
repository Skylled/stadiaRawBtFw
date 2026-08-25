// 600f4266  FUN_600f4266  size=114 bytes
// --- callers ---
//   600ac438 FUN_600ac438
//   600ac128 FUN_600ac128
// --- callees ---
//   600d9306 FUN_600d9306
//   600b00b4 FUN_600b00b4
//   600f42d8 FUN_600f42d8
//   600f45a6 FUN_600f45a6
//   600f43c0 FUN_600f43c0


void FUN_600f4266(char param_1,undefined4 *param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = FUN_600d9306(*param_2);
  if (iVar1 != 0) {
    FUN_600f42d8(*param_2,0);
  }
  if (param_1 == '\0') {
    FUN_600b00b4(param_2,0x89,0);
  }
  else if (*(char *)((int)param_2 + 0x31) == '\x03') {
    FUN_600f45a6(param_2,param_3);
  }
  else if (*(char *)((int)param_2 + 0x31) == '\x02') {
    FUN_600f43c0(param_2,*(undefined2 *)(param_2 + 0xb));
  }
  return;
}


