// 60101d4e  FUN_60101d4e  size=196 bytes
// --- callers ---
//   600641a8 usb_host_audio_topology__600641a8
//   600daf3a FUN_600daf3a
//   60063e24 usb_host_audio_topology__60063e24
//   600daf9e FUN_600daf9e
//   600d6750 FUN_600d6750
//   600d6256 FUN_600d6256
// --- callees ---
//   60101ca2 FUN_60101ca2
//   60101c78 FUN_60101c78


void FUN_60101d4e(int param_1,char *param_2,int param_3,int param_4)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = param_4 + 4;
  *(int *)(param_2 + 4) = param_3;
  param_2[8] = '\0';
  param_2[9] = '\0';
  param_2[10] = '\0';
  param_2[0xb] = '\0';
  param_2[0xc] = '\0';
  param_2[0xd] = '\0';
  param_2[0xe] = '\0';
  param_2[0xf] = '\0';
  *param_2 = '\0';
  if (param_1 == 0) {
    *(char **)(param_3 + 0xc) = param_2;
    if (*(int *)(param_4 + 0xc) != param_3) goto LAB_60101d78;
  }
  else {
    *(char **)(param_3 + 8) = param_2;
    if (param_4 != param_3) {
      if (*(int *)(param_4 + 8) == param_3) {
        *(char **)(param_4 + 8) = param_2;
      }
      goto LAB_60101d78;
    }
    *(char **)(param_4 + 4) = param_2;
  }
  *(char **)(param_4 + 0xc) = param_2;
LAB_60101d78:
  do {
    while( true ) {
      if ((*(char **)(param_4 + 4) == param_2) ||
         (pcVar3 = *(char **)(param_2 + 4), *pcVar3 != '\0')) {
        **(char **)(param_4 + 4) = '\x01';
        return;
      }
      pcVar2 = *(char **)(pcVar3 + 4);
      pcVar1 = *(char **)(pcVar2 + 8);
      if (pcVar3 != pcVar1) break;
      pcVar1 = *(char **)(pcVar2 + 0xc);
      if ((pcVar1 == (char *)0x0) || (*pcVar1 != '\0')) {
        if (*(char **)(pcVar3 + 0xc) == param_2) {
          FUN_60101c78(pcVar3,iVar4);
          param_2 = pcVar3;
        }
        **(undefined1 **)(param_2 + 4) = 1;
        *pcVar2 = '\0';
        FUN_60101ca2(pcVar2,iVar4);
      }
      else {
LAB_60101d96:
        *pcVar3 = '\x01';
        *pcVar1 = '\x01';
        *pcVar2 = '\0';
        param_2 = pcVar2;
      }
    }
    if ((pcVar1 != (char *)0x0) && (*pcVar1 == '\0')) goto LAB_60101d96;
    if (*(char **)(pcVar3 + 8) == param_2) {
      FUN_60101ca2(pcVar3,iVar4);
      param_2 = pcVar3;
    }
    **(undefined1 **)(param_2 + 4) = 1;
    *pcVar2 = '\0';
    FUN_60101c78(pcVar2,iVar4);
  } while( true );
}


