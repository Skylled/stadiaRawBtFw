// 60101d4a  thunk_FUN_60101ccc  size=4 bytes
// --- callers ---
//   600641a8 usb_host_audio_topology__600641a8
//   60063e24 usb_host_audio_topology__60063e24
//   600daeea FUN_600daeea
//   600d6750 FUN_600d6750
//   600d6256 FUN_600d6256
// --- callees ---


char * thunk_FUN_60101ccc(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((*param_1 == '\0') && (*(char **)(*(int *)(param_1 + 4) + 4) == param_1)) {
    pcVar2 = *(char **)(*(char **)(*(int *)(param_1 + 4) + 4) + 0xc);
  }
  else {
    pcVar1 = *(char **)(param_1 + 8);
    if (*(char **)(param_1 + 8) == (char *)0x0) {
      for (pcVar2 = *(char **)(param_1 + 4); *(char **)(pcVar2 + 8) == param_1;
          pcVar2 = *(char **)(pcVar2 + 4)) {
        param_1 = pcVar2;
      }
    }
    else {
      do {
        pcVar2 = pcVar1;
        pcVar1 = *(char **)(pcVar2 + 0xc);
      } while (*(char **)(pcVar2 + 0xc) != (char *)0x0);
    }
  }
  return pcVar2;
}


