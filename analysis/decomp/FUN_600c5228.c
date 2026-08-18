// 600c5228  FUN_600c5228  size=78 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6


void FUN_600c5228(char *param_1)

{
  undefined1 auStack_14 [6];
  undefined1 local_e;
  char local_d;
  
  if (*param_1 == '\0') {
    FUN_600efcc6(auStack_14,param_1 + 3);
    local_e = 1;
    local_d = param_1[2];
    if (*(int *)(DAT_600c5278 + 0xe8) != 0) {
      (**(code **)(DAT_600c5278 + 0xe8))(7,auStack_14);
    }
  }
  return;
}


