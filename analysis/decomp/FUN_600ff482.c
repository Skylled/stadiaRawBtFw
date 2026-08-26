// 600ff482  FUN_600ff482  size=92 bytes
// --- callers ---
//   600959cc FUN_600959cc
// --- callees ---
//   600f3ed6 FUN_600f3ed6
//   60095b2c FUN_60095b2c


void FUN_600ff482(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 local_d;
  int local_c;
  
  local_c = FUN_60095b2c(*(undefined1 *)(param_2 + 0xc));
  local_d = 0;
  if (local_c != 0) {
    iVar1 = FUN_600f3ed6(*(undefined1 *)(param_2 + 0xc),*(undefined1 *)(param_2 + 0xd),
                         *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 8),param_2,param_1);
    if (iVar1 == 0) {
      local_d = 0x85;
    }
    if (*(int *)(local_c + 0x18) != 0) {
      (**(code **)(local_c + 0x18))(0x13,&local_d);
    }
  }
  return;
}


