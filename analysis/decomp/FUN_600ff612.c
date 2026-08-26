// 600ff612  FUN_600ff612  size=96 bytes
// --- callers ---
// --- callees ---
//   600f3e00 FUN_600f3e00
//   60095b2c FUN_60095b2c


void FUN_600ff612(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  undefined2 local_24;
  undefined1 local_22;
  undefined1 uStack_e;
  undefined1 local_d;
  int local_c;
  
  iVar1 = FUN_600f3e00(param_1,&local_d,&local_24,&uStack_e);
  if (iVar1 != 0) {
    local_c = FUN_60095b2c(local_d);
    if ((local_c != 0) && (*(int *)(local_c + 0x18) != 0)) {
      local_24 = param_1;
      local_22 = param_2;
      (**(code **)(local_c + 0x18))(0x14,&local_24);
    }
  }
  return;
}


