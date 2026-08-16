// 600b05f0  FUN_600b05f0  size=290 bytes
// --- callers ---
//   600ab9b8 FUN_600ab9b8
// --- callees ---
//   600f139a FUN_600f139a
//   600afd28 FUN_600afd28
//   6009ca80 FUN_6009ca80


void FUN_600b05f0(char param_1)

{
  int iVar1;
  byte local_f;
  byte local_e;
  byte local_d;
  char *local_c;
  
  local_c = DAT_600b0714;
  iVar1 = FUN_600afd28(param_1);
  for (local_d = 0; local_d < 3; local_d = local_d + 1) {
    if (local_c[0x1a] != '\0') {
      local_e = 0;
      while ((local_e < 10 && ((local_c[local_e] != '\0' || (local_c[local_e + 10] != '\0'))))) {
        local_f = local_e;
        if (param_1 == local_c[local_e]) {
          while (local_f = local_f + 1, local_f < 10) {
            local_c[local_f - 1] = local_c[local_f];
          }
          if (*local_c == '\0') {
            FUN_6009ca80(0,local_c + 0x14);
          }
        }
        if (param_1 == local_c[local_e + 10]) {
          local_c[local_e + 10] = '\0';
          local_f = local_e;
          if ((iVar1 != 0) && (*(char *)(iVar1 + 0x2e) != '\0')) {
            *(char *)(iVar1 + 0x2e) = *(char *)(iVar1 + 0x2e) + -1;
          }
          while (local_f = local_f + 1, local_f < 10) {
            local_c[local_f + 9] = local_c[local_f + 10];
          }
          if (local_c[10] == '\0') {
            FUN_600f139a(0,local_c + 0x14);
          }
        }
        local_e = local_e + 1;
      }
    }
    local_c = local_c + 0x1b;
  }
  return;
}


