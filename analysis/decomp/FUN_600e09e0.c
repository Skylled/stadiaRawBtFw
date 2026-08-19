// 600e09e0  FUN_600e09e0  size=48 bytes
// --- callers ---
//   600e0a14 FUN_600e0a14
//   60086b98 FUN_60086b98
//   60091ab4 FUN_60091ab4
// --- callees ---
//   6004cb28 FUN_6004cb28


char * FUN_600e09e0(char *param_1,char *param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  for (; 1 < param_3; param_3 = param_3 - 1) {
    if (*param_2 == '\0') goto LAB_600e09f4;
    *pcVar2 = *param_2;
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + 1;
  }
  if (param_3 != 0) {
LAB_600e09f4:
    *pcVar2 = '\0';
  }
  iVar1 = FUN_6004cb28(param_2);
  return pcVar2 + (iVar1 - (int)param_1);
}


