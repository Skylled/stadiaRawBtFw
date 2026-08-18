// 600c39c0  FUN_600c39c0  size=100 bytes
// --- callers ---
// --- callees ---
//   60096314 FUN_60096314
//   600c3e84 FUN_600c3e84


void FUN_600c39c0(int param_1)

{
  if ((DAT_600c3a24[2] == 0) || ((DAT_600c3a24[2] != 0 && (*(int *)(param_1 + 0x108) != 0)))) {
    (*(code *)*DAT_600c3a24)(2,param_1 + 8);
  }
  if (*(char *)(DAT_600c3a24 + 0x4f) == '\0') {
    FUN_600c3e84();
  }
  else {
    *(undefined1 *)((int)DAT_600c3a24 + 0x13d) = 1;
    DAT_600c3a24[0x49] = DAT_600c3a28;
    FUN_60096314(DAT_600c3a2c,0,4000);
  }
  return;
}


