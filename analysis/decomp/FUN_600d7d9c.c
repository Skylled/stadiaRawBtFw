// 600d7d9c  FUN_600d7d9c  size=58 bytes
// --- callers ---
// --- callees ---
//   60067c3c gotham__60067c3c


int FUN_600d7d9c(undefined4 param_1,char *param_2,int param_3,undefined4 param_4)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar1 = param_2;
  while( true ) {
    pcVar3 = pcVar1;
    if ((int)(param_2 + (param_3 - (int)pcVar3)) < 1) goto LAB_600d7dc0;
    iVar2 = gotham__60067c3c(param_1,pcVar3,1,param_2 + (param_3 - (int)pcVar3),param_4);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (iVar2 == 0) break;
    if ((*pcVar3 == '\n') || (pcVar1 = pcVar3 + 1, *pcVar3 == '\r')) break;
  }
  *pcVar3 = '\0';
LAB_600d7dc0:
  return (int)pcVar3 - (int)param_2;
}


