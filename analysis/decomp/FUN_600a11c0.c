// 600a11c0  FUN_600a11c0  size=80 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600aa3cc FUN_600aa3cc


void FUN_600a11c0(char *param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(DAT_600a1210 + 0x738);
  FUN_600aa3cc(DAT_600a1214);
  *(undefined4 *)(DAT_600a1210 + 0x738) = 0;
  if (pcVar1 != (code *)0x0) {
    if (*param_1 == '\0') {
      (*pcVar1)(param_1 + 1);
    }
    else {
      (*pcVar1)(0);
    }
  }
  return;
}


