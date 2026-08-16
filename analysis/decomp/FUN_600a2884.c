// 600a2884  FUN_600a2884  size=280 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a29a0 FUN_600a29a0
//   600a27fc FUN_600a27fc
//   600a2f3c FUN_600a2f3c


void FUN_600a2884(char *param_1)

{
  int iVar1;
  char local_12;
  char local_11;
  code *local_10;
  int local_c;
  
  iVar1 = DAT_600a299c;
  local_c = DAT_600a299c;
  local_10 = *(code **)(DAT_600a299c + 0x3c);
  if (*(char *)(DAT_600a299c + 0x61b) == '\0') {
    if (*(char *)(DAT_600a299c + 0x61a) == '\x01') {
      local_11 = *param_1;
      if (local_11 == '\0') {
        local_12 = '\0';
      }
      else {
        local_12 = '\n';
      }
      if (*(char *)(DAT_600a299c + 0x61d) == '\0') {
        *(undefined1 *)(DAT_600a299c + 0x61a) = 0;
        if (local_10 != (code *)0x0) {
          (*local_10)(&local_12);
        }
      }
      else if (local_12 == '\0') {
        if (*(char *)(DAT_600a299c + 0x61d) == '\x01') {
          local_12 = FUN_600a27fc(*(undefined1 *)(DAT_600a299c + 0x60c),DAT_600a299c + 0x60d);
          if (local_12 == '\x01') {
            *(undefined1 *)(local_c + 0x61d) = 2;
          }
          else {
            *(undefined1 *)(local_c + 0x61a) = 0;
            FUN_600a2f3c(10,*(byte *)(local_c + 0x608) & 3);
          }
        }
        else {
          *(undefined1 *)(DAT_600a299c + 0x61d) = 3;
          *(undefined1 *)(iVar1 + 0x61a) = 0;
          FUN_600a29a0(iVar1);
        }
      }
      else {
        FUN_600a2f3c(10,*(byte *)(DAT_600a299c + 0x608) & 3);
        *(undefined1 *)(local_c + 0x61a) = 0;
        *(undefined1 *)(local_c + 0x61e) = 0;
        *(undefined1 *)(local_c + 0x61d) = 0;
      }
    }
  }
  else {
    *(char *)(DAT_600a299c + 0x61b) = *(char *)(DAT_600a299c + 0x61b) + -1;
  }
  return;
}


