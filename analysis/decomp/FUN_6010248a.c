// 6010248a  FUN_6010248a  size=26 bytes
// --- callers ---
//   6005a1b0 device_info__6005a1b0
//   600d4664 FUN_600d4664
//   60091ddc FUN_60091ddc
// --- callees ---


char * FUN_6010248a(char *param_1,char param_2)

{
  char *pcVar1;
  
  do {
    pcVar1 = param_1;
    if (*pcVar1 == '\0') {
      if (param_2 == '\0') {
        return pcVar1;
      }
      return (char *)0x0;
    }
    param_1 = pcVar1 + 1;
  } while (*pcVar1 != param_2);
  return pcVar1;
}


