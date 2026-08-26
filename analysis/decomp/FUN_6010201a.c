// 6010201a  FUN_6010201a  size=128 bytes
// --- callers ---
//   60101fe4 FUN_60101fe4
// --- callees ---
//   600cca30 FUN_600cca30
//   600cc9e4 FUN_600cc9e4


int FUN_6010201a(char *param_1,int param_2,char *param_3,int *param_4)

{
  int iVar1;
  char extraout_r2;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = param_1 + param_2 + -1;
  pcVar4 = param_1;
LAB_60102028:
  cVar2 = '\0';
  if (*param_3 == '\0') {
LAB_60102092:
    *pcVar4 = cVar2;
    return (int)pcVar4 - (int)param_1;
  }
  if (pcVar5 <= pcVar4) {
LAB_6010208a:
    FUN_600cc9e4(param_1,pcVar4);
    cVar2 = extraout_r2;
    goto LAB_60102092;
  }
  if (*param_3 == '%') {
    cVar2 = param_3[1];
    if (cVar2 == 's') {
      pcVar3 = (char *)(*param_4 + -1);
      while( true ) {
        pcVar3 = pcVar3 + 1;
        if (*pcVar3 == '\0') break;
        if (pcVar4 == pcVar5) goto LAB_6010208a;
        *pcVar4 = *pcVar3;
        pcVar4 = pcVar4 + 1;
      }
      param_3 = param_3 + 2;
      param_4 = param_4 + 1;
      goto LAB_60102028;
    }
    if (cVar2 != 'z') {
      if (cVar2 == '%') {
        param_3 = param_3 + 1;
      }
      goto LAB_60102044;
    }
    if (param_3[2] == 'u') {
      iVar1 = FUN_600cca30(pcVar4,(int)pcVar5 - (int)pcVar4,*param_4);
      if (iVar1 < 1) goto LAB_6010208a;
      pcVar4 = pcVar4 + iVar1;
      param_3 = param_3 + 3;
      param_4 = param_4 + 1;
      goto LAB_60102028;
    }
  }
LAB_60102044:
  *pcVar4 = *param_3;
  param_3 = param_3 + 1;
  pcVar4 = pcVar4 + 1;
  goto LAB_60102028;
}


