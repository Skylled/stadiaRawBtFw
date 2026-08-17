// 600a32d4  FUN_600a32d4  size=96 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600aa3cc FUN_600aa3cc


void FUN_600a32d4(char *param_1)

{
  undefined1 local_10;
  char local_f;
  char local_e;
  code *local_c;
  
  local_c = *(code **)(DAT_600a3334 + 0x7a8);
  FUN_600aa3cc(DAT_600a3338);
  *(undefined4 *)(DAT_600a3334 + 0x7a8) = 0;
  if (local_c != (code *)0x0) {
    local_f = *param_1;
    if (local_f == '\0') {
      local_10 = 0;
      local_e = param_1[1];
    }
    else {
      local_10 = 10;
    }
    (*local_c)(&local_10);
  }
  return;
}


