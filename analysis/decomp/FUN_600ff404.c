// 600ff404  FUN_600ff404  size=126 bytes
// --- callers ---
//   600959cc FUN_600959cc
// --- callees ---
//   600f3e00 FUN_600f3e00
//   600f3da6 FUN_600f3da6
//   60095b2c FUN_60095b2c
//   60095c84 FUN_60095c84


void FUN_600ff404(undefined4 param_1,int param_2)

{
  int iVar1;
  char local_15;
  undefined1 auStack_14 [6];
  undefined1 local_e;
  undefined1 local_d;
  int local_c;
  
  local_d = 0x85;
  iVar1 = FUN_600f3e00(*(undefined2 *)(param_2 + 6),&local_e,auStack_14,&local_15,param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_600f3da6(*(undefined2 *)(param_2 + 6));
    if (iVar1 == 0) {
      local_d = 0;
    }
    local_c = FUN_60095b2c(local_e);
    if ((local_c != 0) && (*(int *)(local_c + 0x18) != 0)) {
      if (local_15 == '\x01') {
        FUN_60095c84(0x1e,0xff,auStack_14);
      }
      (**(code **)(local_c + 0x18))(0x12,&local_d);
    }
  }
  return;
}


