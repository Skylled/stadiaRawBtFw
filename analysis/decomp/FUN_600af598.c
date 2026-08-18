// 600af598  FUN_600af598  size=114 bytes
// --- callers ---
//   600ab424 FUN_600ab424
// --- callees ---


void FUN_600af598(byte param_1,undefined4 param_2,undefined1 param_3)

{
  *(undefined1 *)((uint)param_1 * 0x10 + DAT_600af60c + 0xfbb) = 1;
  *(byte *)((uint)param_1 * 0x10 + DAT_600af60c + 0xfba) = param_1;
  *(undefined2 *)((uint)param_1 * 0x10 + DAT_600af60c + 0xfb8) =
       *(undefined2 *)((uint)param_1 * 0x28 + DAT_600af60c + 0xaa4);
  *(undefined1 *)((uint)param_1 * 0x10 + DAT_600af60c + 0xfbc) = param_3;
  return;
}


