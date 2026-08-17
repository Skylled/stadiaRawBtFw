// 6009c790  FUN_6009c790  size=52 bytes
// --- callers ---
//   600b59ec FUN_600b59ec
//   600f0e6e FUN_600f0e6e
//   600b54d4 FUN_600b54d4
//   600b56aa FUN_600b56aa
//   6009b368 FUN_6009b368
//   6009c444 FUN_6009c444
// --- callees ---
//   6009ebd8 FUN_6009ebd8
//   6009ec14 FUN_6009ec14


void FUN_6009c790(char param_1)

{
  *(char *)(DAT_6009c7c4 + 0xa30) = param_1;
  if ((param_1 == '\x02') || (param_1 == '\x01')) {
    FUN_6009ebd8(2);
  }
  else {
    FUN_6009ec14(2);
  }
  return;
}


