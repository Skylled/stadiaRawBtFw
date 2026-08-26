// 60101e12  FUN_60101e12  size=436 bytes
// --- callers ---
//   600dae1c FUN_600dae1c
// --- callees ---
//   60101ca2 FUN_60101ca2
//   60101c78 FUN_60101c78


char * FUN_60101e12(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 *puVar6;
  char *pcVar7;
  int iVar8;
  
  pcVar3 = *(char **)(param_1 + 8);
  pcVar4 = *(char **)(param_1 + 0xc);
  pcVar7 = pcVar4;
  if ((pcVar3 != (char *)0x0) && (pcVar2 = pcVar4, pcVar7 = pcVar3, pcVar4 != (char *)0x0)) {
    do {
      pcVar5 = pcVar2;
      pcVar2 = *(char **)(pcVar5 + 8);
    } while (*(char **)(pcVar5 + 8) != (char *)0x0);
    pcVar7 = *(char **)(pcVar5 + 0xc);
    if (pcVar5 != param_1) {
      *(char **)(pcVar3 + 4) = pcVar5;
      *(char **)(pcVar5 + 8) = pcVar3;
      pcVar3 = pcVar5;
      if (pcVar4 != pcVar5) {
        pcVar3 = *(char **)(pcVar5 + 4);
        if (pcVar7 != (char *)0x0) {
          *(char **)(pcVar7 + 4) = pcVar3;
        }
        *(char **)(*(int *)(pcVar5 + 4) + 8) = pcVar7;
        *(char **)(pcVar5 + 0xc) = pcVar4;
        *(char **)(*(int *)(param_1 + 0xc) + 4) = pcVar5;
      }
      if (*(char **)(param_2 + 4) == param_1) {
        *(char **)(param_2 + 4) = pcVar5;
      }
      else {
        iVar8 = *(int *)(param_1 + 4);
        if (*(char **)(iVar8 + 8) == param_1) {
          *(char **)(iVar8 + 8) = pcVar5;
        }
        else {
          *(char **)(iVar8 + 0xc) = pcVar5;
        }
      }
      *(undefined4 *)(pcVar5 + 4) = *(undefined4 *)(param_1 + 4);
      cVar1 = *pcVar5;
      *pcVar5 = *param_1;
      *param_1 = cVar1;
      goto LAB_60101e60;
    }
  }
  pcVar3 = *(char **)(param_1 + 4);
  if (pcVar7 != (char *)0x0) {
    *(char **)(pcVar7 + 4) = pcVar3;
  }
  if (*(char **)(param_2 + 4) == param_1) {
    *(char **)(param_2 + 4) = pcVar7;
  }
  else {
    iVar8 = *(int *)(param_1 + 4);
    if (*(char **)(iVar8 + 8) == param_1) {
      *(char **)(iVar8 + 8) = pcVar7;
    }
    else {
      *(char **)(iVar8 + 0xc) = pcVar7;
    }
  }
  if (*(char **)(param_2 + 8) == param_1) {
    pcVar4 = pcVar7;
    if (*(int *)(param_1 + 0xc) == 0) {
      pcVar2 = *(char **)(param_1 + 4);
    }
    else {
      do {
        pcVar2 = pcVar4;
        pcVar4 = *(char **)(pcVar2 + 8);
      } while (*(char **)(pcVar2 + 8) != (char *)0x0);
    }
    *(char **)(param_2 + 8) = pcVar2;
  }
  if (*(char **)(param_2 + 0xc) == param_1) {
    pcVar4 = pcVar7;
    if (*(int *)(param_1 + 8) == 0) {
      pcVar2 = *(char **)(param_1 + 4);
    }
    else {
      do {
        pcVar2 = pcVar4;
        pcVar4 = *(char **)(pcVar2 + 0xc);
      } while (*(char **)(pcVar2 + 0xc) != (char *)0x0);
    }
    *(char **)(param_2 + 0xc) = pcVar2;
  }
LAB_60101e60:
  if (*param_1 != '\0') {
    iVar8 = param_2 + 4;
    while (pcVar4 = pcVar3, pcVar3 = *(char **)(param_2 + 4), *(char **)(param_2 + 4) != pcVar7) {
      if ((pcVar7 != (char *)0x0) && (*pcVar7 != '\x01')) goto LAB_60101fc0;
      pcVar2 = *(char **)(pcVar4 + 8);
      pcVar3 = pcVar7;
      if (pcVar2 == pcVar7) {
        pcVar2 = *(char **)(pcVar4 + 0xc);
        if (*pcVar2 == '\0') {
          *pcVar2 = '\x01';
          *pcVar4 = '\0';
          FUN_60101c78(pcVar4,iVar8);
          pcVar2 = *(char **)(pcVar4 + 0xc);
        }
        pcVar7 = *(char **)(pcVar2 + 8);
        pcVar5 = *(char **)(pcVar2 + 0xc);
        if (((pcVar7 != (char *)0x0) && (*pcVar7 != '\x01')) ||
           ((pcVar5 != (char *)0x0 && (*pcVar5 != '\x01')))) {
          if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\x01')) {
            *pcVar7 = '\x01';
            *pcVar2 = '\0';
            FUN_60101ca2(pcVar2,iVar8);
            pcVar2 = *(char **)(pcVar4 + 0xc);
          }
          *pcVar2 = *pcVar4;
          puVar6 = *(undefined1 **)(pcVar2 + 0xc);
          *pcVar4 = '\x01';
          if (puVar6 != (undefined1 *)0x0) {
            *puVar6 = 1;
          }
          FUN_60101c78(pcVar4,iVar8);
          break;
        }
      }
      else {
        if (*pcVar2 == '\0') {
          *pcVar2 = '\x01';
          *pcVar4 = '\0';
          FUN_60101ca2(pcVar4,iVar8);
          pcVar2 = *(char **)(pcVar4 + 8);
        }
        pcVar5 = *(char **)(pcVar2 + 8);
        pcVar7 = *(char **)(pcVar2 + 0xc);
        if (((pcVar7 != (char *)0x0) && (*pcVar7 != '\x01')) ||
           ((pcVar5 != (char *)0x0 && (*pcVar5 != '\x01')))) {
          if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\x01')) {
            *pcVar7 = '\x01';
            *pcVar2 = '\0';
            FUN_60101c78(pcVar2,iVar8);
            pcVar2 = *(char **)(pcVar4 + 8);
          }
          *pcVar2 = *pcVar4;
          puVar6 = *(undefined1 **)(pcVar2 + 8);
          *pcVar4 = '\x01';
          if (puVar6 != (undefined1 *)0x0) {
            *puVar6 = 1;
          }
          FUN_60101ca2(pcVar4,iVar8);
          break;
        }
      }
      pcVar3 = *(char **)(pcVar4 + 4);
      *pcVar2 = '\0';
      pcVar7 = pcVar4;
    }
    pcVar7 = pcVar3;
    if (pcVar7 != (char *)0x0) {
LAB_60101fc0:
      *pcVar7 = '\x01';
    }
  }
  return param_1;
}


