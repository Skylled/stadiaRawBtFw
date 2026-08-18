// 600c527c  FUN_600c527c  size=76 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6


void FUN_600c527c(char *param_1)

{
  undefined1 auStack_14 [6];
  undefined1 local_e;
  char local_c;
  
  if (*param_1 == '\0') {
    FUN_600efcc6(auStack_14,param_1 + 3);
    local_e = 2;
    local_c = param_1[2];
    if (*(int *)(DAT_600c52c8 + 0xe8) != 0) {
      (**(code **)(DAT_600c52c8 + 0xe8))(7,auStack_14);
    }
  }
  return;
}


