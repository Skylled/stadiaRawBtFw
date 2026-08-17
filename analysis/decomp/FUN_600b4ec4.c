// 600b4ec4  FUN_600b4ec4  size=12 bytes
// --- callers ---
//   600f3bde FUN_600f3bde
// --- callees ---


undefined4 FUN_600b4ec4(undefined2 param_1,undefined2 param_2,char param_3)

{
  int iVar1;
  char *pcVar2;
  
  if (param_3 == '\0') {
    iVar1 = FUN_600bcc30(0,param_1);
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = *(char **)(iVar1 + 300);
    if (((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) || (pcVar2[1] != '\x04')) {
      return 0;
    }
    *(undefined2 *)(pcVar2 + 0x14) = param_2;
  }
  else {
    *(undefined2 *)(DAT_600b4f30 + 0xea0) = param_2;
  }
  return 1;
}


