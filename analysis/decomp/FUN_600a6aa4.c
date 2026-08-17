// 600a6aa4  FUN_600a6aa4  size=116 bytes
// --- callers ---
//   600f230a FUN_600f230a
// --- callees ---
//   6009feb8 FUN_6009feb8


void FUN_600a6aa4(undefined2 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 local_14;
  undefined2 local_10;
  int local_c;
  
  local_c = FUN_6009feb8(param_1);
  local_14 = *DAT_600a6b18;
  local_10 = (undefined2)DAT_600a6b18[1];
  if (*(int *)(DAT_600a6b1c + 0x1aac) != 0) {
    if (local_c == 0) {
      (**(code **)(DAT_600a6b1c + 0x1aac))(&local_14,param_2,param_3);
    }
    else {
      (**(code **)(DAT_600a6b1c + 0x1aac))(local_c + 0x10,param_2,param_3);
    }
  }
  return;
}


