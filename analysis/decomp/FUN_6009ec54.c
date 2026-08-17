// 6009ec54  FUN_6009ec54  size=168 bytes
// --- callers ---
//   600b8ba4 FUN_600b8ba4
//   600f7cea FUN_600f7cea
// --- callees ---
//   6009ec14 FUN_6009ec14
//   6009ebd8 FUN_6009ebd8


void FUN_6009ec54(byte param_1,char param_2)

{
  FUN_6009ec14(0xc);
  if (param_2 == '\0') {
    if (*(char *)((uint)param_1 + DAT_6009ecfc + 0xade) != '\0') {
      *(char *)((uint)param_1 + DAT_6009ecfc + 0xade) =
           *(char *)(DAT_6009ecfc + (uint)param_1 + 0xade) + -1;
    }
  }
  else {
    *(char *)((uint)param_1 + DAT_6009ecfc + 0xade) =
         *(char *)(DAT_6009ecfc + (uint)param_1 + 0xade) + '\x01';
  }
  if (*(char *)(DAT_6009ecfc + 0xade) != '\0') {
    FUN_6009ebd8(4);
  }
  if (*(char *)(DAT_6009ecfc + 0xadf) != '\0') {
    FUN_6009ebd8(8);
  }
  if ((param_1 == 1) && (param_2 != '\0')) {
    *(undefined1 *)(DAT_6009ecfc + 0x8e6) = 0;
    *(undefined1 *)(DAT_6009ecfc + 0x8ee) = 0;
    FUN_6009ec14(0x231);
  }
  return;
}


