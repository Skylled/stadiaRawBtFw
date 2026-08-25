// 600fd8c4  FUN_600fd8c4  size=172 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
// --- callees ---
//   60094d24 FUN_60094d24
//   600fdbb8 FUN_600fdbb8
//   60094f58 FUN_60094f58
//   60094ffc FUN_60094ffc


void FUN_600fd8c4(undefined4 param_1,undefined2 *param_2)

{
  undefined1 local_2c4 [688];
  int *local_14;
  int local_10;
  undefined2 local_a;
  
  local_a = *param_2;
  local_10 = 0;
  if (*(char *)((int)param_2 + 0xf) == '\0') {
    FUN_600fdbb8(param_2);
  }
  else {
    local_10 = FUN_60094ffc(*(undefined1 *)(param_2 + 7),param_2 + 4,2);
    if (local_10 == 0) {
      local_14 = (int *)FUN_60094f58(*(undefined1 *)(param_2 + 7));
      if ((local_14 != (int *)0x0) && (*local_14 != 0)) {
        local_2c4[0] = 0x85;
        (*(code *)*local_14)(0xe,local_2c4);
      }
    }
    else {
      FUN_60094d24(local_10,local_a,param_2);
    }
  }
  return;
}


