// 60102502  FUN_60102502  size=52 bytes
// --- callers ---
//   600d4664 FUN_600d4664
// --- callees ---


char * FUN_60102502(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (*param_1 == '\0') {
    if (*param_2 != '\0') {
      param_1 = (char *)0x0;
    }
  }
  else {
    while (pcVar3 = param_1, *pcVar3 != '\0') {
      pcVar1 = param_2 + -1;
      pcVar2 = pcVar3 + -1;
      do {
        pcVar1 = pcVar1 + 1;
        if (*pcVar1 == '\0') {
          return pcVar3;
        }
        pcVar2 = pcVar2 + 1;
        param_1 = pcVar3 + 1;
      } while (*pcVar2 == *pcVar1);
    }
    param_1 = (char *)0x0;
  }
  return param_1;
}


