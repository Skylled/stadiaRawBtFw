// 600f6b96  FUN_600f6b96  size=80 bytes
// --- callers ---
//   600ae7f8 FUN_600ae7f8
//   600ad4f4 FUN_600ad4f4
//   600aeb14 FUN_600aeb14
//   600f633e FUN_600f633e
//   600af0b4 FUN_600af0b4
// --- callees ---
//   600afd28 FUN_600afd28


void FUN_600f6b96(undefined2 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_600afd28((char)param_1);
  if (((iVar1 != 0) && (*(char *)(iVar1 + 0x2d) != '\0')) && (*(int *)(iVar1 + 0x24) != 0)) {
    (**(code **)(iVar1 + 0x24))(param_1,param_2,param_3,param_4);
  }
  return;
}


