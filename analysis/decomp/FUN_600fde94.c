// 600fde94  FUN_600fde94  size=256 bytes
// --- callers ---
//   600fd6d6 FUN_600fd6d6
// --- callees ---
//   600c65b0 FUN_600c65b0
//   600efcc6 FUN_600efcc6
//   600ef3cc FUN_600ef3cc
//   600f3da6 FUN_600f3da6
//   60095c84 FUN_60095c84


void FUN_600fde94(undefined2 *param_1,short *param_2)

{
  undefined1 local_2c0 [2];
  undefined2 local_2be;
  undefined1 local_2bc;
  undefined1 auStack_2bb [7];
  short local_2b4;
  int local_10;
  code *local_c;
  
  local_c = (code *)**(undefined4 **)(param_1 + 6);
  local_10 = *(int *)(param_1 + 6);
  local_2bc = *(undefined1 *)(*(int *)(param_1 + 6) + 5);
  local_2be = *param_1;
  if (*param_2 == 0x1d08) {
    local_2b4 = 0x16;
  }
  else {
    local_2b4 = param_2[9];
  }
  local_2c0[0] = *(undefined1 *)((int)param_1 + 0x1d);
  FUN_600efcc6(auStack_2bb,param_1 + 1);
  if (*(char *)(param_1 + 4) == '\x01') {
    FUN_60095c84(0x1d,0xff,param_1 + 1);
  }
  FUN_600ef3cc(param_1);
  if (*param_2 == 0x1d08) {
    local_2c0[0] = FUN_600f3da6(param_2[3]);
  }
  if (local_c != (code *)0x0) {
    (*local_c)(5,local_2c0);
  }
  if ((*(char *)(local_10 + 6) == '\0') && (*(char *)(local_10 + 7) != '\0')) {
    FUN_600c65b0(local_10);
  }
  return;
}


