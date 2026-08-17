// 600b4ec2  FUN_600b4ec2  size=2 bytes
// --- callers ---
//   60132bb4 FUN_60132bb4
// --- callees ---


undefined4 FUN_600b4ec2(undefined2 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  char *pcVar2;
  
  *param_3 = param_2;
  if ((char)param_3 == '\0') {
    iVar1 = FUN_600bcc30(0,param_1);
    if (iVar1 == 0) {
      return 0;
    }
    pcVar2 = *(char **)(iVar1 + 300);
    if (((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) || (pcVar2[1] != '\x04')) {
      return 0;
    }
    *(short *)(pcVar2 + 0x14) = (short)param_2;
  }
  else {
    *(short *)(DAT_600b4f30 + 0xea0) = (short)param_2;
  }
  return 1;
}


