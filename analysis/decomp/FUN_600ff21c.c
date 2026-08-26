// 600ff21c  FUN_600ff21c  size=254 bytes
// --- callers ---
//   600959cc FUN_600959cc
// --- callees ---
//   600f367e FUN_600f367e
//   600efaf6 FUN_600efaf6
//   600f37d2 FUN_600f37d2
//   60095d4c FUN_60095d4c
//   600f3e00 FUN_600f3e00
//   600f3c42 FUN_600f3c42
//   60095b2c FUN_60095b2c
//   60095cd4 FUN_60095cd4


void FUN_600ff21c(undefined4 param_1,int param_2)

{
  int iVar1;
  char local_31;
  undefined2 local_30;
  char local_2e;
  undefined1 auStack_1c [7];
  undefined1 local_15;
  int local_14;
  char local_d;
  int local_c;
  
  local_c = 0;
  local_d = -0x79;
  local_14 = FUN_600efaf6(param_1,*(undefined2 *)(param_2 + 8));
  if (local_14 != 0) {
    iVar1 = FUN_600f3e00(*(undefined2 *)(param_2 + 6),&local_15,auStack_1c,&local_31);
    if (iVar1 != 0) {
      local_c = FUN_60095b2c(local_15);
      FUN_600f3c42(local_15,auStack_1c,1,local_31);
      if (*(char *)(param_2 + 0xc) == '\0') {
        local_d = FUN_600f37d2(*(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8),
                               *(undefined2 *)(param_2 + 10),param_2 + 0xd);
      }
      else {
        local_d = FUN_600f367e(*(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8),
                               *(undefined2 *)(param_2 + 10),param_2 + 0xd);
      }
      if (local_31 == '\x01') {
        FUN_60095d4c(0x1e,0xff,auStack_1c);
        FUN_60095cd4(0x1e,0xff,auStack_1c);
      }
    }
    if ((((local_d != '\0') || (*(char *)(param_2 + 0xc) == '\0')) && (local_c != 0)) &&
       (*(int *)(local_c + 0x18) != 0)) {
      local_2e = local_d;
      local_30 = *(undefined2 *)(param_2 + 6);
      (**(code **)(local_c + 0x18))(5,&local_30);
    }
  }
  return;
}


